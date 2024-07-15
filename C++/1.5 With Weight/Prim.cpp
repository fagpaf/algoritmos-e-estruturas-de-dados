#include "LinkedList.h"
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
void Prim(Graph* g, int D[], int V[]);
void printPrim(Graph* g, int D[]);
void clearGraph(Graph* g);

int main() {
    Graph* g = createGraph(5);

    setEdge(g, 0, 1, 10);
    setEdge(g, 0, 2, 3);
    setEdge(g, 0, 3, 20);
    setEdge(g, 1, 3, 5);
    setEdge(g, 2, 1, 2);
    setEdge(g, 2, 4, 15);
    setEdge(g, 3, 4, 11);

    int D[g->n];
    int V[g->n];
    cout << "Resultado do algoritmo de Prim:" << endl;
    Prim(g, D, V);
    printPrim(g, D);
    
    return 0;
}

Graph* createGraph(int n){ //ok
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->Parent = (int*)malloc(g->n * sizeof(int)); // É inicializado no Prim
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

void setEdge(Graph* g, int i, int j, int wt){ 
    List* l = g->ldj[i];
    append(l, j, wt);
}

void delEdge(Graph* g, int i, int j){ //ok
    List* l = g->ldj[i];
    if(l == NULL || g == NULL){
        return;
    }
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

void Prim(Graph* g, int V[], int D[]){
    for (int i = 0; i < g->n; i++){
        D[i] = INFINITE;               // Array de distâncias, inicia-se com o maior valor possível
        g->Parent[i] = -1;                     // Array de vértices predecessores 'parents'
        setMark(g, i, UNVISITED);
    }
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    >H;
    H.push({0, {0, 0}}); // (distância, (vértice, predecessor))
    D[0] = 0;
    
    for (int i = 0; i < g->n; i++){
        pair<int, pair<int, int>> top;
        int v;
        do{
            if(H.empty()) return;
            top = H.top();
            H.pop();
            v = top.second.first;   // Pegando o vértice atual, pois 'top.first' é o predecessor
        }while (!(getMark(g, v) == UNVISITED));// Nesse 'do while' removesse o menor elemento da heap até q ele não tenha sido visitado
        
        setMark(g, v, VISITED);
        V[v] = top.first;               // Fazendo a marcação do predecessor de 'v', no array para indicar de qual vértice vc veio
        int w = first(g, v);
        while (w < g->n){
            if(getMark(g, w) != VISITED && D[w] > weight(g, v, w)){ 
                // 'w' é 'UNVISITED' e a distância indo direto para 'w' for maior q passando por 'v' + o peso de 'v' para 'w'
                
                D[w] = weight(g, v, w);
                H.push({D[w], {w, v}}); // Inserir na heap a nova tripla de valores para criar a min heap e refazer o loop
            }
            w = next_vertex(g, v);       // Como o algoritmo encontra uma família de menores caminhos, ele usa todos os vértices q tem ligação
        }
        
    }
}

void printPrim(Graph* g, int D[]){
    for (int i = 0; i < g->n; i++){
        cout << D[i] << " ";
    }
    cout << endl;
}

void clearGraph(Graph* g){ //ok
    for (int i = 1; i < g->n; i++){
        clear_List(g->ldj[i]);
    }
    free(g->Parent);
    free(g->Mark);
    free(g);
}
