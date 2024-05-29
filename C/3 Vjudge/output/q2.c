#include <stdio.h>
#include <stdlib.h>

// Definição das estruturas de nó e fila
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
void clear_queue(Queue* q);
int queue_length(Queue* q);
void print_queue(Queue* q);

int main() {
    Queue* q = create_queue();
    int test_cases, num_students;
    
    if (scanf("%d %d", &test_cases, &num_students) != 2) {
        fprintf(stderr, "Erro na leitura do número de testes e estudantes.\n");
        return 1;
    }
    
    for (int i = 0; i < test_cases; i++) {
        for (int j = 0; j < num_students; j++) {
            int li, ri;
            if (scanf("%d %d", &li, &ri) != 2) {
                fprintf(stderr, "Erro na leitura dos tempos li e ri.\n");
                clear_queue(q);
                return 1;
            }
            enqueue(q, ri);
        }

        int time = 1;
        int count = 0;

        while (queue_length(q) > 0) {   
            int queue_time = dequeue(q);
            if (queue_time < time) {
                printf("0%c", count == num_students - 1 ? '\n' : ' ');
            } else {
                printf("%d%c", time, count == num_students - 1 ? '\n' : ' ');
                time++;
            }
            count++;
        }
    }
    clear_queue(q);
    return 0;
}

// Funções auxiliares
Node* create_node(int num) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Erro ao alocar memória para o nó.\n");
        exit(EXIT_FAILURE);
    }
    new_node->element = num;
    new_node->next = NULL;
    return new_node;
}

Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        fprintf(stderr, "Erro ao alocar memória para a fila.\n");
        exit(EXIT_FAILURE);
    }
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

int dequeue(Queue* q) {
    if (q->size == 0) {
        fprintf(stderr, "Tentativa de remover de uma fila vazia.\n");
        return -1;
    }
    Node* temp = q->front;
    int num = temp->element;
    q->front = q->front->next;
    free(temp);
    q->size--;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return num;
}

void clear_queue(Queue* q) {
    while (q->front != NULL) {
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

int queue_length(Queue* q) {
    return q->size;
}

void print_queue(Queue* q) {
    Node* current = q->front;
    while (current != NULL) {
        printf("%d\n", current->element);
        current = current->next;
    }
}
