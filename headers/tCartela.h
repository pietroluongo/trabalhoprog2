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

//Checa se algum numero da cartela foi sorteado na rodada
void ChecaCartela(tCartela* cartela, int num);

//Printa as informações da cartela
void PrintaCartela(tCartela* cartela);

//Retorna o id da cartela
int GetIdC(tCartela cartela);

//Retorna a quantidade de números marcados na cartela
int getHitsC(tCartela cartela);

//Monta as cartelas dos jogadores
void MontaCartelas(tJogador* jogadores, tCartela* cartelas, tConfig* cfg);

#endif /* UTILITY_H */

