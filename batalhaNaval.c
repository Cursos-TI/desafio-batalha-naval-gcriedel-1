// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Objetivo: Batalha Naval - Tema 3 - Desafio Nível Mestre - Modulo 5

#include <stdio.h>

int main() {

    // =====================================================
    // criando o tabuleiro principal 10x10
    // tudo começa com 0 representando água
    // =====================================================

    int tabuleiro[10][10];

    // preenchendo o tabuleiro inteiro com água

    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 10; j++) {

            tabuleiro[i][j] = 0;
        }
    }

    // =====================================================
    // tamanho padrão dos navios
    // =====================================================

    int tamanhoNavio = 3;

    // =====================================================
    // NAVIO HORIZONTAL
    // =====================================================

    int linhaH = 1;
    int colunaH = 2;

    if (colunaH + tamanhoNavio <= 10) {

        int podePosicionar = 1;

        // verificando se já existe outro navio

        for (int i = 0; i < tamanhoNavio; i++) {

            if (tabuleiro[linhaH][colunaH + i] != 0) {

                podePosicionar = 0;
            }
        }

        // posicionando o navio

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

    if (linhaV + tamanhoNavio <= 10) {

        int podePosicionar = 1;

        // verificando sobreposição

        for (int i = 0; i < tamanhoNavio; i++) {

            if (tabuleiro[linhaV + i][colunaV] != 0) {

                podePosicionar = 0;
            }
        }

        if (podePosicionar == 1) {

            for (int i = 0; i < tamanhoNavio; i++) {

                tabuleiro[linhaV + i][colunaV] = 3;
            }
        }
    }

    // =====================================================
    // NAVIO DIAGONAL DESCENDO
    // =====================================================

    int linhaD1 = 0;
    int colunaD1 = 0;

    if ((linhaD1 + tamanhoNavio <= 10) &&
        (colunaD1 + tamanhoNavio <= 10)) {

        int podePosicionar = 1;

        for (int i = 0; i < tamanhoNavio; i++) {

            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {

                podePosicionar = 0;
            }
        }

        if (podePosicionar == 1) {

            for (int i = 0; i < tamanhoNavio; i++) {

                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        }
    }

    // =====================================================
    // NAVIO DIAGONAL SUBINDO
    // =====================================================

    int linhaD2 = 2;
    int colunaD2 = 9;

    if ((linhaD2 + tamanhoNavio <= 10) &&
        (colunaD2 - tamanhoNavio + 1 >= 0)) {

        int podePosicionar = 1;

        for (int i = 0; i < tamanhoNavio; i++) {

            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {

                podePosicionar = 0;
            }
        }

        if (podePosicionar == 1) {

            for (int i = 0; i < tamanhoNavio; i++) {

                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
            }
        }
    }

    // =====================================================
    // agora começa a parte das habilidades
    // vou usar matrizes separadas pra cada uma
    // =====================================================

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // =====================================================
    // preenchendo todas as matrizes com 0
    // =====================================================

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }
    }

    // =====================================================
    // HABILIDADE CONE
    //
    // aqui o cone começa pequeno em cima
    // e vai aumentando pra baixo
    // =====================================================

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            // usando condição pra montar o cone

            if (j >= 2 - i && j <= 2 + i) {

                cone[i][j] = 1;
            }
        }
    }

    // =====================================================
    // HABILIDADE CRUZ
    //
    // aqui o centro fica preenchido
    // tanto na vertical quanto horizontal
    // =====================================================

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            if (i == 2 || j == 2) {

                cruz[i][j] = 1;
            }
        }
    }

    // =====================================================
    // HABILIDADE OCTAEDRO
    //
    // aqui tentei fazer um formato de losango
    // =====================================================

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            // distância do centro da matriz

            if ((i + j >= 2) &&
                (i + j <= 6) &&
                (i - j <= 2) &&
                (j - i <= 2)) {

                octaedro[i][j] = 1;
            }
        }
    }

    // =====================================================
    // pontos de origem das habilidades
    // aqui escolhi manualmente no tabuleiro
    // =====================================================

    int origemConeLinha = 2;
    int origemConeColuna = 2;

    int origemCruzLinha = 6;
    int origemCruzColuna = 2;

    int origemOctaedroLinha = 6;
    int origemOctaedroColuna = 6;

    // =====================================================
    // aplicando a habilidade CONE no tabuleiro
    // posições afetadas vão virar 5
    // =====================================================

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            int linhaTabuleiro = origemConeLinha + i - 2;
            int colunaTabuleiro = origemConeColuna + j - 2;

            // verificando limites do tabuleiro

            if (linhaTabuleiro >= 0 &&
                linhaTabuleiro < 10 &&
                colunaTabuleiro >= 0 &&
                colunaTabuleiro < 10) {

                if (cone[i][j] == 1) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }

    // =====================================================
    // aplicando habilidade CRUZ
    // =====================================================

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            int linhaTabuleiro = origemCruzLinha + i - 2;
            int colunaTabuleiro = origemCruzColuna + j - 2;

            if (linhaTabuleiro >= 0 &&
                linhaTabuleiro < 10 &&
                colunaTabuleiro >= 0 &&
                colunaTabuleiro < 10) {

                if (cruz[i][j] == 1) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }

    // =====================================================
    // aplicando habilidade OCTAEDRO
    // =====================================================

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            int linhaTabuleiro = origemOctaedroLinha + i - 2;
            int colunaTabuleiro = origemOctaedroColuna + j - 2;

            if (linhaTabuleiro >= 0 &&
                linhaTabuleiro < 10 &&
                colunaTabuleiro >= 0 &&
                colunaTabuleiro < 10) {

                if (octaedro[i][j] == 1) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }

    // =====================================================
    // mostrando o tabuleiro final
    //
    // 0 = água
    // 3 = navio
    // 5 = habilidade
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