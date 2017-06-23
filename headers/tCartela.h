/* 
 * File:   tCartela.h
 * Author: Gabriel Pietroluongo Nascimento
 *
 * Tipo tCartela
 */

#ifndef TCARTELA_H
#define TCARTELA_H

#include "tGeradorAle.h"

typedef struct
{
    int id;
    int lin;
    int col;
    int marcados;
    int nums[20][20];
} tCartela;

//Cria uma cartela baseada nas entradas de parâmetro da função
tCartela CriaCartela(int lin, int col, int id);

//Printa a cartela
void PrintaCartela(tCartela cartela);

//Checa os números da cartela; Se algum foi sorteado na rodada, substitui por ---
void ChecaCartela(tCartela cartela);

//Retorna a ID da cartela
int getID(tCartela cartela);

//Retorna a quantidade de números marcados na cartela
int getHits(tCartela cartela);

#endif /* TCARTELA_H */

