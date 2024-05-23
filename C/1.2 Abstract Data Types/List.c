#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ // Assim deixa mais explícito o nome da struct
    int element; // O elemento armazenado no nó
    struct Node* next; // Ponteiro para o próximo nó
} Node;

typedef struct List{ 
    Node* head;
    Node* tail;
    Node* curr;
    int count;          // list size
} List;

// Ponteiros:
Node* create_node(Node* next_val, int num); // Função q retorna um ponteiro para a struct "Node"
Node* create_next_node(Node* next_val); // Um ponteiro para o próximo nó na lista encadeada
List* creat_list();

// Operações:
void insert(List* l, int num);
void move_to_start(List* l);
void move_to_end(List* l);
void append(List* l, int num);
void prev(List* l);
void next(List* l);
void printlist(List* l);
void clear(List* l);
int  del(List* l);
int  length(List* l);


int main() {
    
    int x = 3;
    
    List* l = creat_list();
    x = length(l);
    printf("%d\n", x);
    
    insert(l, 1);
    insert(l, 2);
    insert(l, 4);
    x = length(l);
    printf("%d\n", x);
    printlist(l);

    clear(l);
    return 0;
}

Node* create_node(Node* next_val, int num){ 
    
    Node* new_node = (Node*) malloc(sizeof(Node)); // Alocação dinâmica para o ponteiro da struct "Node"
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
    l -> curr = NULL; // Inicializa o 'curr' como NULL
    l -> tail = NULL; // Inicializa a 'tail' como NULL
    l -> head = NULL; // Inicializa o 'head' como NULL
    l -> count = 0;   // Inicializa o contador de nós como 0
    return l;
}

void insert(List* l, int num){ // Com o pointer "List* l" a função terá acesso a lista original e ñ uma cópia, assim inserindo o novo valor na linked list

    l -> curr -> next = create_node(l -> curr -> next, num); // Criar um novo nó e atribui ao seu próximo o ponteiro do próximo link do nó atual

    if (l -> tail == l -> curr){ // Se a "cauda" for igual a posição do cursor, então a cauda recebe a nova posição do cursor   
        l -> tail = l -> curr -> next;
    }
    l -> count++; // Aumenta o tamanho da lista em +1
}

void move_to_start(List* l){
    l -> curr = l -> head; // Move o cursor para o início  da lista
}

void move_to_end(List* l){
    l -> curr = l ->tail; // Move o cursor para o final da lista
}

// TESTAR COM CUIDADO
void append(List* l, int num){ // Adiciona um novo nó ao final da lista, como em .py
    move_to_end(l);
    insert(l, num);
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

int del(List* l){ // Ecrever "typedef struct Node" fez sumir o erro: "ponteiro ou referência para o tipo incompleto 'struct Node' não é permitida" 

    if (l -> curr -> next == NULL){
        return -1; // Porque função "int" ñ permite retornar "NULL", pq ele é usado para funções de retorno para ponteiros, '-1' indica um erro 
    }
    
    int num = l -> curr -> next -> element;
    
    if (l -> tail == l -> curr -> next){
        l -> curr -> next = l -> curr -> next -> next;        
        l -> count--;
    }
    return num;
}
//int curr_pos(List* l){}

int length(List* l){
    Node* current = l -> head;
    int size = 0;
    
    if (current != NULL){
        size++;
        current = current -> next;
    }
    return size;
}

void clear(List* l){
    Node* current = l -> head;
    
    while (current != NULL){
        free(current);
        current = current -> next;
    }
    free(l);
}

void printlist(List* l){
    Node* current = l -> head;

    while(current != NULL){
        printf("%d\n", current -> element);
        current = current -> next;
    }
}