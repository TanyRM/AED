#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 10
#define RANGE_NUMEROS 100

void bubble_sort(unsigned long long int *vetor){
    unsigned long long int i, j, aux;
    int cont = 0;
    for(i = 0; i < TAMANHO_VETOR - 1; i++){
        for(j = 0; j < TAMANHO_VETOR - i - 1; j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
            cont++; // Contabilizando cada comparação
        }
    }
    printf("%d\n", cont);
}

void bubble_sort_otimizado(unsigned long long int *vetor){
    unsigned long long int i, j, aux; 
    int trocas = 0, cont = 0;
    for(i = 0; i < TAMANHO_VETOR - 1; i++){
        trocas = 0;
        for(j = 0; j < TAMANHO_VETOR - i - 1; j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                trocas++;
            }
            cont++; // Contabilizando cada comparação
        }
        if (trocas == 0){
            break;
        }
    }
    printf("%d\n", cont);
}

int main(){
    unsigned long long int vetor1[TAMANHO_VETOR], vetor2[TAMANHO_VETOR];
    int i;

    srand(time(NULL));

    for (i=0; i<TAMANHO_VETOR; i++) {
        vetor1[i] = rand() % RANGE_NUMEROS;
        vetor2[i] = vetor1[i];
    }

    bubble_sort(vetor1);
    bubble_sort_otimizado(vetor2);

    return 0;
}