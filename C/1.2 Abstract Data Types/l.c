#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definição da estrutura da lista
typedef struct List {
    Node* head;
    Node* tail;
    Node* curr;
    int count;          // tamanho da lista
} List;

// Função para criar um novo nó
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Função para criar uma nova lista
List* creat_list() {
    List* l = (List*)malloc(sizeof(List));
    if (!l) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
    l->head = l->tail = l->curr = NULL;
    l->count = 0;
    return l;
}

// Função para inserir um novo elemento na lista encadeada
void insert(List* l, int data) {
    Node* new_node = create_node(data);
    if (l->head == NULL) { // Se a lista estiver vazia
        l->head = l->tail = new_node;
    } else {
        l->tail->next = new_node;
        l->tail = new_node;
    }
    l->count++;
}

// Função para mover o cursor para o final da lista
void movecurr(List* l) {
    l->curr = l->tail;
}

// Função para mover o cursor para o início da lista
void move_to_start(List* l) {
    l->curr = l->head;
}

// Função para remover o primeiro elemento da lista encadeada
int del(List* l) {
    if (l->head == NULL) {
        return -1; // A lista está vazia
    }
    Node* temp = l->head;
    int data = temp->data;
    l->head = l->head->next;
    if (l->head == NULL) { // Se a lista ficou vazia após a remoção
        l->tail = NULL;
    }
    free(temp);
    l->count--;
    return data;
}

// Função para imprimir os elementos da lista encadeada
void printlist(List* l) {
    Node* current = l->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Função para liberar a memória alocada para os nós da lista encadeada
void clear(List* l) {
    Node* current = l->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(l);
}

int main() {
    int x = 3;
    int y = 0;
    List* l = creat_list();
    
    insert(l, 10);
    insert(l, 20);
    movecurr(l);
    insert(l, x);
    move_to_start(l);
    y = del(l);
    printf("%d\n", y);
    insert(l, 89);
    printlist(l);
    clear(l);
    return 0;
}
