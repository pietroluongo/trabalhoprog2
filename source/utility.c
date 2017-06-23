#include "../headers/utility.h"

int ChecaParam(int arg)
{
    return arg == 2;
}

void Erro(char* msg)
{
    printf(msg);
}

FILE* GetFile(char* PATH, FILE* input)
{
    input = fopen(PATH, READ);
}

void CloseFile(FILE* file)
{
    fclose(file);
}

void ReadConfig(int *seed, int *qtdPedras, int *lin, int *col, int *qJog, FILE* input)
{
    fscanf(input, "%d;%d;%d;%d;%d", &seed, &qtdPedras, &lin, &col, &qJog);
}

void CopiaStr(char* A, char* B)
{
    int i = 0;
    while(A[i] != '\0')
    {
        B[i] = A[i];
    }
}
