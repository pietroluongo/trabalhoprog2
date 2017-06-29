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
    for(i = 0; i < cartela->col; i++)
    {
        for(j = 0; j < cartela->lin; j++)
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

void PrintaCartela(tCartela* cartela)
{
    int i, j;
    for(i = 0; i <= cartela->col; i++)
    {
        int num = cartela->numeros[i][j];
        printf("\t|");
        if(num < 10 && num > 0)
        {
            printf("00");
            printf("%d|", cartela->numeros[i][0]);
        }
        else if (num > 10)
        {
            printf("0");
            printf("%d|", cartela->numeros[i][0]);
        }
        else
        {
            printf("---");
        }
        for(j = 1; j < cartela->lin-1; j++)
        {
            int num = cartela->numeros[i][j];
            if(num < 10 && num > 0)
                printf("00");
            else if(num > 10)
                printf("0");
            else
            {
                printf("---|");
                continue;
            }
            printf("%d|", num);
        }
        printf("\n");
        j = 0;
    }
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
    int k = 0;
    int i;
    for(i = 0; i < getConfqJog(cfg); i++)
    {
        int j;
        for(j = 0; j < jogadores[i].qtdCartelas; j++)
        {
            tCartela c = InitCartela(jogadores[i].id, getConfLin(cfg), 
                                     getConfCol(cfg), getConfPedras(cfg));
            jogadores[i].cartelaIds[j] = k;
            cartelas[k] = c;
            k++;
        }
    }
}