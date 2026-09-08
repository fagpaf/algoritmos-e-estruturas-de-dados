#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ // Assim deixa mais explícito o nome da struct
    int element; // O elemento armazenado no nó
    struct Node* next; // Ponteiro para o próximo nó
} Node;

typedef struct Stack{
    Node* top; // Referência para o primeiro elemento
    int size;
} Stack;

// Funções:
Stack* create_s();
void clearStack(Stack* s);
void push(Stack* s, int num);
void print_stack(Stack* s);
int pop(Stack* s);
int top_value(Stack* s);
int length(Stack* s);
int is_empyt(Stack* s);

int main() {


    return 0;
}

Stack* create_s(){
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s -> top = NULL;
    s -> size = 0;
    return s;
}

void push(Stack* s, int num){
    Node* n = (Node*) malloc(sizeof(Node));

    n->element = num;
    n->next = s->top;
    s->top = n;
    s->size++;
}

int pop(Stack* s){
    if (s->top == NULL){
        return -1;
    }
    
    Node* temp = s->top;
    int num = s->top->element;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return num;
}

int top_value(Stack* s){
    if(s->top == NULL){
        return -1;
    }
    int num = s->top->element;
    return num;
}

int length(Stack* s){
    return s->size;
}

void clearStack(Stack* s){
    while(s->top != NULL){
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->size = 0;
}

void print_stack(Stack* s){
    if (s->top == NULL){
        printf("-1\n");
    }
    Node* current = s->top;
    while(current != NULL){
        printf("%d ", current->element);
        current = current->next;
    }
    printf("\n");
}

int is_empyt(Stack* s){
    if (s->size == 0){
        return 0; // Falso
    }
    return 1; // Verdadeiro se a pilha tiver vazia
}