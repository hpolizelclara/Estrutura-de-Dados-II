#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matriz;
    int i, j;
    int soma = 0;
    int tamanho;
    
    printf("Insira a dimensão da matriz quadrada: ");
    scanf("%d", &tamanho);
    
    // Alocação malloc que permite a dinamização da dimensão da matriz
    matriz = (int **)malloc(tamanho * sizeof(int *));
    
    for (i = 0; i < tamanho; i++){
        matriz[i] = (int *)malloc(tamanho * sizeof(int));
    }
    
    printf("Insira os elementos da matriz:\n");
    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            scanf("%d", &matriz[i][j]);
            
            if (i == j) {
                soma += matriz[i][j];
            }
        }
    }

    printf("Soma dos elementos da diagonal principal: %d\n", soma);
    
    // Liberação da memória 
    for (i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }
    free(matriz);
    
    return 0;
}
