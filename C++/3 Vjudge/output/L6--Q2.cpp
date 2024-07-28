#include "libs/Graph.h"

void prim(Graph* g, int D[]);

int main() {
    int city, road;
    while(true){
        cin >> city >> road;
        if(city == 0 && road == 0) break;

        if(road == 0 || city >= road + 2){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        Graph* g = createGraph(city);
        int v, u, wt;
        for (int i = 0; i < road; i++){
            cin >> v >> u >> wt;
            if(wt > weight(g, v, u)) continue;
            setEdge(g, v, u, wt);
            setEdge(g, u, v, wt);
        }

        int arr[g->n];
        prim(g, arr);
        int res = 0;
        for (int i = 1; i < g->n; i++){ // pois os 'arr[0]' começa com '0'
            if(res > arr[i]) continue;
            res = arr[i];
        }

        if(res == INFINITE){
            cout << "IMPOSSIBLE" << endl;
        }else{
            cout << res << endl;
        }
        clearGraph(g);
    }
    return 0;
}
// g++ q.cpp -o q.exe ; Get-Content input.txt | ./q.exe

void prim(Graph* g, int D[]){
    for (int i = 0; i < g->n; i++){
        D[i] = INFINITE;
        g->Parent[i] = -999;
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
            v = top.second.first;
        }while (!(getMark(g, v) == UNVISITED));

        setMark(g, v, VISITED);
        g->Parent[v] = top.first;        
        int w = first(g, v);
        while (w < g->n){
            if(getMark(g, w) != VISITED && D[w] > weight(g, v, w)){ 
                D[w] = weight(g, v, w); 
                H.push({D[w], {w, v}}); 
            }
            w = next_vertex(g, v);      
        }
    }
}