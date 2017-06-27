#include "../headers/tJogador.h"

tJogador InitJogador(char* name, int qtd, int id)
{
    tJogador j;
    j.id = id;
    CopiaStr(name, j.nome);
    j.qtdCartelas = qtd;
    return j;
}


void LeParticipantes(int qJog, tJogador* out, int* totalCartelas)
{
    int i;
    for(i = 0; i < qJog; i++)
    {
        char nome[99];
        int qCartelas;
        scanf("\n%98[^;]", nome);
        scanf("%*[;]");
        scanf("%d", &qCartelas);
        scanf("%*[^\n]");
        out[i] = InitJogador(nome, qCartelas, i);
        *totalCartelas += qCartelas;
    }
}