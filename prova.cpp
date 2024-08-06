#include "Lybrary/GraphMatrix.h"


typedef struct Node{
    int value;
    struct Node* next;
} Node;

typedef struct Stack{
    Node* top;
    int cnt;
}Stack;

Node* create_node(int element, Node* next){
    Node* n = (Node*)malloc(sizeof(Node));
    n->value = element;
    n->next = next;
    return n;
}

Stack* create_stack(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    s->cnt = 0;
    return s;
}

void push(Stack* s, int element){
    Node* n = (Node*)malloc(sizeof(Node));
    n->value = element;
    n->next = s->top;
    s->top = n;
    s->cnt++;
}

int pop(Stack* s){
    if(s->top == NULL){
        return -1;
    }

    Node* temp = s->top;
    int num = s->top->value;
    s->top = s->top->next;
    free(temp);
    s->cnt--;
    return num;
}

int length(Stack* s){
    return s->cnt;
}

int main(){

    cout << "ad" << endl;
    return 0;
}


// -----------------------------------------------------
// BFS
void BFS(Graph* g, int start){
    queue<int> q;
    q.push(start);
    setMark(g, start, VISITED);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        int w = first(g, v);
        while(w < g->n){
            if(getMark(g, w) == UNVISITED){
                setMark(g, w, VISITED);
                q.push(w);
            }
            w = next(g, v, w);
        }
    }
}

void DFS(Graph* g, int v){
    setMark(g, v, VISITED);
    int w = first(g, v);
    while(w < g->n){
        if(getMark(g, w) == UNVISITED){
            DFS(g, w);
        }
        w = next(g, v, w);
    }
}

// void graphTraverse(Graph* g){
//     for (int i = 0; i < g->n; i++){
//         setMark(g, i, UNVISITED)
//     }
//     for (int i = 0; i < g->n; i++){
//         if(getMark(g, i) == UNVISITED){
//             DFS(g, i);
//         }
//     }
// }

void BFS(Graph* g, int start){
    queue<int> q;
    q.push(start);
    setMark(g, start, VISITED);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        int w = first(g, v);
        while(w < g->n){   
            if(getMark(g, w) == UNVISITED){
                setMark(g, w, VISITED);
                q.push(w);
            }
            w = next(g, v, w);
        }
    }
}

void DFS(Graph* g, int v){
    setMark(g, v, VISITED)
    int w = first(g, v);
    while(w < g->n){
        if(getMark(g, w) == UNVISITED){
            DFS(g, w);
        }
        w = next(g, v, w);
    }
}





void graphTraverse(Graph* g){
    for (int i = 0; i < g->n; i++){
        setMark(g, i, UNVISITED);
    }
    for (int i = 0; i < g->n; i++){
        if(getMark(g, i) == UNVISITED){
            DFS(g, i);
        }
    }
    
}






// ---------------------------------------------------------
// KNAPSACK-BU

// int knapsack(int n, int W, int weight_of[], int value_of[], int** F) {
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= W; j++) {
//             int current = F[i][j];
//             int notInsert = F[i-1][j];
//             int insert = value_of[i] + F[i-1][j-weight_of[i]];
//             if (weight_of[i] <= j) {
//                 current = max(notInsert, insert);
//             } else {
//                 current = notInsert;
//             }
//         }
//     }
//     return F[n][W];


int knapsack(int n, int W, int weight_of[], int value_of[], int** F){
    F[n+1][W+1] = malloc;
    for (int i = 1; i <= n; i++){
        for (int j = 1; i <= W; j++){
            int current = F[i][j];
            int notInsert = F[i-1][j];
            int insert = value_of[i] + F[i-1][j - weight-of[i]]
            if(weight_of[i] <= j){
                current = max(notInsert, insert);
            }
            else{
                current = notInsert;
            }
        }
    }
    return F[n][W];
}