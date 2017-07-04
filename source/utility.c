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

void ReadConfig(/*FILE* input*/ tConfig* cfg)
{
    //fscanf(input, "%d;%d;%d;%d;%d", seed, qtdPedras, lin, col, qJog);
    scanf("%d;", &cfg->seed);
    scanf("%d;", &cfg->qtdPedras);
    scanf("%d;", &cfg->lin);
    scanf("%d;", &cfg->col);
    scanf("%d", &cfg->qJog);
    cfg->bingo = 0;
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

int getConfSeed(tConfig* config)
{
    return config->seed;
}

int getConfPedras(tConfig* config)
{
    return config->qtdPedras;
}

int getConfLin(tConfig* config)
{
    return config->lin;
}

int getConfCol(tConfig* config)
{
    return config->col;
}

int getConfqJog(tConfig* config)
{
    return config->qJog;
}

int getConfTotalCartelas(tConfig* config)
{
    return config->totalCartelas;
}

int setConfTotalCartelas(tConfig* config, int n)
{
    config->totalCartelas = n;
}

int getDig(int n)
{
    int count = 0;
    while(n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}