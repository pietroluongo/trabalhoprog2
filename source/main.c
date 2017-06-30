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
    //Cria o struct que contém as configurações do programa
    tConfig config;
    
    //Lê as configurações do programa para o struct
    ReadConfig(&config);
    
    //Vetor com informações dos participantes
    tJogador jogadores[getConfqJog(&config)];
    
    //Total de cartelas do jogo
    int totalCartelas = 0;
    
    //Lê o nome dos participantes e quantas cartelas cada um tem
    LeParticipantes(getConfqJog(&config), jogadores, &totalCartelas);
    
    //Salva o total de cartelas para o struct de configurações
    setConfTotalCartelas(&config, totalCartelas);
    
    //Cria um vetor que contém todas as cartelas do jogo
    tCartela cartelas[totalCartelas];
    
    //Monta as cartelas dos participantes
    MontaCartelas(jogadores, cartelas, &config);
    
    //PrintaCartelasDoJogador(cartelas, &jogadores[0], totalCartelas);
    
    //PrintaCartelasDoJogo(cartelas, jogadores &config);
    //Executa o jogo de bingo
    //printf("%s", getOwnerById(&cartelas[3], jogadores, &config).nome);
    IniciaJogo(cartelas, jogadores, &config);
    //ChecaCartela(&cartelas[1], 18);
    
    return (EXIT_SUCCESS);
}

