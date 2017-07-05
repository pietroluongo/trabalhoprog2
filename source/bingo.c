#include "../headers/bingo.h"

void RealizaJogo(tBingo* jogo, FILE** output, FILE** out_stats, FILE** out_extra)
{
    //Reinicia o gerador para o sorteio das pedras
    ReiniciaGerador(jogo->seed, jogo->qtdPedras);
    int pedra;
    int bingo = 0;
    tJogador vencedores[10];
    while(!bingo)
    {
        pedra = GeraProxNumero();
        fprintf(*output, "Pedra:%d\n", pedra);
        PrintaCartelasBingo(jogo->cartelas, jogo->jogadores, jogo->qJog, jogo->totalCartelas, *output);
        int i;
        for(i = 0; i < jogo->totalCartelas; i++)
        {
            if(ChecaCartelaBingo(&jogo->cartelas[i], pedra))
            {
                vencedores[bingo] = getOwnerByIdC(&jogo->cartelas[i], jogo->jogadores, jogo->qJog);
                bingo++;
            }
        }
    }
    PrintaCartelasBingo(jogo->cartelas, jogo->jogadores, jogo->qJog, jogo->totalCartelas, *output);
    if(bingo == 1)
    {
        fprintf(*output, "Jogador Venceu!\n%s\n", vencedores[0].nome);
    }
    else
    {
        fprintf(*output, "Jogadores Empataram!\n");
        int i;
        for(i = 0; i < bingo; i++)
        {
            fprintf(*output, "%s\n", vencedores[i].nome);
        }
    }
    ProcessStats(jogo, out_stats);
    ProcessBonus(jogo, out_extra);
}

void InitGame(tBingo* cfg, FILE* input, FILE* out_cart)
{
    fscanf(input, "%d;%d;%d;%d;%d", &cfg->seed, &cfg->qtdPedras, &cfg->lin,
                                    &cfg->col, &cfg->qJog);
    /*scanf("%d;", &cfg->seed);
    scanf("%d;", &cfg->qtdPedras);
    scanf("%d;", &cfg->lin);
    scanf("%d;", &cfg->col);
    scanf("%d", &cfg->qJog);*/
    
    //Lê o nome dos participantes e quantas cartelas cada um tem
    LeParticipantes(cfg->qJog, cfg->jogadores, &cfg->totalCartelas, input);
    
    //Monta as cartelas dos participantes
    MontaCartelasBingo(cfg->cartelas, cfg->jogadores, cfg->totalCartelas,
                       cfg->lin, cfg->col, cfg->qtdPedras);
    
    PrintaCartelasBingo(cfg->cartelas, cfg->jogadores, cfg->qJog, cfg->totalCartelas, out_cart);
}
void ProcessBonus(tBingo* jogo, FILE** out)
{
    int pedras[jogo->qJog];
    tJogador jogs[jogo->qJog];
    int i;
    for(i = 0; i < jogo->qJog; i++)
    {
        jogs[i] = jogo->jogadores[i];
        pedras[i] = getPiorCartelaQtd(jogo->cartelas, jogo->totalCartelas, jogo->qtdPedras, jogo->jogadores[i]);
    }
    for(i = 0; i < jogo->qJog; i++)
    {
        int j;
        for(j = 0; j < jogo->qJog; j++)
        {
            if(pedras[i] > pedras[j])
            {
                int aux1 = pedras[j];
                tJogador aux2 = jogs[j];
                pedras[j] = pedras[i];
                jogs[j] = jogs[i];
                jogs[i] = aux2;
                pedras[i] = aux1;
            }
        }
    }
    for(i = 0; i < jogo->qJog; i++)
    {
        int j;
        for(j = 0; j < jogo->qJog; j++)
        {
            if(pedras[i] == pedras[j])
            {
                if(DesempataNomesJogs(jogs[j], jogs[i]) == 2)
                {
                    int aux1 = pedras[j];
                    tJogador aux2 = jogs[j];
                    pedras[j] = pedras[i];
                    jogs[j] = jogs[i];
                    jogs[i] = aux2;
                    pedras[i] = aux1;
                }
            }
        }
    }
    for(i = 0; i < jogo->qJog; i++)
    {
        fprintf(*out, "%s (%d)\n", jogs[i].nome, pedras[i]);
    }
}

void ProcessStats(tBingo* jogo, FILE** out)
{
    int i, j;
    //Cart[acertos][id]
    int cart[jogo->totalCartelas][2];
    for(i = 0; i < jogo->totalCartelas; i++)
    {
        cart[i][0] = getHitsCBingo(jogo->cartelas[i]);
        cart[i][1] = GetIdC(&jogo->cartelas[i]);
    }
    //Primeira ordenação - Acertos - Decrescente
    for(i = 0; i < jogo->totalCartelas; i++)
    {
        for(j = 0; j < jogo->totalCartelas; j++)
        {
            if(cart[i][0] > cart[j][0])
            {
                int aux1, aux2;
                aux1 = cart[i][0];
                aux2 = cart[i][1];
                cart[i][0] = cart[j][0];
                cart[i][1] = cart[j][1];
                cart[j][0] = aux1;
                cart[j][1] = aux2;
            }
        }
    }//Segunda Ordenação - Nomes - Crescente
    for(i = 0; i < jogo->totalCartelas; i++)
    {
        for(j = 0; j < jogo->totalCartelas; j++)
        {
            if(cart[i][0] == cart[j][0])
            {
                if(DesempataNomes(jogo, cart[i][1], cart[j][1]) == 1)
                {
                    int aux1, aux2;
                    aux1 = cart[i][0];
                    aux2 = cart[i][1];
                    cart[i][0] = cart[j][0];
                    cart[i][1] = cart[j][1];
                    cart[j][0] = aux1;
                    cart[j][1] = aux2;
                }               
            }
        }
    }
    //Terceira ordenação - IDs - Crescente
    for(i = 0; i < jogo->totalCartelas; i++)
    {
        for(j = 0; j < jogo->totalCartelas; j++)
        {
            if(cart[i][0] == cart[j][0])
            {
                    tJogador jA = getOwnerById(cart[i][1], jogo->jogadores, jogo->qJog);
                    tJogador jB = getOwnerById(cart[j][1], jogo->jogadores, jogo->qJog);
                    if(jA.id == jB.id)
                    {
                        if(cart[i][1] < cart[j][1])
            {
                int aux1, aux2;
                aux1 = cart[i][0];
                aux2 = cart[i][1];
                cart[i][0] = cart[j][0];
                cart[i][1] = cart[j][1];
                cart[j][0] = aux1;
                cart[j][1] = aux2;
            }
                    }
            }
        }
    }
    for(i = 0; i < jogo->totalCartelas; i++)
    {
        fprintf(*out, "%d - %d - %s\n", cart[i][0], cart[i][1], getOwnerById(cart[i][1], jogo->jogadores, jogo->qJog).nome);
    }
}

int DesempataNomesJogs(tJogador jA, tJogador jB)
{
    if(jA.id == jB.id)
        return 0;
    int i;
    for(i = 0; i < 99; i++)
    {
        if(jA.nome[i] < jB.nome[i])
            return 1;
        else if(jA.nome[i] > jB.nome[i])
            return 2;
        else if(jA.nome[i] == jB.nome[i])
            continue;
    }
    return 0;
}

//Retorna 1 caso o idA tenha um nome "menor" e 2 caso o idB tenha um nome "menor"
int DesempataNomes(tBingo* jogo, int idA, int idB)
{
    char nomeA[99];
    char nomeB[99];
    tJogador jA = getOwnerById(idA, jogo->jogadores, jogo->qJog);
    tJogador jB = getOwnerById(idB, jogo->jogadores, jogo->qJog);
    if(jA.id == jB.id)
        return 0;
    int i;
    CopiaStr(jA.nome, nomeA);
    CopiaStr(jB.nome, nomeB);
    for(i = 0; i < 99; i++)
    {
        if(nomeA[i] < nomeB[i])
            return 1;
        else if(nomeA[i] > nomeB[i])
            return 2;
        else if(nomeA[i] == nomeB[i])
            continue;
    }
    return 0;
}