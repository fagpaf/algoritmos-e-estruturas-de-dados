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
void toposort(Graph* g, int v, stack<int>& s);
void clearGraph(Graph* g);
void printVertex(List* l);

// g++ sla.cpp -o sla.exe ; Get-Content input.txt | ./sla.exe

int main(){

    Graph* g = createGraph(9);
    setEdge(g, 1, 4);
    setEdge(g, 1, 2);
    setEdge(g, 4, 2);
    setEdge(g, 4, 3);
    setEdge(g, 3, 2);
    setEdge(g, 5, 2);
    setEdge(g, 3, 5);
    setEdge(g, 8, 2);
    setEdge(g, 8, 6);
    
    bool f = isEdge(g, 3, 2);
    if(f == true){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    for (int i = 0; i < g->n; i++){
        printVertex(g->ldj[i]);
    }
    
    // int x = first(g, 1);
    // cout << x << endl;
    // int y = next_vertex(g, 1);
    // cout << y << endl;
    // int z = next_vertex(g, 1);
    // cout << z << endl;

    // delEdge(g, 0, 2);
    // delEdge(g, 0, 1);
    // delEdge(g, 1, 2);
    // delEdge(g, 1, 3);
    // delEdge(g, 1, 4);
    // for (int i = 0; i < g->n; i++){
    //     printVertex(g->ldj[i]);
    // }
    // cout << g->n << endl;

    // stack<int> s;
    // toposort(g, 1, s);
    // while (!s.empty()) {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    // stack<int> s;
    // for (int i = 0; i < g->n; i++) {
    //     if (getMark(g, i) == UNVISITED) {
    //         toposort(g, i, s);
    //     }
    // }
    
    // while (!s.empty()) {
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    // cout << endl;

    clearGraph(g);
    return 0;
}

Graph* createGraph(int n){
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->Mark = (int*)malloc(g->n * sizeof(int));
    fill(g->Mark, g->Mark + g->n, UNVISITED);
    g->ldj = (List**)malloc(g->n * sizeof(List*));
    for(int i = 0; i < g->n; i++){
        g->ldj[i] = create_list();
    }
    return g;
}

int first(Graph* g, int v){
    List* l = g->ldj[v];
    Node* temp =  l->head->next;
    if(temp != NULL){
        return temp->vertex;
    }
    return g->n;
}

int next_vertex(Graph* g, int v){
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

bool isEdge(Graph* g, int i, int j){
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
    setMark(g, v, VISITED); // Marca o vértice como visitado
    int w = first(g, v);    // Obtém o primeiro vizinho
    while(w < g->n){
        if(getMark(g, w) == UNVISITED){ // Se o vizinho não foi visitado
            toposort(g, w, s);          // Chama recursivamente para o vizinho
        }
        w = next_vertex(g, v); // Obtém o próximo vizinho
    }
    s.push(v);              // Adiciona o vértice à pilha após visitar todos os vizinhos
}

void clearGraph(Graph* g){
    for (int i = 0; i < g->n; i++){
        clear_List(g->ldj[i]);
    }
    free(g->ldj);
    free(g->Mark);
    free(g);
}

void printVertex(List* l){
    printlist(l);
    if(l->count != 0){
        cout << endl;
    }
}