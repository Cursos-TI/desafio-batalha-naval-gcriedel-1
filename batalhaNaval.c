// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Objetivo: Batalha Naval - Tema 1 - Desafio Nível Novato - Modulo 5

#include <stdio.h>
int main() {

    // =====================================================
    // criando o tabuleiro 10x10
    // vou usar uma matriz pra representar o mapa do jogo
    // tudo começa como água (0)
    // =====================================================

    int tabuleiro[10][10];

    // preenchendo tudo com 0 (água mesmo)

    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 10; j++) {

            tabuleiro[i][j] = 0;
        }
    }

    // =====================================================
    // criando os navios
    // cada navio vai ter tamanho 3
    // aqui a gente só marca eles como "3"
    // =====================================================

    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3]   = {3, 3, 3};

    // =====================================================
    // posicionamento dos navios
    // escolhi manualmente as coordenadas aqui
    // (sem input do usuário pra simplificar)
    // =====================================================

    // navio horizontal (linha fixa, coluna varia)
    int linhaH = 2;
    int colunaH = 3;

    // navio vertical (coluna fixa, linha varia)
    int linhaV = 5;
    int colunaV = 7;

    // =====================================================
    // colocando o navio horizontal no tabuleiro
    // cuidado pra não sair fora da matriz
    // =====================================================

    for (int i = 0; i < 3; i++) {

        // aqui é tipo: mesma linha, mudando colunas
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // =====================================================
    // colocando o navio vertical no tabuleiro
    // aqui muda a linha e a coluna fica fixa
    // =====================================================

    for (int i = 0; i < 3; i++) {

        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // =====================================================
    // exibindo o tabuleiro
    // aqui uso loops aninhados pra imprimir tudo bonitinho
    // =====================================================

    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 10; j++) {

            // só pra ficar mais legível na tela
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    // =====================================================
    // fim do programa
    // aqui já tá tudo montado e exibido
    // =====================================================

    return 0;
}