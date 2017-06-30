#include "../headers/bingo.h"

void IniciaJogo(tCartela* cartelas, tJogador* jogadores, tConfig* cfg)
{
    //Reinicia o gerador para o sorteio das pedras
    ReiniciaGerador(getConfSeed(cfg), getConfPedras(cfg));
    int pedra;
    int bingo = 0;
    tJogador vencedores[10];
    while(!bingo)
    {
        pedra = GeraProxNumero();
        printf("Pedra:%d\n", pedra);
        PrintaCartelasDoJogo(cartelas, jogadores, cfg);
        int i;
        for(i = 0; i < getConfTotalCartelas(cfg); i++)
        {
            if(ChecaCartela(&cartelas[i], pedra))
            {
                vencedores[bingo] = getOwnerById(&cartelas[i], jogadores, cfg);
                bingo++;
            }
        }
    }
    PrintaCartelasDoJogo(cartelas, jogadores, cfg);
    if(bingo == 1)
    {
        printf("Jogador Venceu!\n%s\n", vencedores[0].nome);
    }
    else
    {
        printf("Jogadores Empataram!");
        int i;
        for(i = 0; i < bingo; i++)
        {
            printf("\n%s", vencedores[i].nome);
        }
    }
}