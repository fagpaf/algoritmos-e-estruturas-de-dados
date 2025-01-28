#include "Graph.h"

typedef struct setQU{
    int* tree;
} setQU;

int main() {
    Graph* g = createGraph;
    Graph* res = createGraph;
    
    
    
    return 0;
}

int find(setQU* ds, int curr) {
    while (curr != ds->tree[curr]) {
        curr = ds->tree[curr];
    }
    return curr;
}

void Union(setQU* ds, int a, int b) {
    int root1 = find(ds, a);
    int root2 = find(ds, b);
    if (root1 != root2) {
        ds->tree[root2] = root1;
    }
}

setQU* createDisjointSet(int n) {
    setQU* ds = (setQU*) malloc(sizeof(setQU));
    ds->tree = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ds->tree[i] = i;
    }
    return ds;
}

void kruskal(Graph* g, Graph* res){
    int edgecnt = 1;
    for (int i = 0; i < g->n -1; i++){
        int w = first(g, i);
        do{
            H[edgecnt++] = (i, w, weight(g, i, w));
            w = next(g, i, w);
        }
        while(w < g->n);
    }
    priority_queue;
    ds = create_disjointSubset(g->n);
    numMST = g->n;
    while(numMST > 1){
        (v, u, wt) = H.top();
        if(find(ds, v) != find(ds, u)){
            Union(ds, v, u);
            setEdge(res, v, u, wt);
            num_MST--;
        }
    }
}


