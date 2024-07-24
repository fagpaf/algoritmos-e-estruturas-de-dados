#include "GraphMatrix.h"

int main(){
    Graph* g = create_graph(5);
    setEdge(g, 0, 1);
    setEdge(g, 0, 2);
    setEdge(g, 1, 3);
    setEdge(g, 1, 4);

    graphTraverse(g);

    clear_graph(g);
    return 0;
}
// g++ Graph.cpp -o Graph.exe ; Get-Content input.txt | ./Graph.exe