#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct pilha{
    int elementos[TAM];
    int n;
} Pilha;

void inicializarPilha(Pilha *p){
    p->n = 0;
}

int estaCheia(Pilha *p){
    return (p->n == TAM) ? 1 : 0;
}

void empilhar(Pilha *p, int elemento){
    if(!(estaCheia(p))){
        p->elementos[p->n] = elemento;
        p->n++;
    } else {
        printf("Não é possível empilhar mais elementos!\n");
    }
}

int estaVazia(Pilha *p){
    return (p->n == 0) ? 1 : 0;
}

void desempilhar(Pilha *p){
    if(!(estaVazia(p))){
        p->n--;
        printf("Topo: %d\n", p->elementos[p->n]);
    } else {
        printf("A pilha está vazia!\n");
    }
}

void imprimirPilha(Pilha *p){
    int i;
    printf("[");
    for(i=0; i<p->n; i++){
        printf(" %d", p->elementos[i]);
    }
    printf("]\n");
}

void imprimirRecursivo(Pilha *p) {
    if (p->n > 0) { 
        int topo = p->elementos[p->n - 1]; 
        p->n--; 
        if (p->n == 0) { 
            printf("%d", topo); 
        } else {
            imprimirRecursivo(p); 
            printf(" %d", topo); 
        }
        p->n++; 
    }
}


int verTopo(Pilha *p){
    if(!(estaVazia(p))){
        return p->elementos[p->n];
    } else {
        printf("A pilha está vazia!\n");
        return -1;
    }
}

int main () {
    Pilha pilha;
    int i;

    inicializarPilha(&pilha);

    for (i=1; i<=TAM; i++){ 
        empilhar(&pilha, i);
    }

    imprimirPilha(&pilha);

    if(estaCheia(&pilha)){
        printf("A pilha está cheia\n");
    }

    printf("Topo: %d\n", verTopo(&pilha));

    for (i=TAM; i>=1; i--){ 
        desempilhar(&pilha);
    }

    if(estaVazia(&pilha)){
        printf("A pilha está vazia\n");
    }

    imprimirPilha(&pilha);

    for (i=TAM; i>=1; i--){ 
        empilhar(&pilha, i);
    }

    imprimirPilha(&pilha);

    imprimirRecursivo(&pilha);

    return 0;
}