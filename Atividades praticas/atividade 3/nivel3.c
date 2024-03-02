#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10
#define TAMANHO_MAXIMO 100 // Tamanho máximo de cada string

typedef struct navegacao {
    char *enderecos[TAM];
    int n;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->n = 0;
}

int estaCheia(Pilha *p) {
    return (p->n == TAM) ? 1 : 0;
}

void novaPagina(Pilha *p, char *link) {
    int i;
    if (!(estaCheia(p))) {
        p->enderecos[p->n] = strdup(link); // Copia a string
        p->n++;
    } else {
        for (i = 0; i < p->n - 1; i++) {
            free(p->enderecos[i]);
            p->enderecos[i] = p->enderecos[i + 1];
        }
        free(p->enderecos[p->n - 1]); 
        p->enderecos[p->n - 1] = strdup(link); 
    }
}

int estaVazia(Pilha *p) {
    return (p->n == 0) ? 1 : 0;
}

void voltar(Pilha *p) {
    if (!(estaVazia(p))) {
        p->n--;
    } else {
        printf("Não é possível voltar!\n");
    }
}

void historico(Pilha *p) {
    int i;
    printf("\nHistorico:\n");
    for (i = 0; i < p->n; i++) {
        printf(" %s\n", p->enderecos[i]);
    }
    printf("\n");
}

char* verAtual(Pilha *p) {
    if (!(estaVazia(p))) {
        return p->enderecos[p->n - 1];
    } else {
        printf("Não é possível voltar!\n");
        return NULL;
    }
}

int main() {
    Pilha navegacao;
    int i;

    inicializarPilha(&navegacao);

    novaPagina(&navegacao, "https://www.pagina1.com");
    novaPagina(&navegacao, "https://www.pagina2.com");
    novaPagina(&navegacao, "https://www.pagina3.com");

    historico(&navegacao);

    printf("Atual: %s\n", verAtual(&navegacao));

    voltar(&navegacao);
    printf("Atual: %s\n", verAtual(&navegacao));

    if (estaVazia(&navegacao)) {
        printf("Não é possível voltar!\n");
    }

    historico(&navegacao);

    return 0;
}
