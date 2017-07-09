#include "../headers/utility.h"

int ChecaArgs(int argCount, char** argVal, FILE** input)
{
   if(argCount <= 1)
    {
        PrintaErro("Diretorio nao informado\n");
        exit(1);
    }
    char PATH_IN[1050];
    sprintf(PATH_IN, "%s/input/jogo_config.txt", argVal[1]);
    printf("Abrindo %s...", PATH_IN);
    *input = fopen(PATH_IN, "r");
    if(!input)
    {
        printf("\nERRO: Nao foi possivel abrir o arquivo: %s\n", PATH_IN);
        exit(1);
    }
    printf("Aberto.\n");
}

void PrintaErro(char* msg)
{
    printf("ERRO: %s", msg);
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

void OpenFiles(FILE** main, FILE** carts, FILE** stats, FILE** extra, char* str)
{
    char PATH_OUT[1050];
    sprintf(PATH_OUT, "%s/output", str);
    mkdir(PATH_OUT, S_IRWXU);
    char PATH_OUT_MAIN[1050];
    char PATH_OUT_CART[1050];
    char PATH_OUT_STATS[1050];
    char PATH_OUT_EXTRA[1050];
    sprintf(PATH_OUT_MAIN, "%s/output/saida.txt", str);
    sprintf(PATH_OUT_CART, "%s/output/cartelas_jogador.txt", str);
    sprintf(PATH_OUT_STATS, "%s/output/estatisticas_jogo.txt", str);
    sprintf(PATH_OUT_EXTRA, "%s/output/bonus.txt", str);
    *main = fopen(PATH_OUT_MAIN, "w");
    *carts = fopen(PATH_OUT_CART, "w");
    *stats = fopen(PATH_OUT_STATS, "w");
    *extra = fopen(PATH_OUT_EXTRA, "w");
    if(!*main || !*carts || !*stats || !*extra)
    {
        printf("ERRO: Nao foi possivel criar os arquivos de saída.");
        printf("\nCertifique-se de que a pasta %s existe e que", PATH_OUT);
        printf(" o usuario atual possui permissao para escrever nela.\n");
        exit(1);
    }
}

void CloseFiles(FILE* main, FILE* carts, FILE* stats, FILE* extra)
{
    fclose(main);
    fclose(carts);
    fclose(stats);
    fclose(extra);
}