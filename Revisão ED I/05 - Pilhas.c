#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 3

int* pilha;
int topo = -1;
int capacidade = INITIAL_SIZE;

// Função para verificar se a pilha está vazia
int isEmpty() {
    return topo == -1;
}

// Função para expandir a capacidade da pilha
void expandCapacity() {
    capacidade *= 2; // Dobra a capacidade
    pilha = realloc(pilha, capacidade * sizeof(int)); // Realoca a pilha com o dobro do tamanho
    if (pilha == NULL) {
        printf("Erro ao expandir a pilha!\n");
        exit(1); // Encerra o programa em caso de falha
    }
    printf("Capacidade da pilha expandida para %d.\n", capacidade);
}

// Função para inserir um elemento na pilha
void push(int elemento) {
    if (topo == capacidade - 1) { // Se a pilha estiver cheia, expande a capacidade
        expandCapacity();
    }
    pilha[++topo] = elemento;
}

// Função para remover um elemento da pilha
int pop() {
    if (isEmpty()) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo--];
    }
}

// Função para retornar o elemento no topo da pilha
int top() {
    if (isEmpty()) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo];
    }
}

// Função para imprimir os elementos da pilha
void imprimir() {
    if (isEmpty()) {
        printf("Pilha vazia!\n");
        return;
    }
    
    printf("Conteúdo da pilha:\n");
    for (int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}

int main() {
    // Aloca memória inicial para a pilha
    pilha = (int*)malloc(capacidade * sizeof(int));
    if (pilha == NULL) {
        printf("Erro ao alocar memória para a pilha!\n");
        return 1;
    }

    // Teste de inserção e expansão da pilha
    push(10);
    push(20);
    push(30);
    imprimir();
    
    push(40); // Este push irá expandir a capacidade da pilha
    push(50);
    imprimir();

    // Testando operações de topo e remoção
    printf("Elemento no topo: %d\n", top());
    printf("Elemento removido: %d\n", pop());
    imprimir();

    // Libera a memória alocada para a pilha
    free(pilha);

    return 0;
}

