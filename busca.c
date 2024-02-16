#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 30000
#define RANGE_NUMEROS 50000

void bubbleSort(int vetor[]) {
    int i, j;
    for (i = 0; i < TAMANHO_VETOR - 1; i++) {
        for (j = 0; j < TAMANHO_VETOR - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos se estiverem fora de ordem.
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int buscaLinear(int vetor[], int valor){
    int i;

    for (i=0; i<TAMANHO_VETOR; i++) {
        if (vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int vetor[], int valor){
    int ini=0, fim=TAMANHO_VETOR-1, meio;

    while (ini <= fim){
        meio = (ini+fim)/2;

        if (vetor[meio] == valor) {
            return meio;
        } 
        else if (vetor[meio] < valor) {
            ini = meio + 1;
        } 
        else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    int tamanhoVetor[TAMANHO_VETOR], usados[RANGE_NUMEROS]={0};
    int posicao, valor, i, num;
    char op;
    clock_t inicio, fim;
    double tempo;

    srand(time(NULL));

    for (i=0; i<TAMANHO_VETOR; i++) {
        do {
            num = rand() % RANGE_NUMEROS;
        } while (usados[num]);

        tamanhoVetor[i] = num;
        usados[num] = 1;
    }

    for (i = 0; i<20; i++) {
        printf("%d ", tamanhoVetor[i]);
    }
    printf("\n");

    bubbleSort(tamanhoVetor);

    for (i = 0; i<20; i++) {
        printf("%d ", tamanhoVetor[i]);
    }
    printf("\n");

    do {
        printf("Digite qual o numero quer procurar: ");
        scanf("%d", &valor);

        inicio = clock();
        posicao = buscaLinear(tamanhoVetor, valor);
        fim = clock();
        tempo = ((double)(fim - inicio))/CLOCKS_PER_SEC;

        if (posicao == -1) {
            printf("\nNumero nao encontrado\n");
        }
        else {
            printf("\nPosicao: %d\n", posicao);
        }
        printf("Tempo de execução: %f segundos\n\n", tempo);


        inicio = clock();
        posicao = buscaBinaria(tamanhoVetor, valor);
        fim = clock();
        tempo = ((double)(fim - inicio))/CLOCKS_PER_SEC;

        if (posicao == -1) {
            printf("Numero nao encontrado\n");
        }
        else {
            printf("\nPosicao: %d\n", posicao);
        }
        printf("Tempo de execução: %f segundos\n\n", tempo);

        printf("Deseja procurar outro numero? ");
        scanf(" %c", &op);
        scanf("%*c");

    } while (op != 'n');

    printf("Programa encerrado.\n");
    return 0;
}