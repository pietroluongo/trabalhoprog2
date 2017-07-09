#include "../headers/tJogador.h"

tJogador InitJogador(char* name, int qtd, int id)
{
    tJogador j;
    j.id = id;
    CopiaStr(name, j.nome);
    j.qtdCartelas = qtd;
    return j;
}


void LeParticipantes(int qJog, tJogador* out, int* totalCartelas, FILE* input)
{
    int i;
    for(i = 0; i < qJog; i++)
    {
        char nome[99];
        int qCartelas;
        fscanf(input, "\n%98[^;]", nome);
        fscanf(input, "%*[;]");
        fscanf(input, "%d", &qCartelas);
        fscanf(input, "%*[^\n]");
        out[i] = InitJogador(nome, qCartelas, i);
        *totalCartelas += qCartelas;
        if(feof(input))
        {
            PrintaErro("Final inesperado do arquivo de configuracoes.\n");
            exit(1);
        }
    }
}

int getQtdCartelasDoJogador(tJogador* jog)
{
    return jog->qtdCartelas;
}

void getIdsCartelasDoJogador(tJogador* jog, int* ids)
{
    int i;
    for(i = 0; i < jog->qtdCartelas; i++)
    {
        ids[i] = jog->cartelaIds[i];
    }
}

void getName(tJogador* jog, char* out)
{
    out = jog->nome;
}

void setCartelaId(tJogador* jog, int index, int id)
{
    jog->cartelaIds[index] = id;
}