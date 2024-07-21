#include <bits/stdc++.h>

using namespace std;

const int VISITED = 1;
const int UNVISITED = 0;

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    Node* curr;
    int count;
} List;

typedef struct Graph{
    int n;
    int* Mark;
    List** ldj;
} Graph;

Node* create_node(Node* n, int num);
Node* create_header(Node* nextval);
List* create_list();
void insert(List* l, int num);
void move_to_start(List* l);
void move_to_end(List* l);
void clearList(List* l);
//---------------------------------------
Graph* createGraph(int n);
int first(Graph* g, int v);
int next_vertex(Graph* g, int v);
void setEdge(Graph* g, int i, int j, int wt);
void delEdge(Graph* g, int i, int j);
bool isEdge(Graph* g, int i, int j);
int weight(Graph* g, int i, int j);
void setMark(Graph* g, int v, int state);
int getMark(Graph* g, int v);
void prim(Graph* g, int D[]);
void clearGraph(Graph* g);

int main(){
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
            if(wt < weight(g, v, u)){
                setEdge(g, v, u, wt);
                setEdge(g, u, v, wt);
            }
        }
        int arr[g->n];
        prim(g, arr);
        int res = 0;
        for (int i = 1; i < g->n; i++){ // pois os 'arr[0]' começa com '0'
            if(res < arr[i]){
                res = arr[i];
            }
        }
        cout << res << endl;
        clearGraph(g);
    }
    return 0;
}

Node* create_node(int num, int wt){ 
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node ->weight = wt;
    new_node -> vertex = num;
    new_node -> next = NULL;
    return new_node;
}

Node* create_header(Node* nextval){
    Node* header = (Node*)malloc(sizeof(Node));
    header->next = nextval;
    return header;
}

List* create_list(){
    List* l = (List*) malloc(sizeof(List));
    l -> curr = l -> tail = l -> head = create_header(NULL);
    l -> count = 0;
    return l;
}

void insert(List* l, int num , int wt){
    l->curr->next = create_node(num, wt);
    if (l->tail == l->curr){
        l->tail = l->curr->next;
    }
    l->curr = l->curr->next;
    l->count++;
}

void move_to_start(List* l){
    l -> curr = l -> head;
}

void move_to_end(List* l){
    l -> curr = l ->tail;
}

void append(List* l, int num, int wt){
    move_to_end(l);
    insert(l, num, wt);
}

void clearList(List* l) {
    Node* current = l->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(l);
}

Graph* createGraph(int n){
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->Mark = (int*)malloc(g->n * sizeof(int));
    g->ldj = (List**)malloc(g->n * sizeof(List*));
    for(int i = 0; i < g->n; i++){
        g->Mark[i] = UNVISITED;
        g->ldj[i] = create_list();
    }
    return g;
}

int first(Graph* g, int v){
    List* l = g->ldj[v];
    Node* temp =  l->head->next;
    if(temp != NULL){
        int num = temp->vertex;
        return num;
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

void setEdge(Graph* g, int i, int j, int wt){ 
    List* l = g->ldj[i];
    append(l, j, wt);
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
    return INT32_MAX;
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

void prim(Graph* g, int D[]){
    for (int i = 0; i < g->n; i++){
        D[i] = INT32_MAX;
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

void clearGraph(Graph* g){
    for (int i = 1; i < g->n; i++){
        clearList(g->ldj[i]);
    }
    free(g->Mark);
    free(g);
}