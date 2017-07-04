#include "../headers/bingo.h"

void RealizaJogo(tBingo* jogo)
{
    //Reinicia o gerador para o sorteio das pedras
    ReiniciaGerador(jogo->seed, jogo->qtdPedras);
    int pedra;
    int bingo = 0;
    tJogador vencedores[10];
    while(!bingo)
    {
        pedra = GeraProxNumero();
        printf("Pedra:%d\n", pedra);
        PrintaCartelasBingo(jogo->cartelas, jogo->jogadores, jogo->qJog, jogo->totalCartelas);
        int i;
        for(i = 0; i < jogo->totalCartelas; i++)
        {
            if(ChecaCartelaBingo(&jogo->cartelas[i], pedra))
            {
                vencedores[bingo] = getOwnerById(&jogo->cartelas[i], jogo->jogadores, jogo->qJog);
                bingo++;
            }
        }
    }
    PrintaCartelasBingo(jogo->cartelas, jogo->jogadores, jogo->qJog, jogo->totalCartelas);
    if(bingo == 1)
    {
        printf("Jogador Venceu!\n%s\n", vencedores[0].nome);
    }
    else
    {
        printf("Jogadores Empataram!\n");
        int i;
        for(i = 0; i < bingo; i++)
        {
            printf("%s\n", vencedores[i].nome);
        }
    }
}

void InitGame(/*FILE* input*/ tBingo* cfg)
{
    FILE* input_file;
    //fscanf(input, "%d;%d;%d;%d;%d", seed, qtdPedras, lin, col, qJog);
    scanf("%d;", &cfg->seed);
    scanf("%d;", &cfg->qtdPedras);
    scanf("%d;", &cfg->lin);
    scanf("%d;", &cfg->col);
    scanf("%d", &cfg->qJog);
    
    //Lê o nome dos participantes e quantas cartelas cada um tem
    LeParticipantes(cfg->qJog, cfg->jogadores, &cfg->totalCartelas);
    
    //Monta as cartelas dos participantes
    MontaCartelasBingo(cfg->cartelas, cfg->jogadores, cfg->totalCartelas,
                       cfg->lin, cfg->col, cfg->qtdPedras);
}