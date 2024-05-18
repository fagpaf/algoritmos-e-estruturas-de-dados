#include <stdio.h>
#include <stdlib.h>

Node* initial_node(int num, Node* next_val); // Função q retorna um ponteiro para a struct "Node"

Node* create_next_node(Node* next_val); // Um ponteiro para o próximo nó na lista encadeada

typedef struct{

    int element; // O elemento armazenado no nó
    struct Node* next; // Ponteiro para o próximo nó

} Node;

typedef struct{

    Node head;
    Node tail;
    Node curr;
    int count;          // list size

} List;

int main() {


    
    return 0;
}

Node* intial_node(int num, Node* next_val){ 
    
    Node* new_node = (Node*) malloc(sizeof(Node)); // Alocação dinâmica para o ponteiro do nó "new_node"
    
    // Usando o operador "->": 

    // Atribui o valor 'num' ao campo 'element' da struct "Node"
    
    new_node -> element = num; // Pode-se acessar e modificar os membros da estrutura diretamente, sem a necessidade de desreferenciar o ponteiro explicitamente
    
    new_node -> next = next_val; // Atribui o ponteiro 'next_val' ao campo 'next' do Node

    return new_node;
}

Node* create_next_node(Node* next_val){

    Node* next_node = (Node*) malloc(sizeof(Node));

    next_node -> next = next_val;

    return next_node;
}

List* creat_list(){
    
    List* l = (List*) malloc(sizeof(List));

    l -> curr = NULL;
    l -> tail = NULL;
    l -> head = NULL;

    l -> count = 0;

    return l;        
}
