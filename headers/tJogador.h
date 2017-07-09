/* 
 * File:   tJogador.h
 * Author: Gabriel Pietroluongo Nascimento
 *
 * Tipo tJogador usado no bingo
 */

#ifndef JOGADOR_H
#define JOGADOR_H
#include "utility.h"

typedef struct
{
    int id;
    char nome[99];
    int qtdCartelas;
    int cartelaIds[10];
} tJogador;

//Inicializa determinado jogador
tJogador InitJogador(char* name, int qtd, int id);

//Lê os participantes do arquivo de configurações
void LeParticipantes(int qJog, tJogador* out, int* totalCartelas, FILE* input);

//Retorna a quantidade de cartelas de determinado jogador
int getQtdCartelasDoJogador(tJogador* jog);

//Retorna os ids das cartelas de determinado jogador
void getIdsCartelasDoJogador(tJogador* jog, int* ids);

//Retorna o nome de determinado jogador
void getName(tJogador* jog, char* out);

//Altera o id da cartela #index do jogador jog para o valor id
void setCartelaId(tJogador* jog, int index, int id);

#endif /* UTILITY_H */

