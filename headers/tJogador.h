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

void LeParticipantes(int qJog, FILE* config, tJogador* out, int* totalCartelas);


#endif /* UTILITY_H */

