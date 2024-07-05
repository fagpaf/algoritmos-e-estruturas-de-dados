#ifndef LINKEDLISTSTR_H
#define LINKEDLISTSTR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Definição do nó da linked list

typedef struct Node {
    char* vertex;
    struct Node* next;
} Node;

// Definição da estrutura da lista ligada
typedef struct List {
    Node* head;
    Node* tail;
    Node* curr;
    int count;          // tamanho da lista
} List;

// Declarações das funções
Node* create_node(Node* n, char* str){ 
    if(str == NULL || strlen(str) == 0){ // verifica se a strig é vazia
        return NULL;
    }
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->vertex = (char*)malloc(strlen(str) + 1); // Aloca espaço para a string
    strcpy(new_node->vertex, str);                     // Copia a string para o campo vertex
    new_node -> next = n;
    return new_node;
}

Node* create_header(Node* nextval){
    Node* header = (Node*)malloc(sizeof(Node));
    header->next = nextval;
    return header;
}

List* create_list(){
    List* l = (List*) malloc(sizeof(List));
    l -> curr = l -> tail = l -> head = create_header(NULL); // Inicializa a lista como NULL
    l -> count = 0;   // Inicializa o contador de nós como 0
    return l;
}

void insert(List* l, char* str){
    l->curr->next = create_node(l->curr->next ,str);
    if (l->tail == l->curr){
        l->tail = l->curr->next;
    }
    l->curr = l->curr->next;
    l->count++;
}

void move_to_start(List* l){
    l -> curr = l -> head; // Move o cursor para o início  da lista
}

void move_to_end(List* l){
    l -> curr = l ->tail; // Move o cursor para o final da lista
}

void append(List* l, char* str){
    move_to_end(l);
    insert(l, str);
}

void movecurr(List* l){
    l->curr = l->curr->next;
}

void prev(List* l){
    if (l -> curr == l -> head){
        return; // Em "void" você pode usar "return;" vazio para interromper a função prematuramente  
    }
    Node* temp = l -> head;
    while(temp -> next != l -> curr){
        temp = temp -> next;
    }
    l -> curr = temp;
}

void next(List* l){
    if (l -> curr != l -> tail){
        l -> curr = l -> curr -> next;
    } 
}

char* del(List* l){ // Ecrever "typedef struct Node" fez sumir o erro: "ponteiro ou referência para o tipo incompleto 'struct Node' não é permitida" 
    if (l -> curr -> next == NULL){
        return NULL; // Porque função "int" ñ permite retornar "NULL", pq ele é usado para funções de retorno para ponteiros, '-1' indica um erro 
    }
    Node* temp = l->curr->next;
    char* str = temp -> vertex;
    if (l -> tail == temp){
        l->tail = l->curr;
    }
    l -> curr -> next = temp -> next;
    free(temp);   
    l -> count--;
    return str;
}

int curr_pos(List* l){
    int pos = 0;
    Node* current = l->head;
    while(current != NULL){
        if(current == l->curr){
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;
}

int length(List* l){
    return l->count;
}

void clearList(List* l) {
    Node* current = l->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(l);
}

void printlist(List* l){
    Node* current = l -> head->next;
    while(current != NULL){
        printf("%s ", current -> vertex);
        current = current -> next;
    }
    printf("\n");
}

#endif