#include <stdio.h>

int main() {
    // Definição de um vetor com 10 elementos cujos valores são os números de 0 a 9
    int vetor[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, temp;

    // Loop para inverter a ordem dos valores dentro do vetor
    for (i = 0; i < 5; i++) {
        temp = vetor[i];
        vetor[i] = vetor[9 - i];
        vetor[9 - i] = temp;
    }

    // Print para mostrar o vetor com os elementos na nova ordem (inversa)
    printf("Vetor invertido:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Novo código para inserir de um vetor de tamanho n
    int n;
    
    // Pede o tamanho do vetor desejado
    printf("\nInsira o tamanho do vetor desejado: ");
    scanf("%d", &n);
    
    int novoVetor[n]; // Define o novo vetor com o tamanho especificado pelo usuário
    
    // Recebe os elementos do vetor do usuário
    printf("Insira os elementos do vetor: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &novoVetor[i]);
    }
    
    // Inverte a ordem dos valores dentro do vetor de tamanho n
    for (i = 0; i < n / 2; i++) {
        temp = novoVetor[i];
        novoVetor[i] = novoVetor[n - 1 - i];
        novoVetor[n - 1 - i] = temp;
    }
    
    // Print para mostrar o novo vetor com os elementos na ordem inversa
    printf("\nVetor invertido:");
    for (i = 0; i < n; i++) {
        printf(" %d", novoVetor[i]);
    }
    printf("\n");

    return 0;
}

