#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    Queue* q = create_queue();

    int id = 0;
    int idx = 0;
    int loop = -1;

    char command[6];
    char fim[4] = "end";

    // Strings para comparar a função a ser executada
    char add[4] = "add";
    char solve[6] = "solve";
    char print[6] = "print";
    char stats[6] = "stats";

    while (loop != 0) { // COMPARAR STRING'S
        scanf("%5s", command); // Use %5s para ler uma string de até 6 caracteres (excluindo o terminador nulo)
        
        if (strcmp(command, fim) == 0) {
            loop = 0;
        } 
        else {
            
            if (strcmp(command, add) == 0) {
                scanf("%d", &id);
                enqueue(q, id);
            
            } else if (strcmp(command, solve) == 0) {
                if(q->size > 0){
                    dequeue(q);
                    idx++;
                }  
            
            } else if (strcmp(command, print) == 0) {
                
                if(q->size > 0){
                    int temp = q->size;
                    Node* current = q->front;
                    while (current != NULL) {
                        if(temp == 1){
                            printf("%d", current->element);
                            current = current->next;
                            temp--;
                        }
                        else{
                            printf("%d ", current->element);
                            current = current->next;
                            temp--;
                        }
                    }
                    printf("\n");
                }
                else{
                    printf("x\n");
                }
            
            } else if (strcmp(command, stats) == 0) {
                printf("%d %d\n", idx, q->size);
            }
        }
    }
    clear(q);
    return 0;
}

Node* create_node(int num) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (n == NULL) {
        // Tratar erro de alocação de memória
        exit(EXIT_FAILURE);
    }
    n->element = num;
    n->next = NULL;
    return n;
}

Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        // Tratar erro de alocação de memória
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

int dequeue(Queue* q){

    if (q -> size == 0){
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
