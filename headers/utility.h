/* 
 * File:   utility.h
 * Author: Gabriel Pietroluongo Nascimento
 *
 * Utilidades gerais do programa
 */

#ifndef UTILITY_H
#define UTILITY_H
#include <stdio.h>
#include <string.h>
#include "tJogador.h"
#define MSG_ERRO_NO_PARAM "ERRO: O diretorio de arquivos de configuracao nao foi informado!"
#define MSG_ERRO_NO_CONFIG "ERRO: Nao foi possivel ler o arquivo %s"
#define CONFIG_INPUT_PATH "/input/jogo_config.txt"
#define READ "r"
#define WRITE "w"
#define APPEND "a"

typedef struct
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
    int totalCartelas;
} tConfig;

int getConfSeed(tConfig* config);

int getConfPedras(tConfig* config);

int getConfLin(tConfig* config);

int getConfCol(tConfig* config);

int getConfqJog(tConfig* config);

int getConfTotalCartelas(tConfig* config);

//Checa se o programa foi inicializado com os parâmetros corretos
int ChecaParam(int arg);

//Mostra mensagem de erro
void Erro(char* msg);

//Abre o arquivo solicitado
FILE* GetFile(char* PATH, FILE* input);

//Fecha o arquivo solicitado
void CloseFile(FILE* file);

//Lê as configurações de jogo do arquivo de configurações e salva no struct
void ReadConfig(/*FILE* input*/ tConfig* cfg);

//Copia uma string para outra
void CopiaStr(char* A, char* B);

void AppendString(char* from, char* to);

void OrdenaVetor(int* vet, int size);

#endif /* UTILITY_H */

