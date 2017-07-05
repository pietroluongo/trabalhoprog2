/* 
 * File:   utility.h
 * Author: Gabriel Pietroluongo Nascimento
 *
 * Utilidades gerais do programa
 */

#ifndef UTILITY_H
#define UTILITY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MSG_ERRO_NO_PARAM "O diretorio de arquivos de configuracao nao foi informado!"
#define MSG_ERRO_NO_CONFIG "Nao foi possivel ler o arquivo %s"
#define CONFIG_INPUT_PATH "/input/jogo_config.txt"
#define OUTPUT_PATH_MAIN "/output/saida.txt"
#define OUTPUT_PATH_CART "/output/cartelas_jogador.txt"
#define READ "r"
#define WRITE "w"
#define APPEND "a"

//Checa se o programa foi inicializado com os parâmetros corretos
int ChecaArgs(int argCount, char** argVal, FILE** input);

//Mostra mensagem de erro
void PrintaErro(char* msg);

//Copia uma string para outra
void CopiaStr(char* A, char* B);

//Concatena String
void AppendString(char* from, char* to);

//Ordena um vetor de inteiros
void OrdenaVetor(int* vet, int size);

//Abre os arquivos de saída
void OpenFiles(FILE** main, FILE** carts, FILE** stats, FILE** extra, char* str);

//Fecha os arquivos de saída
void CloseFiles(FILE* main, FILE* carts, FILE* stats, FILE* extra);

#endif /* UTILITY_H */

