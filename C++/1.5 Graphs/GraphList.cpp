#include "LinkedListSTR.h"
#include <bits/stdc++.h>

using namespace std;

typedef struct Graph{
    int n;                    // Tamanho do grafo
    List** listAdj;         // É um ponteiro para um array de ponteiros para "struct List" 
    // Cada elemento do array H é um ponteiro para o início de uma lista encadeada.
} Graph;

Graph* createGraph(int n);
void setEdge(Graph* g, char* str);
void clearGraph(Graph* g);

int main() {

    Graph* g = createGraph(4);



    clearGraph(g);
    return 0;
}

Graph* createGraph(int n){
    Graph* g = (Graph*)malloc(sizeof(List));
    g->n = n;
    g->listAdj = (List**)malloc(g->n * sizeof(List*)); // 'sizeof(struct List*)' retorna o tamanho em bytes de um ponteiro para struct List
    // Multiplicando esse tamanho por 'g->n', q é o tamanho da tabela temos reservado o tamanho necessário para armazenar nossa tabela
    
    for(int i = 0; i < g->n; i++){
        g->listAdj[i] = create_list(); // 'g->listAdj[i] ' é um bucket que pode conter uma lista encadeada de nós
    }
    return g;
}

void setEdge(Graph* g, char* str){



}

void clearGraph(Graph* g){ // testar
    for (int i = 0; i < g->n; i++){ // Itera sobre todas as listas na tabela
         
        Node* node = g->listAdj[i]->head; // ' g->H[i]->head' é a minha lista da tabela e sendo assim o bucket da lista encadeada
        while(node!=NULL){
            Node* next_node = node->next; // Próximo nó da lista recebendo o elemento seguinte ao "head" da lista
            free(node);
            node = next_node; // atualizando o nó atual para o seguinte
        }
    }
    for (int i = 0; i < g->n; i++){
        g->listAdj[i] = NULL; // Iterando sobre a tabela e fazendo com q cada slot dela receba 'NULL' para esvaziar a tabela
    }
    free(g);
}