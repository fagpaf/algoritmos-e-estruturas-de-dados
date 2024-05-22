#include <stdio.h>

typedef struct Node{ // Assim deixa mais explícito o nome da struct
    int element; // O elemento armazenado no nó
    struct Node* next; // Ponteiro para o próximo nó
} Node;

typedef struct Stack{
    Node* top; // Referência para o primeiro elemento
    int size;
} Stack;

Node* create_node(int num);
Stack* create_s();

// Funções:
void clear(Stack* s);
void push(Stack* s, int num);
void print_stack(Stack* s);
int pop(Stack* s);
int top_value(Stack* s);
int length(Stack* s);


int main() {

    Stack* s = create_s();
    int x = 2;
    int y = 5;
    int z = 7;
    
    push(s, z);
    push(s, y);
    print_stack(s);
    push(s, x);
    print_stack(s);
    pop(s);
    print_stack(s);
    
    return 0;
}

Node* create_node(int num){
    Node* n = (Node*) malloc(sizeof(Node));
    n->element = num;
    n->next = NULL;
    return n;
}

Stack* create_s(){
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s -> top = NULL;
    s -> size = 0;
    return s;
}

void push(Stack* s, int num){
    s->top = create_node(num);
    s->size++;
}

int pop(Stack* s){
    if (s->top == NULL){
        return -1;
    }
    
    int num = s->top->element;
    s->top = s->top->next;
    s->size--;
    return num;
}

int top_value(Stack* s){
    int num = s->top->element;
    return num;
}

int length(Stack* s){
    return s->size;
}

void clear(Stack* s){
    while(s->top != NULL){
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

void print_stack(Stack* s){
    while(s->top != NULL){
        int num = s->top->element;
        printf("%d", num);
        s->top = s->top->next;
    }
    printf("\n");
}