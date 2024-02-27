#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 1000

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

void merge(int vetor[], int inicio, int meio, int fim) {
    int com1 = inicio, com2 = meio+1, comAux = 0, vetAux[fim-inicio+1];
    while(com1<=meio && com2<=fim) {
        if(vetor[com1] <= vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } 
        else {
            vetAux[comAux] = vetor[com2];
            com2++; 
        }
    comAux++; 
    }
    while(com1<=meio) { //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;com1++; 
        }
    while(com2<=fim) { //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;com2++; 
        }
    for(comAux=inicio;comAux<=fim;comAux++) { 
        vetor[comAux] = vetAux[comAux-inicio];
    }
}

void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio+fim)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;
    int j;

    for (j = inicio; j <= fim - 1; j++) {
        if (vetor[j] < pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[fim]);
    return (i + 1);
}

void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int indiceParticao = particionar(vetor, inicio, fim);

        quickSort(vetor, inicio, indiceParticao - 1);
        quickSort(vetor, indiceParticao + 1, fim);
    }
}

void countingSort(int vetor[], int n, int k) {
    int i, j;
    int c[k + 1], b[n];

    for (i = 0; i <= k; i++) {
        c[i] = 0;
    }

    for (j = 0; j < n; j++) {
        c[vetor[j]]++;
    }

    for (i = 1; i <= k; i++) {
        c[i] += c[i - 1];
    }

    for (j = n - 1; j >= 0; j--) {
        b[--c[vetor[j]]] = vetor[j];
    }

    for (i = 0; i < n; i++) {
        vetor[i] = b[i];
    }
}

void radixSort(int vetor[], int n, int d){
    int i;
    int max = vetor[0];
    for (i = 1; i < n; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }
    for (i=1; i<=d; i++){
        countingSort(vetor, n, max);
    }
}

void inserir(int bucket[], int valor, int* tam_bucket) {
    bucket[*tam_bucket] = valor;
    (*tam_bucket)++;
}

void concatenar(int A[], int buckets[][TAMANHO], int tam_bucket) {
    int idx = 0;
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < tam_bucket; j++) {
            if (buckets[i][j] != -1) {
                A[idx++] = buckets[i][j];
            } else {
                break; // Encerra o loop quando encontrar o final do balde
            }
        }
    }
}

void bucketSort(int vetor[], int n) {
    int buckets[TAMANHO][TAMANHO];
    int tam_bucket = 0;
    int i, j, indice;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < TAMANHO; j++) {
            buckets[i][j] = -1;
        }
    }
    for (i = 0; i < n; i++) {
        indice = vetor[i] / (9 + 1);
        inserir(buckets[indice], vetor[i], &tam_bucket);
    }
    for (i = 0; i < 9; i++) {
        insertionSort(buckets[i]);
    }
    concatenar(vetor, buckets, n);
}


int main(){
    int vetor[TAMANHO];
    int i, j=TAMANHO;

    srand(time(NULL));

    for (i=0; i<TAMANHO; i++) {
        vetor[i] = j;
        printf("%d ", vetor[i]);
        j--;
    }
    printf("\n");

    int op;
    printf("Selecione uma opção:\n 1- Bubble\n 2- Selection\n 3- Insertion\n 4- Merge\n 5- Quick\n 6- Counting\n 7- Radix\n 8- Bucket\n");
    scanf("%d", &op);

    clock_t inicio, fim;
    double tempo;

    inicio = clock();
    switch (op) {
    case 1:
        bubbleSort(vetor);
        break;
    case 2:
        selectionSort(vetor);
        break;
    case 3:
        insertionSort(vetor);
        break;
    case 4:
        mergeSort(vetor, 0, TAMANHO);
        break;
    case 5:
        quickSort(vetor, 0, TAMANHO-1);
        break;
    case 6:
        countingSort(vetor, TAMANHO, TAMANHO);
        break;
    case 7:
        radixSort(vetor, TAMANHO, 3);
        break;
    // case 8 com BucketSort não funciona
    case 8:
        printf("Chamando bucketSort...\n");
        bucketSort(vetor, TAMANHO);
        printf("bucketSort concluído.\n");
        break;
    default:
        break;
    }
    fim = clock();

    tempo = ((double)(fim - inicio))/CLOCKS_PER_SEC;

    for(i = 0; i < TAMANHO; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\nTempo de execução: %f segundos\n", tempo);

    return 0; 
}