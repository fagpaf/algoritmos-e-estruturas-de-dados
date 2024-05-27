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

Node* create_node(char c);
List* create_list();
void insert(List* l, char c);
void move_to_start(List* l);
void move_to_end(List* l);
void printlist(List* l);
void clear(List* l);

const int MAXLEN = 10000;

int main() {
    char str[MAXLEN];
    
    while (fgets(str, MAXLEN, stdin) != NULL) {
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

void home(List* l, char c) {
    Node* new_node = create_node(c);
    if (l->head == NULL) {
        l->head = l->tail = l->curr = new_node;
    } else {
        new_node->next = l->head;
        l->head = new_node;
    }
    move_to_start(l);
    l->count++;
}

Node* create_node(char c) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->element = c;
    new_node->next = NULL;
    return new_node;
}

List* create_list() {
    List* l = (List*)malloc(sizeof(List));
    l->curr = l->tail = l->head = NULL;
    l->count = 0;
    return l;
}

void insert(List* l, char c){
    Node* new_node = create_node(c);
    if (l->head == NULL) {
        l->head = l->tail = l->curr = new_node;
    }
    else if (l->curr == l->tail){
        l->tail->next = new_node;
        l->tail = new_node;
        l->curr = new_node;
    }
    else{
        new_node->next = l->curr->next;
        l -> curr -> next = new_node;
        l->curr = new_node;
    }
    l -> count++;
}

void move_to_start(List* l) {
    l->curr = l->head;
}

void move_to_end(List* l) {
    l->curr = l->tail;
}

void clear(List* l) {
    if (l == NULL) {
        return;
    }
    
    Node* current = l->head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    free(l);
}

void printlist(List* l) {
    Node* current = l->head;

    while (current != NULL) {
        printf("%d ", current->element);
        current = current->next;
    }
    printf("\n");
}
