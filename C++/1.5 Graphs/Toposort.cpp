#include "LinkedList.h"
#include <bits/stdc++.h>

using namespace std;

const int VISITED = 1;
const int UNVISITED = 0;

typedef struct Graph{
    int n;
    int* Mark;
    List** ldj;
} Graph;

Graph* createGraph(int n);
int first(Graph* g, int v);
int next_vertex(Graph* g, int v);
void setEdge(Graph* g, int i, int j);
void delEdge(Graph* g, int i, int j);
void setMark(Graph* g, int v, int state);
int getMark(Graph* g, int v);
void toposort(Graph* g, int v, stack<int>& s);
void clearGraph(Graph* g);
void print_list_vertex(List* l);

int main(){

    Graph* g = createGraph(2);
    setEdge(g, 0, 1);
    setEdge(g, 0, 2);
    setEdge(g, 1, 2);
    setEdge(g, 1, 3);
    setEdge(g, 1, 4);

    for (int i = 0; i < g->n; i++){
        print_list_vertex(g->ldj[i]);
    }
    
    // int x = first(g, 1);
    // printf("%d\n", x);
    // int y = next_vertex(g, 1);
    // printf("%d\n", y);
    // int z = next_vertex(g, 1);
    // printf("%d\n", z);

    // delEdge(g, 0, 2);
    // delEdge(g, 0, 1);
    // delEdge(g, 1, 2);
    // delEdge(g, 1, 3);
    // delEdge(g, 1, 4);
    // for (int i = 0; i < g->n; i++){
    //     print_list_vertex(g->ldj[i]);
    // }

    // printf("%d\n", g->n);

    stack<int> s;
    toposort(g, 0, s);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    clearGraph(g);
    return 0;
}

Graph* createGraph(int n){
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->Mark = (int*)malloc(g->n * sizeof(int));
    g->ldj = (List**)malloc(g->n * sizeof(List*));
    for(int i = 0; i < g->n; i++){
        g->ldj[i] = create_list();
    }
    return g;
}

int first(Graph* g, int v){
    List* l =  g->ldj[v];
    int num = l->head->next->vertex;
    return num;
}

int next_vertex(Graph* g, int v){
    List* l = g->ldj[v];
    if(l->curr == l->tail){
        move_to_start(l);
    }
    l->curr = l->curr->next;
    int num = l->curr->next->vertex;
    return num;
}

void setEdge(Graph* g, int i, int j){
    List* l = g->ldj[i];
    append(l, j);
}

void delEdge(Graph* g, int i, int j){
    List* l = g->ldj[i];
    del(l, j);
    if(l->count == 0){
        g->n--;
    }
}

void setMark(Graph* g, int v, int state){
    if (v >= 0 && v < g->n){
        g->Mark[v] = state;
    }
}

int getMark(Graph* g, int v){
    if (v >= 0 && v < g->n){
        return g->Mark[v];
    }
    return UNVISITED;
}

void toposort(Graph* g, int v, stack<int>& s){
    setMark(g, v, VISITED);
    int w = first(g, v);
    while(w < g->n){
        if(getMark(g, w) == UNVISITED){
            toposort(g, v, s);
        }
    }
    s.push(v);
}

void clearGraph(Graph* g){ // testar
    for (int i = 0; i < g->n; i++){ // Itera sobre todas as ls na tabela
         
        Node* node = g->ldj[i]->head; // ' g->H[i]->head' é a minha l da tabela e sendo assim o bucket da l encadeada
        while(node!=NULL){
            Node* next_node = node->next; // Próximo nó da l recebendo o elemento seguinte ao "head" da l
            free(node);
            node = next_node; // atualizando o nó atual para o seguinte
        }
    }
    for (int i = 0; i < g->n; i++){
        g->ldj[i] = NULL; // Iterando sobre a tabela e fazendo com q cada slot dela receba 'NULL' para esvaziar a tabela
    }
    free(g);
}

void print_list_vertex(List* l){ // adaptar
    Node* temp = l->head->next;
    while (temp != NULL)
    {
        printf("%d ",temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}