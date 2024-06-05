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
Node* create_node(Node* n, int num); // Função q retorna um ponteiro para a struct "Node"
Node* create_header(Node* nextval);
List* create_list();

// Operações:
void insert(List* l, int num);
void move_to_start(List* l);
void move_to_end(List* l);
void movecurr(List* l);
void prev(List* l);
void next(List* l);
void printlist(List* l);
void clearList(List* l);
int  del(List* l);
int  length(List* l);
int  curr_pos(List* l);

int main(){

    int x = 0;
    List* l = create_list();
    
    insert(l, 10);
    insert(l, 20);
    printlist(l);
    
    move_to_start(l);
    x = curr_pos(l);
    printf("%d\n", x);
    
    insert(l, 30); // Inserir 30 após a posição do cursor (que está no início)
    insert(l, 40); // Inserir 40 após a posição do cursor (que agora está após 30)
    
    move_to_end(l);
    insert(l, 50); // Inserir 50 no final da lista
    
    printf("Lista: ");
    printlist(l); // Deveria imprimir: 10 30 40 20 50
    
    clear_List(l);
    return 0;
}

Node* create_node(Node* n, int num){ 
    Node* new_node = (Node*) malloc(sizeof(Node)); // Alocação dinâmica para o ponteiro da struct "Node"
    // Usando o operador "->": 
    // Atribui o valor 'num' ao campo 'element' da struct "Node"
    
    new_node -> element = num; // Pode-se acessar e modificar os membros da estrutura diretamente, sem a necessidade de desreferenciar o ponteiro explicitamente
    new_node -> next = n; // Atribui o ponteiro 'next_val' ao campo 'next' do Node
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

void insert(List* l, int num){
    l->curr->next = create_node(l->curr->next ,num);
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

int del(List* l){ // Ecrever "typedef struct Node" fez sumir o erro: "ponteiro ou referência para o tipo incompleto 'struct Node' não é permitida" 
    if (l -> curr -> next == NULL){
        return -1; // Porque função "int" ñ permite retornar "NULL", pq ele é usado para funções de retorno para ponteiros, '-1' indica um erro 
    }
    Node* temp = l->curr->next;
    int num = temp -> element;
    if (l -> tail == temp){
        l->tail = l->curr;
    }
    l -> curr -> next = temp -> next;
    free(temp);   
    l -> count--;
    return num;
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
        printf("%d ", current -> element);
        current = current -> next;
    }
    printf("\n");
}