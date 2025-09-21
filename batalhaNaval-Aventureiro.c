#include <stdio.h>

#define TAMANHO 10   // Tamanho fixo do tabuleiro (10x10)
#define NAVIO 3      // Tamanho fixo dos navios
#define AGUA 0       // Representa água no tabuleiro
#define OCUPADO 3    // Representa parte de um navio

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar navio horizontal
void posicionarHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int colunaInicio) {
    if (linha + colunaInicio > TAMANHO - 1) return; // fora do tabuleiro

    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linha][colunaInicio + i] != AGUA) return;  // verifica se espaço esta vazio(água)
        tabuleiro[linha][colunaInicio + i] = OCUPADO;
    }
}

// Função para posicionar navio vertical
void posicionarVertical(int tabuleiro[TAMANHO][TAMANHO], int linhaInicio, int coluna) {
    if (linhaInicio + coluna > TAMANHO - 1) return; // fora do tabuleiro

    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaInicio + i][coluna + i] != AGUA) return; // verifica se espaço esta vazio(água)
        tabuleiro[linhaInicio + i][coluna + i] = OCUPADO;
    }
}

// Função para posicionar navio diagonal ↘
void posicionarDiagonalDireita(int tabuleiro[TAMANHO][TAMANHO], int linhaInicio, int colunaInicio) {
    if (linhaInicio + colunaInicio > TAMANHO - 1) return; // fora do tabuleiro

    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaInicio + i][colunaInicio + i] != AGUA) return;  // verifica se espaço esta vazio(água)
        tabuleiro[linhaInicio + i][colunaInicio + i] = OCUPADO;
    }
}

// Função para posicionar navio diagonal ↙
void posicionarDiagonalEsquerda(int tabuleiro[TAMANHO][TAMANHO], int linhaInicio, int colunaInicio) {
    if (linhaInicio + colunaInicio > TAMANHO - 1) return; // fora do tabuleiro

    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaInicio + i][colunaInicio + i] != AGUA) return;  // verifica se espaço esta vazio(água)
        tabuleiro[linhaInicio + i][colunaInicio - i] = OCUPADO;
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[10][10];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializar com água
    inicializarTabuleiro(tabuleiro);

    // Posicionar os 4 navios
    posicionarHorizontal(tabuleiro, 1, 0);       // Horizontal na linha 2 (índice 1)
    posicionarVertical(tabuleiro, 4, 6);         // Vertical na linha 5, coluna G
    posicionarDiagonalDireita(tabuleiro, 0, 5);  // Diagonal ↘ começando em (linha 1, col F)
    posicionarDiagonalEsquerda(tabuleiro, 6, 2); // Diagonal ↙ começando em (linha 7, col C)

    // Exibir tabuleiro
    printf(" ===== TABULEIRO =====\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}