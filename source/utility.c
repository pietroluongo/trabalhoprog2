#include "../headers/utility.h"

int ChecaParam(int arg)
{
    return arg == 2;
}

void Erro(char* msg)
{
    //printf(msg);
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
    fscanf(input, "%d;%d;%d;%d;%d", seed, qtdPedras, lin, col, qJog);
}

void CopiaStr(char* A, char* B)
{
    int i = 0;
    while(A[i] != '\0')
    {
        B[i] = A[i];
        i++;
    }
}
void AppendString(char* from, char* to)
{
    int l = strlen(to);
    int i;
    for(i = 0; i < strlen(from); i++)
    {
        to[l + i] = from[i];
    }
}

void OrdenaVetor(int* vet, int size)
{
    int i, j, aux;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(vet[i] < vet[j])
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}