/* 
 * File:   bingo.h
 * Author: Gabriel Pietroluongo Nascimento
 *
 * Núcleo de processamento do jogo de bingo
 */

#ifndef BINGO_H
#define BINGO_H
#include "utility.h"
#include "tCartela.h"
#include "tJogador.h"
#include "../source/tGeradorAle.h"

//Struct de configurações do jogo
typedef struct
{
    //Seed da geração de números
    int seed;
    //Quantidade de pedras a serem sorteadas pela banca - MAX: 900
    int qtdPedras;
    //Quantidade de linhas da cartela - MAX: 20
    int lin;
    //Quantidade de colunas da cartela - MAX: 20
    int col;
    //Quantidade de participantes do jogo - MAX: 20
    int qJog;
    //Total de cartelas do jogo
    int totalCartelas;
    //Vetor com informações dos participantes do jogo
    tJogador jogadores[20];
    //Vetor com todas as cartelas do jogo
    tCartela cartelas[200];
} tBingo;

//Realiza o jogo de bingo
void RealizaJogo(tBingo* jogo);

//Inicializa as configurações do jogo
void InitGame(/*FILE* input*/ tBingo* cfg);

#endif /* BINGO_H */

