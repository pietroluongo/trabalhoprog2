/* 
 * File:   tCartela.h
 * Author: Gabriel Pietroluongo Nascimento
 *
 * Tipo Cartela - Gerenciamento das cartelas de jogos
 * Este tipo pode ser expandido no futuro a fim de possibilitar seu uso em 
 * outros jogos. No momento, ele está otimizado para um jogo de bingo. Assim, 
 * a maioria das funções é específica para o bingo. Poderia ser criado um tipo
 * 'tCartelaJogoDaVelha', por exemplo, para outro uso utilizando as funções
 * presentes aqui.
 */

#ifndef CARTELA_H
#define CARTELA_H
#include "../source/tGeradorAle.h"
#include "utility.h"
#include "tJogador.h"

typedef struct
{
    int id;
    int lin;
    int col;
    int numeros[20][20];
    int numerosMarcados;
} tCartela;

//Inicializa a cartela
tCartela initCartelaBingo(int id, int lin, int col, int qtdPedras);

/*
 * Checa se algum numero da cartela foi sorteado na rodada. Retorna 1 em caso
 * de bingo
*/
int ChecaCartelaBingo(tCartela* cartela, int num);

//Printa as informações de uma cartela de bingo
void PrintaCartelaBingo(tCartela* cartela);

//Printa todas as cartelas de determinado jogador
void PrintaCartelasDoJogador(tCartela* cartelas, tJogador* jogador, int totalCartelas);

//Salva as informações sobre todas as cartelas de dado jogador no vetor "destino"
void GetCartelasDoJogador(tCartela* cartelasDoJogo, tCartela* destino, tJogador* jogador, int total);

//Printa todas as cartelas do jogo (estado do jogo)
void PrintaCartelasBingo(tCartela* cartelas, tJogador* jogadores, int qJog, int total);

//Retorna o id da cartela
int GetIdCBingo(tCartela cartela);

//Retorna a quantidade de números marcados na cartela
int getHitsCBingo(tCartela cartela);

//Monta as cartelas dos jogadores
void MontaCartelasBingo(tCartela* cartelas, tJogador* jogadores,
                        int totalCartelas, int lin, int col, int qPedras);
//Retorna o jogador que é o dono da cartela
tJogador getOwnerById(tCartela* cartela, tJogador* jogadores, int qJog);

#endif /* UTILITY_H */

