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
bool isEdge(Graph* g, int i, int j);
void setMark(Graph* g, int v, int state);
int getMark(Graph* g, int v);
void toposort(Graph* g, int v, stack<int>& s, bool& ward);
void clearGraph(Graph* g);
void printVertex(List* l);

int main(){
    int n, operations;
    cin >> n >> operations;
    Graph* g = createGraph(n + 1); // para satisfazer o range
    int x, y;
    for (int i = 0; i < operations; i++){
        cin >> x >> y;
        setEdge(g, x, y);
    }
    stack<int> s;
    bool ward = false;
    for (int i = 1; i < g->n; i++){
        if(getMark(g, i) == UNVISITED){
            toposort(g, i, s, ward);
        }
    }
    if(ward == true){
        cout << "Sandro fails.";
    }
    else{
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
    }

    clearGraph(g);
    return 0;
}
// g++ teste.cpp -o teste.exe ; Get-Content input.txt | ./teste.exe

Graph* createGraph(int n){ //ok
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->Mark = (int*)malloc(g->n * sizeof(int));
    for(int i = 1; i < g->n; i++){
        g->Mark[i] = UNVISITED;
    }
    g->ldj = (List**)malloc(g->n * sizeof(List*));
    for(int i = 1; i < g->n; i++){
        g->ldj[i] = create_list();
    }
    return g;
}

int first(Graph* g, int v){ //ok
    List* l = g->ldj[v];
    Node* temp =  l->head->next;
    if(temp != NULL){
        int num = temp->vertex;
        return num;
    }
    return g->n;
}

int next_vertex(Graph* g, int v){ //ok
    List* l = g->ldj[v];
    if(l->curr == l->tail){
        move_to_start(l);
    }
    l->curr = l->curr->next;
    if(l->curr->next != NULL){
        return l->curr->next->vertex;
    }
    return g->n;
}

void setEdge(Graph* g, int i, int j){ //ok
    List* l = g->ldj[i];
    append(l, j);
}

void delEdge(Graph* g, int i, int j){ //ok
    if(g->ldj[i] == NULL || g == NULL){
        return;
    }
    List* l = g->ldj[i];
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

void toposort(Graph* g, int v, stack<int>& s, bool& ward){
    setMark(g, v, VISITED); // Marca o vértice como visitado
    int w = first(g, v);    // Obtém o primeiro vizinho
    while(w < g->n){
        if(getMark(g, w) == UNVISITED){ // Se o vizinho não foi visitado
            toposort(g, w, s, ward);     
        }
        // else{
        //     ward = true;
        //     return;
        // }
        w = next_vertex(g, v); // Obtém o próximo vizinho
    }
    s.push(v);              // Adiciona o vértice à pilha após visitar todos os vizinhos
}

void clearGraph(Graph* g){ //ok
    for (int i = 1; i < g->n; i++){
        clear_List(g->ldj[i]);
    }
    free(g);
}

void printVertex(List* l){ //ok
    printlist(l);
    if(l->count != 0){
        cout << endl;
    }
}