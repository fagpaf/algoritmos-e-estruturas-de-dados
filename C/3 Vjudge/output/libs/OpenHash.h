#ifndef OPENHASH_H
#define OPENHASH_H

#include <string.h>
#include "Q3LinkedList.h"

typedef int (*HashFunction)(char* key); //  podemos usar HashFunction como qualquer outro tipo, como int ou char*

typedef struct Dictionary{
    int m;                // Tamanho da tabela
    int cnt;              // Números de elementos na tabela
    HashFunction hashFun; // 'hashFun' é uma variável do tipo "HashFunction", ou seja, é um ponteiro para uma função
    List** H;         // É um ponteiro para um array de ponteiros para "struct List" 
    // Cada elemento do array H é um ponteiro para o início de uma lista encadeada.
} Dictionary;

Dictionary* createDict(int size, int(*hash)(char*));
Node* create_entry(Node* n, char* str);
int find(Dictionary* d, char* key);
void insertDict(Dictionary* d, char* key, int num);
int size(Dictionary* d);
void print_list_elements(List* lista);
void clearDict(Dictionary* d);

// Ponteiro para função ----> <tipo-de-retorno> ( *<nome-da-variável> ) ( <parâmetros> )

Dictionary* createDict(int size, int(*hash)(char*)){
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

Node* create_entry(Node* n, char* str){
    n->element = str;
    n->next = NULL; // Define o próximo como NULL, pois este será o último nó já q só será inserido via "append"
    return n; 
}

int find(Dictionary* d, char* key) {
    for (int i = 0; i <= d->m - 1; i++) {
        Node* temp = d->H[i]->head->next;
        for(int j = 0; j < d->H[i]->count; j++){
            if (temp->element == key) {         // Verifica se a 'key' do nó atual (d->H[i]->key) é igual ao valor 'key' que estamos procurando.
                return i;                          // Retorna o índice se a chave for encontrada, usando o '&' para ter o endereço de memória do bucket
            }
            temp = temp->next;
        }
    }
    return -1; // Retorna NULL se a chave não for encontrada
}

void insertDict(Dictionary* d, char* key, int num){
    if (find(d, key) == -1){
        for (int j = 1; i < 20; j++){
            int pos = (d->hashFun(key) + j^2 + 23*j) % 101;
            if (d->H[pos] == NULL ){
                int pos = d->hashFun(key);
                List* l = d->H[pos];
                Node* entry = create_entry(l->tail, num);
                append(l, entry->element);
            }
            
        }
    }
}

int size(Dictionary* d){
    return d->cnt;
}

void print_list_elements(List* lista){
    Node* temp = lista->head->next;
    while (temp != NULL){
        printf("%s ",temp->element);
        temp = temp->next;
    }
    free(temp);
    printf("\n");
    
}

void remove_key(Dictionary* d, char* key){ // mexer aq
    for (int i = 0; i < 101; i++){
        if (d->H[i] != NULL){
            if (strcmp(d->H[i], key) == 0){
                d->H[i] = NULL;
                return;
            }
            else{
                for (int j = 0; j < length(H[i]); j++){
                    if (strcmp(d->H[j], key) == 0{
                        d->H[j] = NULL;
                    }
                }
            }
        }
    }
}

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