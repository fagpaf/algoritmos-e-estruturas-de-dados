#include "Graph.h"

int main() {
    Graph* g = createGraph;
    Graph* res = createGraph;
    
    
    
    return 0;
}

void Kruskal(Graph* g, Graph* res){
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
            union(ds, v, u);
            setEdge(res, v, u, wt);
            num_MST--;
        }
    }
}