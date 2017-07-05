#include "../headers/tCartela.h"

tCartela InitCartelaBingo(int id, int lin, int col, int qtdPedras)
{
    int size = lin*col;
    ReiniciaGerador(id, qtdPedras);
    int nums[size];
    int i;
    for(i = 0; i < size; i++)
    {
        nums[i] = GeraProxNumero();
    }
    OrdenaVetor(nums, size);
    tCartela r;
    r.id = id;
    r.lin = lin;
    r.col = col;
    r.numerosMarcados = 0;
    memset(r.numeros, 0, sizeof r.numeros);
    int j, n = 0;
    for(i = 0; i < col; i++)
    {
        for(j = 0; j < lin; j++)
        {
            r.numeros[j][i] = nums[n];
            n++;
        }
    }
    return r;
}

int GetIdC(tCartela* cartela)
{
    return cartela->id;
}
int ChecaCartelaBingo(tCartela* cartela, int num)
{
    int i, j;
    for(i = 0; i <= cartela->col; i++)
    {
        for(j = 0; j <= cartela->lin; j++)
        {
            if(cartela->numeros[i][j] == num)
            {
                cartela->numerosMarcados++;
                cartela->numeros[i][j] = -1;
            }
        }
    }
    if(cartela->numerosMarcados == cartela->col * cartela->lin)
    {
        return 1;
        printf("\n BINGO \n");
    }
    return 0;
}

void PrintaCartelaBingo(tCartela* cartela, FILE* out)
{
    fprintf(out, "Cartela ID:%d\n", GetIdC(cartela));
    int i, j;
    for(i = 0; i < cartela->lin; i++)
    {
        int num = cartela->numeros[i][0];
        fprintf(out, "\t|");
        if(num > 0 && num < 10)
        {
            fprintf(out, "00");
            fprintf(out, "%d|", num);
        }
        else if(num >= 10 && num < 100)
        {
            fprintf(out, "0");
            fprintf(out, "%d|", num);
        }
        else if(num >= 100)
            fprintf(out, "%d|", num);
        else
            fprintf(out, "---|");
        for(j = 1; j < cartela->col; j++)
        {
            num = cartela->numeros[i][j];
            if(num > 0 && num < 10)
            {
                fprintf(out, "00");
                fprintf(out, "%d|", num);
            }
            else if(num >= 10 && num < 100)
            {
                fprintf(out, "0");
                fprintf(out, "%d|", num);
            }
            else if(num >= 100)
                fprintf(out, "%d|", num);
            else
                fprintf(out, "---|");
        }
        fprintf(out,"\n");
    }
}

int getHitsCBingo(tCartela cartela)
{
    return cartela.numerosMarcados;
}

void MontaCartelasBingo(tCartela* cartelas, tJogador* jogadores,
                        int totalCartelas, int lin, int col, int qPedras)
{
    int k = 0;
    int jogAtual = 0;
    int countAtual = 0;
    int i;
    for(i = 0; i < totalCartelas; i++)
    {
        tCartela c = InitCartelaBingo(k, lin, col, qPedras);
        cartelas[i] = c;
        if(countAtual < jogadores[jogAtual].qtdCartelas)
        {
            jogadores[jogAtual].cartelaIds[countAtual] = k;
            countAtual++;
        }
        else
        {
            jogAtual++;
            countAtual = 0;
            jogadores[jogAtual].cartelaIds[countAtual] = k;
            countAtual++;
        }
        k++;
        
    }
}

void GetCartelasDoJogador(tCartela* cartelasDoJogo, tCartela* destino, tJogador* jogador, int total)
{
    int i, j;
    int cur = 0;
    int qtdCartelasDoJogador = getQtdCartelasDoJogador(jogador);
    //Vetor com todas as ids de cartelas do jogador em questão
    int idsDoJogador[qtdCartelasDoJogador];
    getIdsCartelasDoJogador(jogador, idsDoJogador);
    for(i = 0; i < qtdCartelasDoJogador; i++)
    {
        for(j = 0; j < total; j++)
        {
            if(GetIdC(&cartelasDoJogo[j]) == idsDoJogador[i])
            {
                destino[cur] = cartelasDoJogo[j];
                cur++;
            }
        }
    }
}

void PrintaCartelasDoJogador(tCartela* cartelas, tJogador* jogador, int totalCartelas, FILE* out)
{
    fprintf(out, "Jogador:%s\n", jogador->nome);
    tCartela cartela [getQtdCartelasDoJogador(jogador)];
    
    GetCartelasDoJogador(cartelas, cartela, jogador, totalCartelas);
    int i;
    for(i = 0; i < getQtdCartelasDoJogador(jogador); i++)
    {
        PrintaCartelaBingo(&cartela[i], out);
        fprintf(out, "\n");
    }
}

void PrintaCartelasBingo(tCartela* cartelas, tJogador* jogadores, int qJog, int total, FILE* out)
{
    int i;
    for(i = 0; i < qJog; i++)
    {
        PrintaCartelasDoJogador(cartelas, &jogadores[i], total, out);
        fprintf(out, "\n");
    }
}

tJogador getOwnerByIdC(tCartela* cartela, tJogador* jogadores, int qJog)
{
    tJogador owner;
    int i;
    for(i = 0; i < qJog; i++)
    {
        int Ids[getQtdCartelasDoJogador(&jogadores[i])];
        getIdsCartelasDoJogador(&jogadores[i], Ids);
        int j;
        for(j = 0; j < getQtdCartelasDoJogador(&jogadores[i]); j++)
        {
            if(Ids[j] == cartela->id)
            {
                owner = jogadores[i];
            }
        }
    }
    return owner;
}

tJogador getOwnerById(int id, tJogador* jogadores, int qJog)
{
    tJogador owner;
    int i;
    for(i = 0; i < qJog; i++)
    {
        int Ids[getQtdCartelasDoJogador(&jogadores[i])];
        getIdsCartelasDoJogador(&jogadores[i], Ids);
        int j;
        for(j = 0; j < getQtdCartelasDoJogador(&jogadores[i]); j++)
        {
            if(Ids[j] == id)
            {
                owner = jogadores[i];
                break;
            }
        }
    }
    return owner;
}

int getPiorCartelaQtd(tCartela* cartelas, int totalCartelas, int qPedras, tJogador jogador)
{
    int ids[totalCartelas];
    getIdsCartelasDoJogador(&jogador, ids);
    int i;
    int menor = qPedras;
    for(i = 0; i < jogador.qtdCartelas; i++)
    {
        if(getCartelaById(ids[i], totalCartelas, cartelas).numerosMarcados < menor)
            menor = getCartelaById(ids[i], totalCartelas, cartelas).numerosMarcados;
    }
    return menor;
}

tCartela getCartelaById(int id, int totalCartelas, tCartela* cartelas)
{
    int i;
    for(i = 0; i < totalCartelas; i++)
    {
        if(cartelas[i].id == id)
            return cartelas[i];
    }
}