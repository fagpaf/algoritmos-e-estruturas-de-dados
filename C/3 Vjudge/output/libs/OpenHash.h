#ifndef OPENHASH_H
#define OPENHASH_H

#include "LinkedList.h"

typedef int (*HashFunction)(int key, int m); //  podemos usar HashFunction como qualquer outro tipo, como int ou char*

typedef struct Dictionary{
    int m;                // Tamanho da tabela
    int cnt;              // Números de elementos na tabela
    HashFunction hashFun; // 'hashFun' é uma variável do tipo "HashFunction", ou seja, é um ponteiro para uma função
    List** H;         // É um ponteiro para um array de ponteiros para "struct List" 
    // Cada elemento do array H é um ponteiro para o início de uma lista encadeada.
} Dictionary;

Dictionary* createDict(int size, int(*hash)(int, int));
Node* create_entry(Node* n, int num);
int find(Dictionary* d, int key);
void insertDict(Dictionary* d, int key, int num);
int hash(int key, int m);
int size(Dictionary* d);
void print_list_elements(List* lista);
void clearDict(Dictionary* d);

int hash(int key, int m){
    int value = key % m;
    if(value < 0){
        value += m;
    }
    return value;
}

// Ponteiro para função ----> <tipo-de-retorno> ( *<nome-da-variável> ) ( <parâmetros> )

Dictionary* createDict(int size, int(*hash)(int, int)){
    Dictionary* d = (Dictionary*)malloc(sizeof(List));
    d->m = size;
    d->cnt = 0;
    d->H = (List**)malloc(d->m * sizeof(List*)); // 'sizeof(struct List*)' retorna o tamanho em bytes de um ponteiro para struct List
    // Multiplicando esse tamanho por 'd->m', q é o tamanho da tabela temos reservado o tamanho necessário para armazenar nossa tabela
    
    for(int i = 0; i <= size - 1; i++){
        d->H[i] = create_list(); // 'H[i]' é um bucket que pode conter uma lista encadeada de nós
    }
    d->hashFun = hash;
    return d;
}

Node* create_entry(Node* n, int num){
    n->element = num;
    n->next = NULL; // Define o próximo como NULL, pois este será o último nó já q só será inserido via "append"
    return n; 
}

int find(Dictionary* d, int key) {
    for (int i = 0; i <= d->m - 1; i++) {
        Node* temp = d->H[i]->head->next;
        for(int j = 0; j < d->H[i]->count; j++){
            if (temp->element == key) {         // Verifica se a 'key' do nó atual (d->H[i]->key) é igual ao valor 'key' que estamos procurando.
                return i;                          // Retorna o ponteiro se a chave for encontrada, usando o '&' para ter o endereço de memória do bucket
            }
            temp = temp->next;
        }
    }
    return -1; // Retorna NULL se a chave não for encontrada
}

void insertDict(Dictionary* d, int key, int num){
    if (find(d, key) == -1){
        int pos = d->hashFun(key, d->m);
        List* l = d->H[pos];
        Node* entry = create_entry(l->tail, num);
        append(l, entry->element);
    }
}

int size(Dictionary* d){
    return d->cnt;
}

void print_list_elements(List* lista){
    Node* temporario = lista->head->next;
    while (temporario != NULL)
    {
        printf("%d ",temporario->element);
        temporario = temporario->next;
    }
    printf("\n");
}

// int remove_key(){

// }

void clearDict(Dictionary* d){
    for (int i = 0; i <= d->m - 1; i++){ // Itera sobre todas as listas na tabela hash
         
        Node* node = d->H[i]->head; // ' d->H[i]->head' é a minha lista da tabela e sendo assim o bucket da lista encadeada
        while(node!=NULL){
            Node* next_node = node->next; // Próximo nó da lista recebendo o elemento seguinte ao "head" da lista
            free(node);
            node = next_node; // atualizando o nó atual para o seguinte
        }
    }
    for (int i = 0; i < d->m; i++){
        d->H[i] = NULL; // Iterando sobre a tabela e fazendo com q cada slot dela receba 'NULL' para esvaziar a tabela
    }
    d->cnt = 0;
    free(d);
}

#endif