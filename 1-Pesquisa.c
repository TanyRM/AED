
//Algoritmos de Pesquisa (sequencial e binária)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 100

// Função para preencher o vetor com valores aleatórios entre 1 e 100.
void preencherVetor(int vetor[]) {
    srand(time(NULL));
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        vetor[i] = rand() % 100 + 1;
    }
}

// Função para ordenar o vetor usando o algoritmo Bubble Sort.
void bubbleSort(int vetor[]) {
    for (int i = 0; i < TAMANHO_VETOR - 1; i++) {
        for (int j = 0; j < TAMANHO_VETOR - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos se estiverem fora de ordem.
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Função para realizar uma busca sequencial no vetor.
int buscaSequencial(int vetor[], int elemento) {
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        if (vetor[i] == elemento) {
            return i;
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado.
}

// Função para realizar uma busca binária no vetor (requer que o vetor esteja ordenado).
int buscaBinaria(int vetor[], int elemento) {
    int esquerda = 0;
    int direita = TAMANHO_VETOR - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;

        if (vetor[meio] == elemento) {
            return meio;
        } else if (vetor[meio] < elemento) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado.
}

int main() {
    int vetor[TAMANHO_VETOR];
    preencherVetor(vetor);

    printf("Vetor gerado aleatoriamente:\n");
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    int escolha = 0;
    int elemento;
    int posicao;

    while (escolha != -1) {
        printf("Escolha o tipo de busca (1 - Sequencial, 2 - Binária, -1 - Parar): ");
        scanf("%d", &escolha);

        if (escolha == -1) {
            break;
        } else if (escolha != 1 && escolha != 2) {
            printf("Opção inválida.\n");
            continue;
        }

        printf("Digite o elemento a ser buscado: ");
        scanf("%d", &elemento);

        if (escolha == 2) {
            // Antes de usar busca binária, o vetor precisa estar ordenado.
            bubbleSort(vetor);
            
            printf("O vetor foi ordenado:\n");
            for (int i = 0; i < TAMANHO_VETOR; i++) {
                printf("%d ", vetor[i]);
            }
            printf("\n");
        }

        if (escolha == 1) {
            posicao = buscaSequencial(vetor, elemento);
        } else {
            posicao = buscaBinaria(vetor, elemento);
        }

        if (posicao != -1) {
            printf("Elemento encontrado na posição %d do vetor.\n", posicao);
        } else {
            printf("Elemento não encontrado no vetor.\n");
        }
    }

    return 0;
}
