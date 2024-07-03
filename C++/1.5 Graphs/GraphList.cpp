#include <bits/stdc++.h>

using namespace std;

typedef struct Graph{
    int n;
    vector<list<int>> listAdj;
} Graph;

Graph* createGraph(int n);

int main() {



    return 0;
}

Graph* createGraph(int n){
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->listAdj.resize(n); // Redimensiona o vetor para conter n listas
    return g;
}
