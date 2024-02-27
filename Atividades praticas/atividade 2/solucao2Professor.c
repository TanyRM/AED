#include <stdio.h>
#include <stdlib.h>
#include <time.h> // para srand() e time()

// Estrutura para representar um jogador
typedef struct {
    int id;
    int pontos;
} Jogador;

// Função para criar a matriz com as especificações dadas
int **criarMatriz(int qtdLinhas, int qtdColunas) {
    int **matriz;
    int i, j;

    // Alocar memória para as linhas
    matriz = (int **)malloc(qtdLinhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para as linhas.\n");
        exit(1);
    }

    // Alocar memória para as colunas de cada linha
    for (i = 0; i < qtdLinhas; i++) {
        matriz[i] = (int *)malloc(qtdColunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para as colunas.\n");
            exit(1);
        }
    }

    // Preencher a matriz com os valores adequados (ID da linha na primeira coluna e pontos aleatórios nas demais)
    for (i = 0; i < qtdLinhas; i++) {
        matriz[i][0] = i + 1; // ID da linha
        for (j = 1; j < qtdColunas; j++) {
            matriz[i][j] = rand() % 11; // Pontos aleatórios de 0 a 10
        }
    }

    return matriz;
}

// Função para liberar a memória alocada para a matriz
void liberarMatriz(int **matriz, int qtdLinhas) {
    int i;
    for (i = 0; i < qtdLinhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Função para trocar duas linhas da matriz
void trocarLinhas(int **matriz, int linha1, int linha2, int qtdColunas) {
    int *temp = matriz[linha1];
    matriz[linha1] = matriz[linha2];
    matriz[linha2] = temp;
}

// Função para ordenar a matriz com base na quantidade total de pontos e no ID em caso de empate
void ordenarMatriz(int **matriz, int qtdLinhas, int qtdColunas) {
    int i, j;

    for (i = 0; i < qtdLinhas - 1; i++) {
        for (j = 0; j < qtdLinhas - i - 1; j++) {
            int pontos1 = 0, pontos2 = 0;
            for (int k = 1; k < qtdColunas; k++) {
                pontos1 += matriz[j][k];
                pontos2 += matriz[j + 1][k];
            }

            if (pontos1 < pontos2 || (pontos1 == pontos2 && matriz[j][0] < matriz[j + 1][0])) {
                trocarLinhas(matriz, j, j + 1, qtdColunas);
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Inicializar a semente do gerador de números aleatórios com o tempo atual

    int qtdLinhas, qtdColunas;
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &qtdLinhas);
    printf("Digite o número de colunas da matriz (incluindo a coluna de ID): ");
    scanf("%d", &qtdColunas);

    // Criar a matriz
    int **matriz = criarMatriz(qtdLinhas, qtdColunas);

    // Exibir a matriz antes da ordenação
    printf("\nMatriz antes da ordenacao:\n");
    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Calcular e exibir a quantidade total de pontos por jogador
    printf("\nQuantidade total de pontos por jogador:\n");
    for (int i = 0; i < qtdLinhas; i++) {
        int totalPontos = 0;
        for (int j = 1; j < qtdColunas; j++) {
            totalPontos += matriz[i][j];
        }
        printf("Jogador %d: %d pontos\n", matriz[i][0], totalPontos);
    }

    // Ordenar a matriz
    ordenarMatriz(matriz, qtdLinhas, qtdColunas);

    // Exibir a matriz ordenada
    printf("\nMatriz ordenada:\n");
    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar memória alocada para a matriz
    liberarMatriz(matriz, qtdLinhas);

    return 0;
}
