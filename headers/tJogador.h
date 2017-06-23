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
    int nums[20][20];
} tCartela;

tCartela CriaCartela(int lin, int col);

void PrintaCartela(tCartela cartela);

#endif /* TCARTELA_H */

