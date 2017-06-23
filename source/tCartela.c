#include "../headers/tCartela.h"

tCartela InitCartela(int id, int lin, int col)
{
    ReiniciaGerador(id, lin*col);
    tCartela r;
    r.id = id;
    r.lin = lin;
    r.col = col;
    memset(r.numeros, 0, sizeof r.numeros);
    int i, j;
    for(i = 0; i < col; i++)
    {
        for(j = 0; j < lin; j++)
        {
            r.numeros[i][j] = GeraProxNumero();
        }
    }
    return r;
}

void ChecaCartela(tCartela* cartela, int num)
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
}

void PrintaCartela(tCartela* cartela)
{
    //TODO
}

int GetIdC(tCartela cartela)
{
    return cartela.id;
}

int getHitsC(tCartela cartela)
{
    return cartela.numerosMarcados;
}

void MontaCartelas(int size, tJogador* jogadores, tCartela* cartelas, int lin, int col)
{
    int k = 0;
    int i;
    for(i = 0; i<size; i++)
    {
        int j;
        for(j = 0; j < jogadores[i].qtdCartelas; j++)
        {
            tCartela c = InitCartela(jogadores[i].id, lin, col);
            jogadores[i].cartelaIds[j] = k;
            cartelas[k] = c;
            k++;
        }
    }
}