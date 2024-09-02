#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó 
typedef struct Node {
    int data;           
    struct Node* next;  
    struct Node* prev;
} Node;

Node* head = NULL;

// Função para inserir um novo nó no início da lista
void insertFront(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value; 
    newNode->next = head;  
    newNode->prev = NULL;  

    if (head != NULL)
        head->prev = newNode; 
        
    head = newNode; 
}

// Função para deletar um nó na lista
void deleteNode(Node* node) {
    if (node == head) 
        head = node->next; 
        
    if (node->next != NULL)
        node->next->prev = node->prev;
        
    if (node->prev != NULL)
        node->prev->next = node->next;  

    free(node);
}

// Função para imprimir os elementos da lista
void printList() {
    Node* temp = head;
    while (temp != NULL) { 
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função para buscar um valor na lista
Node* searchNode(int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Valor %d encontrado.\n", value);
            if (temp->prev != NULL) 
                printf("Vizinho anterior: %d\n", temp->prev->data);
            else 
                printf("Não há vizinho anterior (nó é o primeiro).\n");

            if (temp->next != NULL)
                printf("Vizinho próximo: %d\n", temp->next->data);
            else
                printf("Não há vizinho próximo (nó é o último).\n");
            return temp; 
        }
        temp = temp->next;
    }
    printf("Valor %d não encontrado na lista.\n", value);
    return NULL; 
}

// Função para inserir múltiplos valores na lista
void insertMultiple(int n) {
    int value;
    for (int i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &value);
        insertFront(value);
    }
}

int main() {
    int n;
    printf("Quantos valores você deseja inserir? ");
    scanf("%d", &n);
    insertMultiple(n);

    printList();
    
    int searchValue;
    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &searchValue);
    searchNode(searchValue);

    return 0;
}

