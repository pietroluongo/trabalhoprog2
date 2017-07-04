/* 
 * File:   tCartela.h
 * Author: Gabriel Pietroluongo Nascimento
 *
 * Tipo Cartela - Gerenciamento das cartelas do bingo
 */

#ifndef CARTELA_H
#define CARTELA_H
#include "../source/tGeradorAle.h"
#include "utility.h"

typedef struct
{
    int id;
    int lin;
    int col;
    int numeros[20][20];
    int numerosMarcados;
} tCartela;

//Inicializa a cartela
tCartela initCartela(int id, int lin, int col, int qtdPedras);

//Checa se algum numero da cartela foi sorteado na rodada. Retorna 1 em caso de
//bingo
int ChecaCartela(tCartela* cartela, int num);

//Printa as informações da cartela
void PrintaCartela(tCartela* cartela, tConfig cfg);

//Printa todas as cartelas de determinado jogador
void PrintaCartelasDoJogador(tCartela* cartelas, tJogador* jogador, tConfig cfg);

//Salva as informações sobre todas as cartelas de dado jogador no vetor "destino"
void GetCartelasDoJogador(tCartela* cartelasDoJogo, tCartela* destino, tJogador* jogador, int total);

//Printa todas as cartelas do jogo (estado do jogo)
void PrintaCartelasDoJogo(tCartela* cartelas, tJogador* jogadores, tConfig* cfg);

//Retorna o id da cartela
int GetIdC(tCartela cartela);

//Retorna a quantidade de números marcados na cartela
int getHitsC(tCartela cartela);

//Monta as cartelas dos jogadores
void MontaCartelas(tJogador* jogadores, tCartela* cartelas, tConfig* cfg);

//Retorna o jogador que é o dono da cartela
tJogador getOwnerById(tCartela* cartela, tJogador* jogadores, tConfig* cfg);

#endif /* UTILITY_H */

