#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

void bubbleSort(int vetor[]){
    int i, fim, aux;

    for (fim = TAMANHO-1; fim > 0; fim--) {
        for (i = 0; i < fim; ++i) {
            if (vetor[i] > vetor[i+1]) {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }
}

void selectionSort(int vetor[]){
    int i, j, min, aux;

    for (i = 0; i < (TAMANHO-1); i++) {
        min = i;

        for (j = (i+1); j < TAMANHO; j++) {
            if(vetor[j] < vetor[min])
            min = j;
        }

        if (vetor[i] != vetor[min]) {
        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
    }
}

}

void insertionSort(int vetor[]){
    int i= 0, j= 1, aux = 0;

    while (j < TAMANHO) {
        aux = vetor[j];
        i = j - 1;
        
        while ((i >= 0) && (vetor[i] > aux)) {
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }

        vetor[i + 1] = aux;
        j = j + 1;
    }
}

int main(){
    int vetor[TAMANHO] = {7,3,9,5,4,8,1,2,6,0};

   return 0; 
}