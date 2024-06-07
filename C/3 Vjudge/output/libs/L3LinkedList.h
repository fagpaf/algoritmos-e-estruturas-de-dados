#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
// Definição do nó da linked list
typedef struct Node {
    char* key;
    int value;
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
Node* create_node(Node* n, char* str, int value){ 
    Node* new_node = (Node*) malloc(sizeof(Node)); // Alocação dinâmica para o ponteiro da struct "Node"
    // Usando o operador "->": 
    // Atribui o valor 'num' ao campo 'key' da struct "Node"
    
    new_node -> key = str; // Pode-se acessar e modificar os membros da estrutura diretamente, sem a necessidade de desreferenciar o ponteiro explicitamente
    new_node -> next = n; // Atribui o ponteiro 'next_val' ao campo 'next' do Node
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

void insert(List* l, char* str, int value){
    l->curr->next = create_node(l->curr->next ,str, value);
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

void append(List* l, char* str, int value){
    move_to_end(l);
    insert(l, str, value);
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
    char* str = temp -> key;
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
    Node* current = l -> head->next;
    while(current != NULL){
        printf("%s ", current -> key);
        current = current -> next;
    }
    printf("\n");
}

#endif // List_h