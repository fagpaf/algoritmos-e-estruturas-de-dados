#ifndef GRAPHWEIGHT_H
#define GRAPHWEIGHT_H

#include "LinkedListWeigth.h"
#include <bits/stdc++.h>

const int VISITED = 1;
const int UNVISITED = 0;
const int INFINITE = INT32_MAX;

using namespace std;

typedef struct Graph{
    int n;
    int* Parent;
    int* Mark;
    List** ldj;
} Graph;

Graph* createGraph(int n);
int first(Graph* g, int v);
int next_vertex(Graph* g, int v);
void setEdge(Graph* g, int i, int j, int wt);
void delEdge(Graph* g, int i, int j);
bool isEdge(Graph* g, int i, int j);
int weight(Graph* g, int i, int j);
void setMark(Graph* g, int v, int state);
int getMark(Graph* g, int v);
void clearGraph(Graph* g);

Graph* createGraph(int n){ //ok
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->Parent = (int*)malloc(g->n * sizeof(int)); // É inicializado no Dijkstra
    g->Mark = (int*)malloc(g->n * sizeof(int));
    g->ldj = (List**)malloc(g->n * sizeof(List*));
    for(int i = 0; i < g->n; i++){
        g->Mark[i] = UNVISITED;
        g->ldj[i] = create_list();
    }
    return g;
}

int first(Graph* g, int v){ //ok
    List* l = g->ldj[v];
    Node* temp =  l->head->next;
    if(temp != NULL) return temp->vertex;

    return g->n;
}

int next_vertex(Graph* g, int v){ //ok
    List* l = g->ldj[v];
    if(l->curr == l->tail){
        move_to_start(l);
    }
    l->curr = l->curr->next;
    if(l->curr->next != NULL) return l->curr->next->vertex;
    
    return g->n;
}

void setEdge(Graph* g, int i, int j, int wt){ 
    List* l = g->ldj[i];
    append(l, j, wt);
}

void delEdge(Graph* g, int i, int j){ //ok
    List* l = g->ldj[i];
    if(l == NULL || g == NULL) return;
    
    del(l, j);
    if(l->count == 0){
        g->n--;
    }
}

bool isEdge(Graph* g, int i, int j){ //ok
    List* l = g->ldj[i];
    Node* temp = l->head->next;
    while(temp != NULL){
        if(temp->vertex == j){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int weight(Graph* g, int i, int j){
    List* l = g->ldj[i];
    Node* temp = l->head->next;
    while(temp != NULL){
        if (temp->vertex == j){
            return temp->weight;
        }
        temp = temp->next;
    }
    return INFINITE;
}

void setMark(Graph* g, int v, int state){ //ok
    if (v >= 0 && v < g->n){
        g->Mark[v] = state;
    }
}

int getMark(Graph* g, int v){ //ok
    if (v >= 0 && v < g->n){
        return g->Mark[v];
    }
    return UNVISITED;
}

void clearGraph(Graph* g){ //ok
    for (int i = 1; i < g->n; i++){
        clear_List(g->ldj[i]);
    }
    free(g->ldj);
    free(g->Parent);
    free(g->Mark);
    free(g);
}
#endif