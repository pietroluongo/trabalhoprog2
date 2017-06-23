#include "../headers/utility.h"

void GetFile(char* PATH, FILE* input)
{
    input = fopen(PATH, "r");
}

void CriaJogadores(int qtd, tJogador* players, FILE* config)
{
    int i;
    for(i = 0; i<qtd; i++)
    {
        char nome[99];
        int qtd;
        fscanf(config, "[^;]%s", &nome);
        fscanf(config, "%d", &qtd);
        fscanf(config, "%*[\n]");
        players[i] = CriaJogador(nome, qtd);
    }
}

void ReadConfig(int *seed, int *qtdPedras, int *lin, int *col, int *qJog, FILE* input)
{
    fscanf(input, "%d", &seed);
    fscanf(input, "%d", &qtdPedras);
    fscanf(input, "%d", &lin);
    fscanf(input, "%d", &col);
    fscanf(input, "%d", &qJog);
}