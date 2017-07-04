#include "../headers/tCartela.h"

tCartela InitCartela(int id, int lin, int col, int qtdPedras)
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

int ChecaCartela(tCartela* cartela, int num)
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
        return 1;
    return 0;
}

void PrintaCartela(tCartela* cartela, tConfig cfg)
{
    printf("Cartela ID:%d\n", GetIdC(*cartela));
    int i, j;
    for(i = 0; i < cartela->lin; i++)
    {
        int num = cartela->numeros[i][0];
        printf("\t|");
        if(num > 0 && num < 10)
        {
            printf("00");
            printf("%d|", num);
        }
        else if(num >= 10 && num < 100)
        {
            printf("0");
            printf("%d|", num);
        }
        else if(num >= 100)
            printf("%d|", num);
        else
            printf("---|");
        for(j = 1; j < cartela->col; j++)
        {
            num = cartela->numeros[i][j];
            if(num > 0 && num < 10)
            {
                printf("00");
                printf("%d|", num);
            }
            else if(num >= 10 && num < 100)
            {
                printf("0");
                printf("%d|", num);
            }
            else if(num >= 100)
                printf("%d|", num);
            else
                printf("---|");
        }
        printf("\n");
    }
    /*
    for(i = 0; i < cartela->col-1; i++)
    {
        int num = cartela->numeros[i][j];
        printf("\t|");
        if(num < 10 && num > 0)
        {
            printf("00");
            printf("%d|", cartela->numeros[i][0]);
        }
        else if (num >= 10 && num < 100)
        {
            printf("0");
            printf("%d|", cartela->numeros[i][0]);
        }
        else if(num >= 100)
        {
            printf("%d|", cartela->numeros[i][0]);
        }
        else
        {
            printf("---|");
        }
        for(j = 1; j <= cartela->lin; j++)
        {
            int num = cartela->numeros[i][j];
            if(num < 10 && num > 0)
                printf("00");
            else if(num >= 10 && num < 100)
                printf("0");
            else if(num >= 100)
                printf("");
            else
            {
                printf("---|");
                continue;
            }
            printf("%d|", num);
        }
        printf("\n");
        j = 0;
    }*/
}

int GetIdC(tCartela cartela)
{
    return cartela.id;
}

int getHitsC(tCartela cartela)
{
    return cartela.numerosMarcados;
}

void MontaCartelas(tJogador* jogadores, tCartela* cartelas, tConfig* cfg)
{
    int q = getConfTotalCartelas(cfg);
    int k = 0;
    int jogAtual = 0;
    int countAtual = 0;
    int i;
    for(i = 0; i < q; i++)
    {
        tCartela c = InitCartela(k, getConfLin(cfg), getConfCol(cfg), getConfPedras(cfg));
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
            if(GetIdC(cartelasDoJogo[j]) == idsDoJogador[i])
            {
                destino[cur] = cartelasDoJogo[j];
                cur++;
            }
        }
    }
}

void PrintaCartelasDoJogador(tCartela* cartelas, tJogador* jogador, tConfig cfg)
{
    printf("Jogador:%s\n", jogador->nome);
    tCartela cartela [getQtdCartelasDoJogador(jogador)];
    
    GetCartelasDoJogador(cartelas, cartela, jogador, getConfTotalCartelas(&cfg));
    int i;
    for(i = 0; i < getQtdCartelasDoJogador(jogador); i++)
    {
        PrintaCartela(&cartela[i], cfg);
        printf("\n");
    }
}

void PrintaCartelasDoJogo(tCartela* cartelas, tJogador* jogadores, tConfig* cfg)
{
    int i;
    for(i = 0; i < getConfqJog(cfg); i++)
    {
        PrintaCartelasDoJogador(cartelas, &jogadores[i], *cfg);
        printf("\n");
    }
}

tJogador getOwnerById(tCartela* cartela, tJogador* jogadores, tConfig* cfg)
{
    tJogador owner;
    int i;
    for(i = 0; i < getConfqJog(cfg); i++)
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