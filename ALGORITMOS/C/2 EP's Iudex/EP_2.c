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
Node* create_node(Node* next_val, int num);
Node* next_node(Node* next_val);
Queue* create_queue();
void enqueue(Queue* q, int num);
int dequeue(Queue* q);
void clear(Queue* q);
int front_value(Queue* q);
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

        scanf("%6[^\n]", command); // Usa-se %6[^\n] para ler até 6 caracteres ou até encontrar uma nova linha
    
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
            }
            else if(strcmp(command, stats) == 0){
                printf("%d %d", idx, q -> size);
            }
        }
    }  
    clear(q);
    return 0;
}

Node* create_node(Node* next_val, int num){

    Node* n = (Node*) malloc(sizeof(Node));

    n -> element = num;
    n -> next = next_val;

    return n;
}

Node* next_node(Node* next_val){

    Node* n = (Node*) malloc(sizeof(Node));

    n -> next = next_val;

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

    q -> rear -> next = create_node(NULL, num);
    q -> rear = q -> rear -> next;
    q -> size++;
}

int dequeue(Queue* q){

    if (q -> size == 0){
        return -1;
    }
    
    int num = q -> front -> next -> element;

    q -> front -> next = q -> front -> next -> next;

    if (q -> front -> next == NULL){
        q -> rear = q -> front;
        q -> size--;
    }
    return num;
}

void clear(Queue* q){

    Node* current = q -> front;

    while(current != NULL){

        free(current);
        current = q -> front -> next;
    }
    free(q);
}

int front_value(Queue* q){

    int num = q -> front -> element;
    return num; 
}

int length(Queue* q){

    int length = 0;
    Node* current = q -> front;
    
    while (current != NULL){
        
        length++;
        current = current -> next;
    }
    return length;
}
