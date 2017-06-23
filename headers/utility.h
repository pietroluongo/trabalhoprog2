/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utility.h
 * Author: 2017100536
 *
 * Utilidades gerais do projeto
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <string.h>
#include "tJogador.h"

void GetFile(char* PATH, FILE* input);

void CriaJogadores(int qtd, tJogador* players, FILE* config);

void ReadConfig(int *seed, int *qtdPedras, int *lin, int *col, int *qJog, FILE* input);


#endif /* UTILITY_H */

