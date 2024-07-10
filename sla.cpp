#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define UNVISITED 0
#define VISITED 1

using namespace std;

struct Node {
    int vertex;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
    Node* curr;
    int count;
};

struct Graph {
    int n;
    int* Mark;
    List** ldj;
};

List* create_list() {
    List* l = (List*)malloc(sizeof(List));
    l->head = l->tail = l->curr = (Node*)malloc(sizeof(Node));
    l->head->next = NULL;
    l->count = 0;
    return l;
}

void append(List* l, int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    l->tail->next = newNode;
    l->tail = newNode;
    l->count++;
}

void move_to_start(List* l) {
    l->curr = l->head;
}

void clear_List(List* l) {
    Node* temp = l->head;
    while (temp != NULL) {
        Node* to_delete = temp;
        temp = temp->next;
        free(to_delete);
    }
    free(l);
}

Graph* createGraph(int n) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->Mark = (int*)malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++) {
        g->Mark[i] = UNVISITED;
    }
    g->ldj = (List**)malloc(g->n * sizeof(List*));
    for (int i = 0; i < g->n; i++) {
        g->ldj[i] = create_list();
    }
    return g;
}

int first(Graph* g, int v) {
    List* l = g->ldj[v];
    Node* temp = l->head->next;
    if (temp != NULL) {
        int num = temp->vertex;
        return num;
    }
    return g->n;
}

int next_vertex(Graph* g, int v) {
    List* l = g->ldj[v];
    if (l->curr == l->tail) {
        move_to_start(l);
    }
    l->curr = l->curr->next;
    if (l->curr->next != NULL) {
        return l->curr->next->vertex;
    }
    return g->n;
}

void setEdge(Graph* g, int i, int j) {
    List* l = g->ldj[i];
    append(l, j);
}

bool isEdge(Graph* g, int i, int j) {
    List* l = g->ldj[i];
    Node* temp = l->head->next;
    while (temp != NULL) {
        if (temp->vertex == j) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void setMark(Graph* g, int v, int state) {
    if (v >= 0 && v < g->n) {
        g->Mark[v] = state;
    }
}

int getMark(Graph* g, int v) {
    if (v >= 0 && v < g->n) {
        return g->Mark[v];
    }
    return UNVISITED;
}

void toposort(Graph* g, int v, stack<int>& s, bool& ward) {
    setMark(g, v, VISITED);
    int w = first(g, v);
    while (w < g->n) {
        if (getMark(g, w) == UNVISITED) {
            toposort(g, w, s, ward);
        }
        w = next_vertex(g, v);
    }
    s.push(v);
}

void clearGraph(Graph* g) {
    for (int i = 0; i < g->n; i++) {
        clear_List(g->ldj[i]);
    }
    free(g->ldj);
    free(g->Mark);
    free(g);
}

void printTopologicalOrder(Graph* g) {
    vector<int> in_degree(g->n, 0);
    for (int i = 0; i < g->n; i++) {
        List* l = g->ldj[i];
        Node* temp = l->head->next;
        while (temp != NULL) {
            in_degree[temp->vertex]++;
            temp = temp->next;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < g->n; i++) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        result.push_back(u);

        List* l = g->ldj[u];
        Node* temp = l->head->next;
        while (temp != NULL) {
            in_degree[temp->vertex]--;
            if (in_degree[temp->vertex] == 0) {
                pq.push(temp->vertex);
            }
            temp = temp->next;
        }
    }

    if (result.size() != g->n) {
        cout << "Sandro fails." << endl;
    } else {
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i] + 1; // Adjusting for 1-based index output
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph* g = createGraph(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        setEdge(g, x - 1, y - 1); // Adjusting for 0-based index internally
    }

    printTopologicalOrder(g);
    clearGraph(g);

    return 0;
}
