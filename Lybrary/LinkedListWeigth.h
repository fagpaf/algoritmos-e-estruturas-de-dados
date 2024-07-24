#ifndef LINKEDLISTWEIGTH_H
#define LINKEDLISTWEIGTH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    Node* curr;
    int count;
} List;

// Declarações das funções
Node* create_node(int num, int wt){ 
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node ->weight = wt;
    new_node -> vertex = num;
    new_node -> next = NULL;
    return new_node;
}

Node* create_header(Node* nextval){
    Node* header = (Node*)malloc(sizeof(Node));
    header->next = nextval;
    return header;
}

List* create_list(){
    List* l = (List*) malloc(sizeof(List));
    l -> curr = l -> tail = l -> head = create_header(NULL);
    l -> count = 0;
    return l;
}

void insert(List* l, int num , int wt){
    l->curr->next = create_node(num, wt);
    if (l->tail == l->curr){
        l->tail = l->curr->next;
    }
    l->curr = l->curr->next;
    l->count++;
}

void move_to_start(List* l){
    l -> curr = l -> head;
}

void move_to_end(List* l){
    l -> curr = l ->tail;
}

void append(List* l, int num, int wt){
    move_to_end(l);
    insert(l, num, wt);
}

void movecurr(List* l){
    l->curr = l->curr->next;
}

void prev(List* l){
    if (l -> curr == l -> head){
        return;
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

void del(List* l, int j){
    move_to_start(l);
    if (l->curr->next == NULL){
        return; 
    }
    Node* temp = l->head; // Talvez isso n esteja certo e seja l->head->next
    Node* prev = NULL;
    // Se o nó a ser removido é o primeiro nó
    if (temp != NULL && temp->vertex == j) {
        l->head = temp->next;
        if (l->head == NULL) {
            l->tail = NULL; // A lista ficou vazia
        }
        free(temp);
        l->count--;
        return;
    }
    // Procura pelo nó a ser removido, mantendo o nó anterior
    while (temp != NULL && temp->vertex != j) {
        prev = temp;
        temp = temp->next;
    }
    // Se o nó não está na lista
    if (temp == NULL) {
        return;
    }
    // Desvincula o nó da lista
    prev->next = temp->next;
    // Se o nó a ser removido é o último nó
    if (temp == l->tail) {
        l->tail = prev;
    }
    free(temp);
    l->count--;
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

void clear_List(List* l) {
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
    Node* current = l->head->next;
    while(current != NULL){
        printf("%d ", current->vertex);
        current = current->next;
    }
    // printf("\n");
}

#endif