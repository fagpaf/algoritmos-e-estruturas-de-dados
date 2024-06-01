#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>

typedef struct Node {
    int element;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Funções
Node* create_node(int num);
Queue* create_queue();
void enqueue(Queue* q, int num);
int dequeue(Queue* q);
void clear(Queue* q);
int length(Queue* q);
int front_value(Queue* q);


Node* create_node(int num) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->element = num;
    n->next = NULL;
    return n;
}

Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue* q, int num) {
    Node* new_node = create_node(num);
    if (q->rear == NULL) {
        q->front = new_node;
    } else {
        q->rear->next = new_node;
    }
    q->rear = new_node;
    q->size++;
}

int dequeue(Queue* q){

    if (q -> size == 0){ // Erro
        return -1;
    }
    Node* temp = q -> front; // Criando um nó temporário para mostrar qual nó será removido da Fila (Usabilidadde de código e leitura)
    
    int num = temp -> element;
    q -> front = q -> front -> next;
    free(temp);
    q -> size--;

    if (q -> front == NULL){
        q -> rear = NULL;
    }

    return num;
}

void clear(Queue* q) {
    while (q->front != NULL) {
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

int length(Queue* q) {
    return q->size;
}

int front_value(Queue* q){
    int num = q->front->element;
    return num;
}

#endif //QUEUE_H