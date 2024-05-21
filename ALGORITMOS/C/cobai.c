#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int element;
    struct Node* next;
} Node;

typedef struct Queue{
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

    while(loop != 0){ // COMPARAR STRING'S
        scanf("%5s", command); // Use %5s para ler uma string de até 5 caracteres (excluindo o terminador nulo)
    
        if (strcmp(command, fim) == 0){
            loop = 0;
        }
        else{
            if (strcmp(command, add) == 0){
                scanf("%d", &id);
                enqueue(q, id);
            }
            else if(strcmp(command, solve) == 0){
                dequeue(q);
                idx++;
            }
            else if(strcmp(command, print) == 0){
                Node* first = q -> front;
                while(first != NULL){   
                    printf("%d ", first -> element);
                    first = first -> next;
                }
                printf("\n");
            }
            else if(strcmp(command, stats) == 0){
                printf("%d %d", idx, q -> size);
            }
        }
    }  
    clear(q);
    return 0;
}

Node* create_node(int num){
    Node* n = (Node*) malloc(sizeof(Node));
    n -> element = num;
    n -> next = NULL;
    return n;
}

Queue* create_queue(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q -> front = NULL; 
    q -> rear =  NULL;
    q -> size = 0;
    return q;
}

void enqueue(Queue* q, int num){
    Node* new_node = create_node(num);
    q -> rear = new_node;
    q -> size++;
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

void clear(Queue* q){
    while(q -> front != NULL){
        Node* current = q -> front;
        q -> front = q -> front -> next;
        free(current);
    }
    free(q);
}

int length(Queue* q){
    return q -> size;
}
