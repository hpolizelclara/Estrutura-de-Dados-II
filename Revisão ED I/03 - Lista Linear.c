#include <stdio.h>
#define MAX_SIZE 10

int lista[MAX_SIZE];
int tamanho = 0;

void inserir(int elemento) {
    if (tamanho < MAX_SIZE) {
        lista[tamanho++] = elemento;
    } else {
        printf("Lista cheia!\n");
    }
}

void remover(int index) {
    if (index < 0 || index >= tamanho) {
        printf("Índice inválido!\n");
    } else {
        for (int i = index; i < tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    }
}

void imprimir() {
    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int buscar(int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == elemento) {
            printf("O elemento %d está na posição %d.\n", elemento, i + 1);
            return i; // Retorna a posição do elemento
        }
    }
    printf("Elemento %d não encontrado na lista.\n", elemento);
    return -1; // Retorna -1 se o elemento não for encontrado
}

void maxeMin() {
    if (tamanho == 0) {
        printf("Lista vazia!\n");
        return;
    }

    int max = lista[0];
    int min = lista[0];

    for (int i = 1; i < tamanho; i++) {
        if (lista[i] > max) {
            max = lista[i];
        }
        if (lista[i] < min) {
            min = lista[i];
        }
    }

    printf("Valor máximo: %d\n", max);
    printf("Valor mínimo: %d\n", min);
}

int main() {
    inserir(10);
    inserir(20);
    inserir(30);
    imprimir();
    maxeMin();
    buscar(10);
    remover(1);
    imprimir();
    maxeMin();
    inserir(40);
    imprimir();
    maxeMin();
    
    return 0;
}

