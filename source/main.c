/* 
 * File:   main.c
 * Author: gabri
 *
 * Created on 23 de Junho de 2017, 16:40
 */

#include <stdio.h>
#include <stdlib.h>
#include "../headers/utility.h"
#include "../headers/tCartela.h"
#include "../headers/tJogador.h"

/*
 * 
 */
int main(int argc, char** argv)
{    
    //Seed da geração de números
    int seed;
    //Quantidade de pedras a serem sorteadas pela banca - MAX: 900
    int qtdPedras;
    //Quantidade de linhas da cartela - MAX: 20
    int lin;
    //Quantidade de colunas da cartela - MAX: 20
    int col;
    //Quantidade de participantes do jogo - MAX: 20
    int qJog;
    //Total de cartelas do jogo
    int totalCartelas = 0;
    
    scanf("%d;%d;%d;%d;%d", &seed, &qtdPedras, &lin, &col, &qJog);
    
    //Vetor com informações dos participantes
    tJogador jogadores[qJog];
    
    //Lê o nome dos participantes e quantas cartelas cada um tem
    LeParticipantes(qJog, jogadores, &totalCartelas);
    
    //Cria um vetor que contém todas as cartelas do jogo
    tCartela cartelas[totalCartelas];
    
    //Monta as cartelas dos participantes
    MontaCartelas(qJog, jogadores, cartelas, lin, col, qtdPedras);
 
    PrintaCartela(&cartelas[0]);
    
    return (EXIT_SUCCESS);
}

