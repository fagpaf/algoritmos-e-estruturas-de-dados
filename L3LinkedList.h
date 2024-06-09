#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    Node* curr;
    int count;          
} List;

Node* create_node(Node* n, char* str, int value){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node -> key = str;
    new_node -> next = n;
    new_node -> value = value;
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

void append(List* l, char* str, int value){
    l->curr = l->tail;
    Node* new_node = create_node(NULL,str, value);
    if (l->head->next == NULL) {
        l->head->next = new_node;
        l->tail = new_node;
    } else {
        l->tail->next = new_node;
        l->tail = new_node; 
    }
    l->count++;
}

char* del(List* l){
    l->curr = l->head;
    Node* temp = l->curr->next;
    char* str = temp->key;
    if (l -> tail == temp){
        l->tail = l->curr;
    }
    l -> curr -> next = temp -> next;
    free(temp);   
    l -> count--;
    return str;
}

void printlist(List* l){
    Node* current = l -> head->next;
    while(current != NULL){
        printf("%d:%s\n", current->value, current->key);
        current = current -> next;
    }
    // printf("\n");
}

#endif // List_h