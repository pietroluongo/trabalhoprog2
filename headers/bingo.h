/* 
 * File:   bingo.h
 * Author: Gabriel Pietroluongo Nascimento
 *
 * Núcleo de processamento do jogo de bingo
 */

#ifndef BINGO_H
#define BINGO_H
#include "utility.h"
#include "tCartela.h"
#include "tJogador.h"
#include "../source/tGeradorAle.h"

//Realiza o jogo de bingo
void IniciaJogo(tCartela* cartelas, tJogador* jogadores, tConfig* cfg);

#endif /* BINGO_H */

