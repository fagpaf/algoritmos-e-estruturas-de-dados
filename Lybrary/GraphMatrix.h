#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

#include <bits/stdc++.h>

using namespace std;

const bool VISITED = true;
const bool UNVISITED = false;

typedef struct Graph{
    int** matrix;
    int numEdge;
    int* Mark; 
    int n;   
} Graph;

Graph* createGraph(int n);
int first(Graph* g, int v);
int next(Graph* g, int v, int w);
void setEdge(Graph* g, int i, int j, int wt);
void delEdge(Graph* g, int i, int j);
int weight(Graph* g, int i, int j);
void setMark(Graph* g, int v, bool state);
bool getMark(Graph* g, int v);
void graphTraverse(Graph* g);
void preVisit(Graph* g, int v);
void posVisit(Graph* g, int v);
void DFS(Graph* g, int v);
void BFS(Graph* g, int start);
void toposort(Graph* g, int v, stack<int>& s);
void clear_graph(Graph* g);

Graph* createGraph(int n){
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->Mark = (int*)malloc(n * sizeof(int*));
    g->matrix = (int**)malloc(n * sizeof(int*));
    g->numEdge = 0;
    g->n = n;
    // Inicializa a matriz de adjacência com 0
    for (int i = 0; i < n; i++){
        g->matrix[i] = (int*)malloc(n * sizeof(int)); // alocando os espaços para matriz
        for (int j = 0; j < n; j++){
            g->matrix[i][j] = 0;
        }
    }
    return g;
}

int first(Graph* g, int v){
    for (int i = 0; i < g->n -1; i++){
        if(g->matrix[v][i] != 0){
            return i;
        }
    }
    return g->n;
}

int next(Graph* g, int v, int w){
    for(int i = w+1; i < g->n - 1; i++){
        if(g->matrix[v][i] != 0){
            return i;
        }
    }
    return g->n;
}

void setEdge(Graph* g, int i, int j, int wt){ //int wt, o peso da aresta
    if(wt == 0) return;

    if(g->matrix[i][j] == 0){
        g->numEdge++;
    }
    g->matrix[i][j] = wt;
}

void delEdge(Graph* g, int i, int j){
    if(g->matrix[i][j] != 0){
        g->numEdge--;
    }
    g->matrix[i][j] = 0;
}

int weight(Graph* g, int i, int j) {
    // Verifica se os índices estão dentro dos limites do grafo
    if (i < 0 || i >= g->n || j < 0 || j >= g->n) {
        return -1; // Retorna -1 para indicar erro
    }
    return g->matrix[i][j];
}


void setMark(Graph* g, int v, bool state){
    if (v >= 0 && v < g->n){
        g->Mark[v] = state;
    }
}

bool getMark(Graph* g, int v){ // essa função é int, tenho q criar um enum
    if (v >= 0 && v < g->n){
        return g->Mark[v];
    }
    return UNVISITED;
}

// Cuidado com grafos não conectados
void graphTraverse(Graph* g){
    for (int v = 0; v < g->n - 1; v++){
        setMark(g, v, UNVISITED);
    }
    for (int v = 0; v < g->n - 1; v++){
        if(getMark(g, v) == UNVISITED){
            BFS(g,v); // Busca em Largura
        }
    }
}

void DFS(Graph* g, int v){
    preVisit(g, v);
    setMark(g, v, VISITED);
    int w = first(g, v);
    while(w < g->n){
        if(getMark(g, w) == UNVISITED){
            DFS(g ,w);
        }
        w = next(g, v, w);
    }
}

void BFS(Graph* g, int start){
    queue<int> q;
    q.push(start);
    setMark(g, start, VISITED);
    while(!q.empty()){ // Enquanto a fila n estiver vazia faça
        int v = q.front();
        q.pop();
        preVisit(g, v);
        int w = first(g, v);
        while (w < g->n){
            if (getMark(g, w) == UNVISITED){
                setMark(g, w, VISITED);
                q.push(w);
            }
            w = next(g, v, w);
        }
        posVisit(g, v);
    }
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
// ------------------------------------------------------
void preVisit(Graph* g, int v){
    // Implementar a ação desejada para pre-visitação
    cout<<"PreVisit: " << v << endl;
}

void posVisit(Graph* g, int v){
    // Implementar a ação desejada para pós-visitação
    cout<<"PostVisit: " << v << endl;
}

void clear_graph(Graph* g){
    for (int i = 0; i < g->n; i++){
        free(g->matrix[i]);
    }
    free(g->matrix);
    free(g->Mark);
    free(g);
}
#endif