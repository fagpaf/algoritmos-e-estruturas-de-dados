#include <stdio.h>
#include <stdlib.h>

// Definição das estruturas de nó e fila
typedef struct Node {
    int start_time; // li
    int leave_time; // ri
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Funções
Node* create_node(int start_time, int leave_time);
Queue* create_queue();
void enqueue(Queue* q, int start_time, int leave_time);
int dequeue(Queue* q, int* start_time, int* leave_time);
void clear_queue(Queue* q);
int queue_length(Queue* q);

int main() {
    Queue* q = create_queue();
    int t, n;
    
    if (scanf("%d", &t) != 1) {
        fprintf(stderr, "Erro na leitura do número de testes.\n");
        return 1;
    }
    
    for (int i = 0; i < t; i++) {
        if (scanf("%d", &n) != 1) {
            fprintf(stderr, "Erro na leitura do número de estudantes.\n");
            clear_queue(q);
            return 1;
        }

        for (int j = 0; j < n; j++) {
            int li, ri;
            if (scanf("%d %d", &li, &ri) != 2) {
                fprintf(stderr, "Erro na leitura dos tempos li e ri.\n");
                clear_queue(q);
                return 1;
            }
            enqueue(q, li, ri);
        }

        int time = 1;
        int count = 0;

        while (queue_length(q) > 0) {
            int start_time, leave_time;
            if (dequeue(q, &start_time, &leave_time) == -1) {
                fprintf(stderr, "Erro ao desempilhar a fila.\n");
                clear_queue(q);
                return 1;
            }

            if (start_time > time) {
                time = start_time; // Ajusta o tempo atual para quando o estudante chegou
            }

            if (leave_time < time) {
                printf("0%c", count == n - 1 ? '\n' : ' ');
            } else {
                printf("%d%c", time, count == n - 1 ? '\n' : ' ');
                time++;
            }
            count++;
        }
    }
    clear_queue(q);
    return 0;
}

// Funções auxiliares
Node* create_node(int start_time, int leave_time) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Erro ao alocar memória para o nó.\n");
        exit(EXIT_FAILURE);
    }
    new_node->start_time = start_time;
    new_node->leave_time = leave_time;
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

void enqueue(Queue* q, int start_time, int leave_time) {
    Node* new_node = create_node(start_time, leave_time);
    if (q->rear == NULL) {
        q->front = new_node;
    } else {
        q->rear->next = new_node;
    }
    q->rear = new_node;
    q->size++;
}

int dequeue(Queue* q, int* start_time, int* leave_time) {
    if (q->size == 0) {
        return -1;
    }
    Node* temp = q->front;
    *start_time = temp->start_time;
    *leave_time = temp->leave_time;
    q->front = q->front->next;
    free(temp);
    q->size--;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return 0;
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
