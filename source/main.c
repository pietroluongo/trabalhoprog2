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

int main(int argc, char** argv)
{
    FILE* input;
    FILE* out_main;
    FILE* out_cart;
    FILE* out_stats;
    FILE* out_extra; 
    //Checa os argumentos de entrada
    ChecaArgs(argc, argv, &input);
    
    //Abre os arquivos de saída
    OpenFiles(&out_main, &out_cart, &out_stats, &out_extra, argv[1]);
    
    //Instância do jogo de bingo
    tBingo jogo;
    
    //Lê as configurações do programa para o struct
    InitGame(&jogo, input, out_cart);
    
    //Realiza o jogo
    RealizaJogo(&jogo, &out_main, &out_stats, &out_extra);
    
    //Fecha os arquivos de saída
    CloseFiles(out_main, out_cart, out_stats, out_extra);
    
    return (EXIT_SUCCESS);
}

