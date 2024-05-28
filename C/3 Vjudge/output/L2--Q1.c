#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int element;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    Node* curr;
    int count;
} List;

Node* create_node(Node* n, char c);
Node* create_header(Node* nextval);
List* create_list();
void insert(List* l, char c);
void move_to_start(List* l);
void move_to_end(List* l);
void printlist(List* l);
void clear(List* l);

const int MAXLEN = 100001;

int main() {
    char str[MAXLEN];
    
    while(scanf(" %s", str) != EOF) { // É bom dar esse espaço no " %s" para evitar problema
        List* l = create_list();
        
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '[') {
                move_to_start(l);
            } else if (str[i] == ']') {
                move_to_end(l);
            } else {
                insert(l, str[i]);
            }
        }
        printlist(l);
        clear(l);
    }
    return 0;
}

Node* create_node(Node* n, char c){ 
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node -> element = c;
    new_node -> next = n;
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
void insert(List* l, char c){
    l->curr->next = create_node(l->curr->next, c);
    if (l->tail == l->curr){
        l->tail = l->curr->next;
    }
    l->curr = l->curr->next;
    l->count++;
}

void move_to_start(List* l) {
    l->curr = l->head;
}

void move_to_end(List* l) {
    l->curr = l->tail;
}

void clear(List* l) {
    Node* current = l->head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(l);
}

void printlist(List* l){
    Node* current = l -> head->next;
    while(current != NULL){
        printf("%c", current -> element);
        current = current -> next;
    }
    printf("\n");
}