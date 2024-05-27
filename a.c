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

Node* create_node(int num) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->element = num;
    new_node->next = NULL;
    return new_node;
}

List* create_list() {
    List* l = (List*)malloc(sizeof(List));
    l->curr = l->tail = l->head = NULL;
    l->count = 0;
    return l;
}

void insert(List* l, int num) {
    Node* new_node = create_node(num);
    
    if (l->head == NULL) { // Se a lista estiver vazia
        l->head = l->tail = l->curr = new_node;
    } else if (l->curr == l->tail) { // Se o cursor estiver no final
        l->tail->next = new_node;
        l->tail = new_node;
    } else {
        new_node->next = l->curr->next;
        l->curr->next = new_node;
    }
    
    l->count++;
}

void insert_at_start(List* l, int num) {
    Node* new_node = create_node(num);
    
    if (l->head == NULL) { // Se a lista estiver vazia
        l->head = l->tail = l->curr = new_node;
    } else {
        new_node->next = l->head;
        l->head = new_node;
    }
    
    l->count++;
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
        printf("%c", current->element); // Changed from %d to %c to print characters
        current = current->next;
    }
    printf("\n");
}

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

