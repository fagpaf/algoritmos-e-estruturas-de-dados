#include <bits/stdc++.h>
//IMPLEMENTAR COM LISTA DE ADJACÊNCIA(OPEN HASH)
using namespace std;

const bool VISITED = true;
const bool UNVISITED = false;

typedef struct Graph{
    int** matrix;   // Matriz de adjacência
    int numEdge;    // Número de Arestas
    int* Mark;      // Matriz de marcação auxiliar do array
    int n;          // Número de Vértices
} Graph;

Graph* create_graph(int n);
int first(Graph* g, int v);
int next(Graph* g, int v, int w);
void setEdge(Graph* g, int i, int j);
void delEdge(Graph* g, int i, int j);
void setMark(Graph* g, int v, bool state);
bool getMark(Graph* g, int v);
void graphTraverse(Graph* g);
void preVisit(Graph* g, int v);
void posVisit(Graph* g, int v);
void DFS(Graph* g, int v);
void BFS(Graph* g, int start);
void toposort(Graph* g, int v, stack<int>& s);

int main() {
    int n, command;
    cin >> &n;


    Graph* g = create_graph(5);
    setEdge(g, 0, 1);
    setEdge(g, 0, 2);
    setEdge(g, 1, 3);
    setEdge(g, 1, 4);

    graphTraverse(g);

    clear_graph(Graph* g);
    return 0;
}

// g++ Graph.cpp -o Graph.exe ; Get-Content input.txt | ./Graph.exe

Graph* create_graph(int n){
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->Mark = (int*)malloc(n * sizeof(int*));
    g->matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->matrix[i] = (int*)malloc(n * sizeof(int)); // alocando os espaços para matriz
    }
    g->flag = g->numEdge = 0;
    g->n = n;
    // Inicializa a matriz de adjacência com 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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

void setEdge(Graph* g, int i, int j){ //int wt, o peso da aresta
    // if(wt == 0) return;

    if(g->matrix[i][j] == 0){
        g->numEdge++;
    }
    // g->matrix[i][j] = wt;
}

void delEdge(Graph* g, int i, int j){
    if(g->matrix[i][j] != 0){
        g->numEdge--;
    }
    g->matrix[i][j] = 0;
}

void setMark(Graph* g, int v, bool state) {
    if (v >= 0 && v < g->n) {
        g->Mark[v] = state;
    }
}

bool getMark(Graph* g, int v) { // essa função é int, tenho q criar um enum
    if (v >= 0 && v < g->n) {
        return g->Mark[v];
    }
    return UNVISITED;
}

// Cuidado com grafos n conectados
void graphTraverse(Graph* g){
    for (int v = 0; v < g->n - 1; v++){
        setMark(g, v, UNVISITED);
    }
    for (int v = 0; v < g->n - 1; v++){
        if(getMark(g, v) == UNVISITED){
            DFS(g,v);
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
    while(q.size() > 0){
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
void preVisit(Graph* g, int v) {
    // Implementar a ação desejada para pre-visitação
    cout<<"PreVisit: " << v << endl;
}


void posVisit(Graph* g, int v) {
    // Implementar a ação desejada para pós-visitação
    cout<<"PostVisit: " << v << endl;
}

void clear_graph(Graph* g){
    for (int i = 0; i < g->n; i++) {
        free(g->matrix[i]);
    }
    free(g->matrix);
    free(g->Mark);
    free(g);
}