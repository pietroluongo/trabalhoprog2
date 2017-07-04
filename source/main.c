/* 
 * File:   main.c
 * Author: gabri
 *
 * Created on 23 de Junho de 2017, 16:40
 */

#include <stdio.h>
#include <stdlib.h>
#include "../headers/utility.h"
#include "../headers/bingo.h"
/*
 * 
 */
int main(int argc, char** argv)
{
    tBingo jogo;
    FILE* input;
    FILE* out_main;
    FILE* out_cart;
    FILE* out_extra;
    //Lê as configurações do programa para o struct
    InitGame(&jogo);
    
    //Realiza o jogo
    RealizaJogo(&jogo);
    
    return (EXIT_SUCCESS);
}

