/* 
 * File:   main.c
 * Author: gabri
 *
 * Created on 23 de Junho de 2017, 16:40
 */

#include <stdio.h>
#include <stdlib.h>
#include "../headers/utility.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    if(!ChecaParam(argc))
    {
        Erro(MSG_ERRO_NO_PARAM);
        return(EXIT_FAILURE);
    }
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
    
    //Referência ao arquivo de configuração
    FILE* config;
    
    //Pega a referência ao arquivo de configuração de fato
    GetFile(argv[1], config);
    
    //Se o arquivo não existir, mostrar mensagem de erro
    if(!config)
    {
        Erro(MSG_ERRO_NO_CONFIG);
        return(EXIT_FAILURE);
    }
    
    //Lê as configurações de jogo do arquivo
    ReadConfig(&seed, &qtdPedras, &lin, &col, &qJog, config);

    
    return (EXIT_SUCCESS);
}

