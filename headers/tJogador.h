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

tJogador InitJogador(char* name, int qtd, int id);

void LeParticipantes(int qJog, tJogador* out, int* totalCartelas);

int getQtdCartelasDoJogador(tJogador* jog);

void getIdsCartelasDoJogador(tJogador* jog, int* ids);

#endif /* UTILITY_H */

