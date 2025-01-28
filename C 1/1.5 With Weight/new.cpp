#include "LinkedListWeigth.h"
#include <bits/stdc++.h>

const int VISITED = 1;
const int UNVISITED = 0;
const int INFINITE = INT32_MAX;

using namespace std;

typedef struct Graph {
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
int Dijkstra(Graph* g, int src, int dest);
void clearGraph(Graph* g);

int main() {
    Graph* g = createGraph(3);
    // setEdge(g, 0, 1, 10);
    // setEdge(g, 0, 2, 3);
    // setEdge(g, 0, 3, 20);
    // setEdge(g, 1, 3, 5);
    // setEdge(g, 2, 1, 2);
    // setEdge(g, 2, 4, 15);
    // setEdge(g, 3, 4, 11);

    const int A = 0;
    const int B = 1;
    const int C = 2;

    setEdge(g, A, B, 100);
    setEdge(g, A, C, 200);
    setEdge(g, B, C, 50);
    setEdge(g, B, A, 100);
    setEdge(g, C, A, 200);
    setEdge(g, C, B, 50);

    int src = A;
    int dest = C;
    cout << "Resultado do algoritmo de Dijkstra:" << endl;
    int ping = Dijkstra(g, src, dest);
    cout << "Soma das distancias minimas: " << ping << endl;

    clearGraph(g); // Libera memória alocada para o grafo
    return 0;
}

Graph* createGraph(int n) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->Parent = (int*)malloc(g->n * sizeof(int));
    g->Mark = (int*)malloc(g->n * sizeof(int));
    g->ldj = (List**)malloc(g->n * sizeof(List*));
    for (int i = 0; i < g->n; i++) {
        g->Mark[i] = UNVISITED;
        g->ldj[i] = create_list();
    }
    return g;
}

int first(Graph* g, int v) {
    List* l = g->ldj[v];
    Node* temp = l->head->next;
    if (temp != NULL) {
        int num = temp->vertex;
        return num;
    }
    return g->n;
}

int next_vertex(Graph* g, int v) {
    List* l = g->ldj[v];
    if (l->curr == l->tail) {
        move_to_start(l);
    }
    l->curr = l->curr->next;
    if (l->curr->next != NULL) {
        return l->curr->next->vertex;
    }
    return g->n;
}

void setEdge(Graph* g, int i, int j, int wt) {
    List* l = g->ldj[i];
    append(l, j, wt);
}

void delEdge(Graph* g, int i, int j) {
    List* l = g->ldj[i];
    if (l == NULL || g == NULL) {
        return;
    }
    del(l, j);
    if (l->count == 0) {
        g->n--;
    }
}

bool isEdge(Graph* g, int i, int j) {
    List* l = g->ldj[i];
    Node* temp = l->head->next;
    while (temp != NULL) {
        if (temp->vertex == j) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int weight(Graph* g, int i, int j) {
    List* l = g->ldj[i];
    Node* temp = l->head->next;
    while (temp != NULL) {
        if (temp->vertex == j) {
            return temp->weight;
        }
        temp = temp->next;
    }
    return INFINITE;
}

void setMark(Graph* g, int v, int state) {
    if (v >= 0 && v < g->n) {
        g->Mark[v] = state;
    }
}

int getMark(Graph* g, int v) {
    if (v >= 0 && v < g->n) {
        return g->Mark[v];
    }
    return UNVISITED;
}

int Dijkstra(Graph* g, int src, int dest) {
    int D[g->n];
    for (int i = 0; i < g->n; i++) {
        D[i] = INFINITE;
        g->Parent[i] = -1;
        setMark(g, i, UNVISITED);
    }
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > H;
    H.push({0, {src, src}});
    D[src] = 0;

    int v, parent; 
    while (!H.empty()) {
        pair<int, pair<int, int>> top = H.top();
        H.pop();
        v = top.second.first;
        parent = top.second.second;
        
        if (getMark(g, v) == VISITED) continue;
        
        setMark(g, v, VISITED);
        g->Parent[v] = parent;

        if (v == dest) return D[v];

        int w = first(g, v);
        while (w < g->n) {
            if (getMark(g, w) != VISITED && D[w] > D[v] + weight(g, v, w)) {
                D[w] = D[v] + weight(g, v, w);
                H.push({D[w], {w, v}});
            }
            w = next_vertex(g, v);
        }
    }
}

void clearGraph(Graph* g) {
    for (int i = 0; i < g->n; i++) {
        clear_List(g->ldj[i]);
    }
    free(g->ldj);
    free(g->Parent);
    free(g->Mark);
    free(g);
}
