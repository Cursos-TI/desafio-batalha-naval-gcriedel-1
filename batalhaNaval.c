// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Objetivo: Batalha Naval - Tema 2 - Desafio Nível Aventureiro - Modulo 5

#include <stdio.h>
int main() {

    // =====================================================
    // criando o tabuleiro 10x10
    // tudo começa com 0 representando água
    // =====================================================

    int tabuleiro[10][10];

    // preenchendo toda a matriz com 0

    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 10; j++) {

            tabuleiro[i][j] = 0;
        }
    }

    // =====================================================
    // tamanho padrão dos navios
    // todos terão tamanho 3
    // =====================================================

    int tamanhoNavio = 3;

    // =====================================================
    // NAVIO HORIZONTAL
    // =====================================================

    int linhaH = 1;
    int colunaH = 2;

    // validação simples pra garantir
    // que o navio não saia do tabuleiro

    if (colunaH + tamanhoNavio <= 10) {

        // verificando se já existe outro navio ali

        int podePosicionar = 1;

        for (int i = 0; i < tamanhoNavio; i++) {

            if (tabuleiro[linhaH][colunaH + i] != 0) {

                podePosicionar = 0;
            }
        }

        // se estiver tudo livre
        // posiciona o navio

        if (podePosicionar == 1) {

            for (int i = 0; i < tamanhoNavio; i++) {

                tabuleiro[linhaH][colunaH + i] = 3;
            }
        }
    }

    // =====================================================
    // NAVIO VERTICAL
    // =====================================================

    int linhaV = 5;
    int colunaV = 7;

    // validação de limite

    if (linhaV + tamanhoNavio <= 10) {

        int podePosicionar = 1;

        // verificando sobreposição

        for (int i = 0; i < tamanhoNavio; i++) {

            if (tabuleiro[linhaV + i][colunaV] != 0) {

                podePosicionar = 0;
            }
        }

        // posicionando o navio

        if (podePosicionar == 1) {

            for (int i = 0; i < tamanhoNavio; i++) {

                tabuleiro[linhaV + i][colunaV] = 3;
            }
        }
    }

    // =====================================================
    // NAVIO DIAGONAL DESCENDO
    // aqui linha e coluna aumentam juntas
    // =====================================================

    int linhaD1 = 0;
    int colunaD1 = 0;

    // validação simples de limite

    if ((linhaD1 + tamanhoNavio <= 10) &&
        (colunaD1 + tamanhoNavio <= 10)) {

        int podePosicionar = 1;

        // verificando se já existe navio

        for (int i = 0; i < tamanhoNavio; i++) {

            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {

                podePosicionar = 0;
            }
        }

        // posicionando na diagonal

        if (podePosicionar == 1) {

            for (int i = 0; i < tamanhoNavio; i++) {

                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        }
    }

    // =====================================================
    // NAVIO DIAGONAL SUBINDO
    // aqui a linha aumenta e a coluna diminui
    // =====================================================

    int linhaD2 = 2;
    int colunaD2 = 9;

    // validação pra não sair do tabuleiro

    if ((linhaD2 + tamanhoNavio <= 10) &&
        (colunaD2 - tamanhoNavio + 1 >= 0)) {

        int podePosicionar = 1;

        // verificando sobreposição

        for (int i = 0; i < tamanhoNavio; i++) {

            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {

                podePosicionar = 0;
            }
        }

        // posicionando o navio diagonal

        if (podePosicionar == 1) {

            for (int i = 0; i < tamanhoNavio; i++) {

                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
            }
        }
    }

    // =====================================================
    // mostrando o tabuleiro na tela
    // aqui os 0 representam água
    // e os 3 representam partes dos navios
    // =====================================================

    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 10; j++) {

            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    // =====================================================
    // fim do programa
    // =====================================================

    return 0;
}