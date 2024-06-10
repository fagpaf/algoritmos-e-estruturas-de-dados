#ifndef OPENHASH_H
#define OPENHASH_H

#include <math.h>
#include "L3LinkedList.h"

typedef int (*HashFunction)(char* key); //  podemos usar HashFunction como qualquer outro tipo, como int ou char*

typedef struct Dictionary{
    int m;                // Tamanho da tabela
    int cnt;              // Números de chaves na tabela
    HashFunction hashFun; // 'hashFun' é uma variável do tipo "HashFunction", ou seja, é um ponteiro para uma função
    List** H;         // É um ponteiro para um array de ponteiros para "struct List" 
    // Cada keyo do array H é um ponteiro para o início de uma lista encadeada.
} Dictionary;

// Ponteiro para função ----> <tipo-de-retorno> ( *<nome-da-variável> ) ( <parâmetros> )

Dictionary* createDict(int size, int(*hash)(char*)){ //ok
    Dictionary* d = (Dictionary*)malloc(sizeof(Dictionary));
    d->m = size;
    d->cnt = 0;
    d->H = (List**)malloc(size * sizeof(List*)); // 'sizeof(struct List*)' retorna o tamanho em bytes de um ponteiro para struct List
    for(int i = 0; i < size; i++){
        d->H[i] = create_list(); // 'H[i]' é um bucket que pode conter uma lista encadeada de nós
    }
    d->hashFun = hash;
    return d;
}

int find(Dictionary* d, char* key) { // ok
    for(int i = 0; i < d->m; i++){
        Node* current = d->H[i]->head->next;
        while(current != NULL){
            if (strcmp(current->key, key) == 0) {
                return i;
            }
            current = current->next;
        }
    }
    return -1;
}

void insertDict(Dictionary* d, char* key, int value){ // ok
    if (find(d, key) == -1){
        for (int j = 1; j < 20; j++){
            int pos = (value + (int)pow(j, 2) + 23*j) % 101; // Type cast para int pq pow() é real
            if (d->H[pos]->head->next == NULL){ // mt burro
                List* l = d->H[pos];
                append(l, key, value);
                d->cnt++;
                return;
            }
        }
    }
}

void remove_key(Dictionary* d, char* key){ // mexer aq
    int search = find(d, key);
    if(search != -1){
        del(d->H[search], key);
        d->cnt--;
    }
}

void clearDict(Dictionary* d){ //ok
    for (int i = 0; i < d->m; i++){ // Itera sobre todas as listas na tabela hash
        Node* node = d->H[i]->head; // ' d->H[i]->head' é a minha lista da tabela e sendo assim o bucket da lista encadeada
        while(node!=NULL){
            Node* next_node = node->next; // Próximo nó da lista recebendo o keyo seguinte ao "head" da lista
            free(node);
            node = next_node; // atualizando o nó atual para o seguinte
        }
        free(d->H[i]);
    }
    free(d);
}

// void printDict(Dictionary* d){
//     List* arr = (Node*)malloc(d->m * sizeof(Node*)); // criando um array de ponteiros para fazer o quicksort nele
//     for(int i = 0; i < d->m; i++){
//         if (d->H[i]->head->next != NULL){
//             Node* current = d->H[i]->head->next;
//             while(current != NULL){
//                 arr = current;
//                 current = current -> next;
//             }
//         }
//     }
//     // Quicksort para organizar o array e imprimir
// }

#endif