#include "../headers/bingo.h"

void IniciaJogo(tCartela* cartelas, tJogador* jogadores, tConfig* cfg)
{
    ReiniciaGerador(getConfSeed(cfg), getConfPedras(cfg));
    int pedra;
    int bContinue = 1;
    int ganhadores = 0;
    while(bContinue)
    {
        pedra = GeraProxNumero();
        int i;
        for(i = 0; i < getConfTotalCartelas(cfg); i++)
        {
            if(ChecaCartela(&cartelas[i], pedra))
            {
                bContinue = 0;
                ganhadores++;
            }
            PrintaCartela(&cartelas[i]);
        }
    }
    
    int ganhadoresIds[ganhadores];
}