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


//Checa se o programa foi inicializado com os parâmetros corretos
int ChecaParam(int arg);

//Mostra mensagem de erro
void Erro(char* msg);

//Abre o arquivo solicitado
FILE* GetFile(char* PATH, FILE* input);

//Fecha o arquivo solicitado
void CloseFile(FILE* file);

//Lê as configurações de jogo do arquivo de configurações
void ReadConfig(int *seed, int *qtdPedras, int *lin, int *col, int *qJog, FILE* input);

//Copia uma string para outra
void CopiaStr(char* A, char* B);

void AppendString(char* from, char* to);

#endif /* UTILITY_H */

