#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estrutura da fila
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Função para criar uma fila
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Falha na alocação de memória para a fila.\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

// Função para adicionar um novo nó
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Falha na alocação de memória para o novo nó.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Função para remover um nó
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Fila está vazia.\n");
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Função para conferir se a fila está vazia
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Função para imprimir os elementos da fila
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front;
    printf("Elementos da fila: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função para contar o número de elementos na fila
void countQueue(Queue* q) {
    Node* temp = q->front;
    int contador = 0;

    while (temp != NULL) {
        contador += 1;
        temp = temp->next;
    }

    printf("Número de elementos na fila: %d\n", contador);
}

// Função para limpar todos os elementos da fila
void clearQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    printf("Fila limpa com sucesso.\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);

    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);

    enqueue(q, 40);
    enqueue(q, 50);
    printQueue(q);

    countQueue(q);
    clearQueue(q);
    printQueue(q);

    return 0;
}

