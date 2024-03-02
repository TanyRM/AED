#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct estrutura {
    int atributo1;
    int atributo2;
} Estrutura;

typedef struct pilha {
    Estrutura elementos[TAM];
    int n;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->n = 0;
}

int estaCheia(Pilha *p) {
    return (p->n == TAM) ? 1 : 0;
}

void empilhar(Pilha *p, Estrutura elemento) {
    if (!(estaCheia(p))) {
        p->elementos[p->n] = elemento;
        p->n++;
    } else {
        printf("Não é possível empilhar mais elementos!\n");
    }
}

int estaVazia(Pilha *p) {
    return (p->n == 0) ? 1 : 0;
}

void desempilhar(Pilha *p) {
    if (!(estaVazia(p))) {
        p->n--;
        printf("Topo: (%d, %d)\n", p->elementos[p->n].atributo1, p->elementos[p->n].atributo2);
    } else {
        printf("A pilha está vazia!\n");
    }
}

void imprimirPilha(Pilha *p) {
    int i;
    printf("[");
    for (i = 0; i < p->n; i++) {
        printf(" (%d, %d)", p->elementos[i].atributo1, p->elementos[i].atributo2);
    }
    printf("]\n");
}

Estrutura verTopo(Pilha *p) {
    if (!(estaVazia(p))) {
        return p->elementos[p->n - 1];
    } else {
        printf("A pilha está vazia!\n");
        Estrutura elementoDefault = {-1, -1}; 
        return elementoDefault;
    }
}

int main() {
    Pilha pilha;
    int i;

    inicializarPilha(&pilha);

    Estrutura elemento1 = {1, 2};
    empilhar(&pilha, elemento1);

    Estrutura elemento2 = {2, 3};
    empilhar(&pilha, elemento2);

    Estrutura elemento3 = {3, 4};
    empilhar(&pilha, elemento3);

    Estrutura elemento4 = {4, 5};
    empilhar(&pilha, elemento4);

    Estrutura elemento5 = {5, 6};
    empilhar(&pilha, elemento5);

    imprimirPilha(&pilha);

    if (estaCheia(&pilha)) {
        printf("A pilha está cheia\n");
    }

    printf("Topo: (%d, %d)\n", verTopo(&pilha).atributo1, verTopo(&pilha).atributo2);

    for (i = TAM; i >= 1; i--) {
        desempilhar(&pilha);
    }

    if (estaVazia(&pilha)) {
        printf("A pilha está vazia\n");
    }

    imprimirPilha(&pilha);

    Estrutura elemento6 = {6, 1};
    empilhar(&pilha, elemento6);

    Estrutura elemento7 = {7, 2};
    empilhar(&pilha, elemento7);

    Estrutura elemento8 = {8, 3};
    empilhar(&pilha, elemento8);

    Estrutura elemento9 = {9, 4};
    empilhar(&pilha, elemento9);

    Estrutura elemento10 = {10, 5};
    empilhar(&pilha, elemento10);

    imprimirPilha(&pilha);

    return 0;
}
