#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int pontuacoes[], int ids[], int tamanho){
    int i, fim, aux;
    for (fim = tamanho-1; fim > 0; fim--) {
        for (i = 0; i < fim; ++i) {
            // Se a pontuação for maior, ou se as pontuações forem iguais e o ID for maior
            if (pontuacoes[i] > pontuacoes[i+1] || (pontuacoes[i] == pontuacoes[i+1] && ids[i] < ids[i+1])) {
                // Troca as pontuações
                aux = pontuacoes[i];
                pontuacoes[i] = pontuacoes[i+1];
                pontuacoes[i+1] = aux;
                // Troca os IDs correspondentes
                aux = ids[i];
                ids[i] = ids[i+1];
                ids[i+1] = aux;
            }
        }
    }
}

int main(){
    int n, i, j, id, pontuacao, total;

    printf("Digite o numero de competidores: ");
    scanf("%d", &n);

    if (n > 1 && n < 1000){
        int *pontuacoes = malloc(n * sizeof(int));
        int *ids = malloc(n * sizeof(int));

        for (i = 0; i < n; i++){
            scanf("%d", &id);
            ids[i] = id;
            total = 0;
            
            for (j = 0; j < 10; j++){
                scanf("%d", &pontuacao);
                if (pontuacao == -1){
                    break;
                } else  {
                    total += pontuacao;
                }
            }
            printf("%d- %d\n", id, total);
            pontuacoes[i] = total;
        }

        bubbleSort(pontuacoes, ids, n);

        for (i = 0; i < n; i++){
            printf("%d\n", ids[i]);
        }

        free(pontuacoes);
        free(ids);
    } else {
        printf("Número de competidores inválido\n");
    }

    return 0;
}
