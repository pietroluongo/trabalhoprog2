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
#define MSG_ERRO_NO_PARAM "ERRO: O diretorio de arquivos de configuracao nao foi informado!"
#define MSG_ERRO_NO_CONFIG "ERRO: Nao foi possivel ler o arquivo %s"
#define CONFIG_INPUT_PATH "/input/jogo_config.txt"
#define OUTPUT_PATH_MAIN "/output/saida.txt"
#define OUTPUT_PATH_CART "/output/cartelas_jogador.txt"
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

//Copia uma string para outra
void CopiaStr(char* A, char* B);

void AppendString(char* from, char* to);

void OrdenaVetor(int* vet, int size);

#endif /* UTILITY_H */

