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

    int id;
    int idx = 0;
    char comando[6];
    char loop[4] = "BLA";
    while(loop != "end"){ // COMPARAR STRING'S
        
        scanf("%s", &comando);
        
        if (comando == "add"){
            scanf("%d", &id);
            enqueue(q, id);
        }
        else if(comando == "solve"){
            dequeue(q);
            idx++;
        }
        else if(comando == "print"){
            
            Node* first = q -> front;
            
            while(first != NULL){
                
                printf("%d ", first);
                first = first -> next;
            }
        }
        else if(comando == "stats"){
            int v = length(q);
            printf("%d %d", idx, v);
        }
    }

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

    int num = q -> front -> next -> element;
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
