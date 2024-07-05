#include "LinkedList.h"
#include <bits/stdc++.h>

using namespace std;

int VISITED = 1;
int UNVISITED = 0;

typedef struct Graph{
    int n;
    int* Mark;
    List** ldj;
} Graph;

Graph* createGraph(int n);
int first(Graph* g, int v);
void setEdge(Graph* g, int i, int j);
void setMark(Graph* g, int v, int state);
int getMark(Graph* g, int v);
void BFS(Graph* g, int start);
void graphTraverse(Graph* g);
void clearGraph(Graph* g);

int main() {

    int c, v, a;
    scanf("%d", &c);
    
    while (c--){
        scanf("%d %d", &v , &a);
        Graph* g = createGraph(v);

        int i, j;
        for (int k = 0; k < a; k++){
            scanf("%d %d", &i, &j);
            setEdge(g, i, j);
            setEdge(g, j, i);
        }
        int p;
        scanf("%d", &p);

        int idx = 1;
        printf("Caso %d", idx);
        int  s, t;
        for (int m = 0; m < p; m++){
            scanf("%d %d", &s, &t);
            graphTraverse(g);
        }
        
    
        idx++;
        clearGraph(g);
    }
    return 0;
}
// g++ q.cpp -o q.exe ; Get-Content input.txt | ./q.exe

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

void BFS(Graph* g, int start){
    queue<int> q;
    q.push(start);
    setMark(g, start, VISITED);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        // preVisit(g, v);
        int w = first(g, v);
        while (w < g->n){
            if (getMark(g, w) == UNVISITED){
                setMark(g, w, VISITED);
                q.push(w);
            }
            w = next_vertex(g, v);
        }
        // posVisit(g, v);
    }
}

void graphTraverse(Graph* g){
    for (int v = 0; v < g->n -1; v++){
        setMark(g, v, UNVISITED);
    }
    for (int v = 0; v < g->n - 1; v++){
        if (getMark(g, v) == UNVISITED){
            BFS(g, v);
        }
    }    
}

void clearGraph(Graph* g){ // precisa dar free na 'Mark'
    for (int i = 0; i < g->n; i++){ 
        Node* node = g->ldj[i]->head; 
        while(node!=NULL){
            Node* next_node = node->next;
            free(node);
            node = next_node;
        }
    }
    for (int i = 0; i < g->n; i++){
        g->ldj[i] = NULL;
    }
    free(g);
}