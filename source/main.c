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
    
    if(!ChecaParam(argc))
    {
        Erro(MSG_ERRO_NO_PARAM);
        return(EXIT_FAILURE);
    }
    //Conterá o caminho do arquivo de entrada
    //c:/ etc... [100] + /input/jogo_config.txt [22] + /0 [1]
    char configPath[123];
    //Seta o valor da entrada
    CopiaStr(argv[1], configPath);
    //Adiciona o caminho do arquivo de configuração em si
    AppendString(configPath, CONFIG_INPUT_PATH);
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
    int totalCartelas;
    
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
    
    //Vetor com informações dos participantes
    tJogador jogadores[qJog];
    
    //Lê o nome dos participantes e quantas cartelas cada um tem
    LeParticipantes(qJog, config, jogadores, &totalCartelas);
    
    //Cria um vetor que contém todas as cartelas do jogo
    tCartela cartelas[totalCartelas];
    
    //Monta as cartelas dos participantes
    MontaCartelas(qJog, jogadores, cartelas, lin, col);
    
    //Fecha o arquivo
    CloseFile(config);
    
    return (EXIT_SUCCESS);
}

