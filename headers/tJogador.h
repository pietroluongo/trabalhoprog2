/* 
 * File:   tCartela.h
 * Author: Gabriel Pietroluongo Nascimento
 *
 * Tipo tCartela
 */

#ifndef TJOGADOR_H
#define TJOGADOR_H

#include "tCartela.h"

typedef struct
{
    char nome[99];
    int qtdCartelas;
    tCartela cartelas[20];
    
}tJogador;

//Cria um jogador baseado nos argumentos passados
tJogador CriaJogador(char* nome, int qtd);

//Cria um jogador lendo as informações da entrada padrão
tJogador CriaJogadorR();

void CriaJogadores(int qtd, tJogador* players);

//Imprime as informações de dado jogador
void PrintaJogador(tJogador jogador);

#endif /* TCARTELA_H */

