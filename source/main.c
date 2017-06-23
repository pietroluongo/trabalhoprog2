/* 
 * File:   main.c
 * Author: Gabriel Pietroluongo Nascimento
 *
 * Núcleo do programa
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * TODO: Criar tipo tCartela;
 * TODO: Criar tipo tJogador;
 */
int main(int argc, char** argv) 
{
    //PARTE I: INICIALIZAÇÃO
    /* Lê os parâmetros do main() para um vetor char[101]
     * Esse vetor deverá conter o caminho para a configuração do jogo
     * Verificar a existência do parâmetro; Em caso negativo:
     * printf("ERRO: O diretorio de arquivos de configuracao nao foi informado!");
     * Nesse planejamento, esse caminho será chamado de $PATH
    */
    if(argc == 1)
    {
        printf("ERRO: O diretorio de arquivos de configuracao nao foi informado!");
        return (EXIT_FAILURE);
    }
    FILE* config;
    config = fopen(argv[1], "r");
    //Seed da geração de números
    int seed;
    //Quantidade de pedras a serem sorteadas pela banca - MAX: 900
    int qtdPedras;
    //Quantidade de linhas da cartela - MAX: 20
    int lin;
    //Quantidade de colunas da cartela - MAX: 20
    int col;
    //Quantidade de participantes do jogo - MAX: 20
    int qJog;
    fscanf(config, "%d;%d;%d;%d;%d", &seed, &qtdPedras, &lin, &col, &qJog);
    
    //PARTE II: CRIAÇÃO DO JOGO
    /*
     * Nome do arquivo de configurações: jogo_config.txt
     * Caminho: $PATH/input/jogo_config.txt
     * Ler as informações para a memória
     * Se não conseguir ler o arquivo, finaliza e imprime uma mensagem avisando
     * A mensagem deve conter o caminho que causou o erro e o nome do arquivo
     * 
     * Se conseguir ler: criar as cartelas (tipo tCartela?)
     * Salvar as cartelas em $PATH/output/cartelas_jogador.txt
     * Se não conseguir:
     * printf("ERRO: Nao foi possível salvar arquivo com as cartelas dos jogadores.");
     * 
     * Organização das configurações:
     *
     * Seed da geração de números
     *  int seed;
     * Quantidade de pedras a serem sorteadas pela banca - MAX: 900
     *  int qtdPedras;
     * Quantidade de linhas da cartela - MAX: 20
     *  int lin;
     * Quantidade de colunas da cartela - MAX: 20
     *  int col;
     * Quantidade de participantes do jogo - MAX: 20
     *  int qJog;
     * 
     * Cada jogador terá NO MÁXIMO 10 CARTELAS
     */

    //PARTE III: REALIZAÇÃO DO JOGO
    /*
     * Reiniciar Gerador -> Sortear pedra -> Marcar as pedras que foram 
     * sorteadas nas cartelas (reimprimir as cartelas a cada jogada)
     * 
     * Fim do jogo: alguém completar a cartela ou acabarem as pedras
     */
    
    return (EXIT_SUCCESS);
}

