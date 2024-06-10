#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int TAM = 101;

typedef int (*HashFunction)(char* key);

typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    Node* curr;
    int count;          
} List;

typedef struct Dictionary{
    int m;
    int cnt;
    HashFunction hashFun;
    List** H;
} Dictionary;

Node* create_node(Node* n, char* str, int value);
Node* create_header(Node* nextval);
List* create_list();
void append(List* l, char* str, int value);
char* del(List* l);
void printlist(List* l);
Dictionary* createDict(int size, int(*hash)(char*));
int find(Dictionary* d, char* key);
void insertDict(Dictionary* d, char* key, int value);
void remove_key(Dictionary* d, char* key);
void clearDict(Dictionary* d);
int hash(char* key);

int main() {

    Dictionary* d = createDict(TAM, hash);
    
    int test, n1;
    scanf("%d", &test);

    char input[20];
    char command[4];
    char str[16];
    
    for(int i = 0; i < test; i++){
        scanf("%d", &n1);
        for(int j = 0; j < n1; j++){
            scanf("%s", input);
            sscanf(input, "%3s:%15s", command, str);
            if (strcmp(command, "ADD") == 0){
                int h = hash(str);
                insertDict(d, str, h);
            }
            else if (strcmp(command, "DEL") == 0){
                remove_key(d, str);
            }
        }
    }
    printf("%d\n", d->cnt);

    for(int i = 0; i < TAM; i++){
        Node* current = d->H[i]->head->next;
        while(current != NULL){
            printf("%d:%s\n", current->value, current->key);
            current = current -> next;
        }
    }
    clearDict(d);
    return 0;
}
// gcc Q1.c -o Q1.exe ; Get-Content input.txt | ./Q1.exe

int hash(char* key){
    int value = 0;
    int length = strlen(key);
    for (int i = 0; i < length; i++){
        value += (key[i] *(i + 1));        
    }
    value *= 19; 
    return value % TAM;
}

Node* create_node(Node* n, char* str, int value){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node -> key = str;
    new_node -> next = n;
    new_node -> value = value;
    return new_node;
}

Node* create_header(Node* nextval){
    Node* header = (Node*)malloc(sizeof(Node));
    header->next = nextval;
    return header;
}

List* create_list(){
    List* l = (List*) malloc(sizeof(List));
    l -> curr = l -> tail = l -> head = create_header(NULL); // Inicializa a lista como NULL
    l -> count = 0;   // Inicializa o contador de nós como 0
    return l;
}

void append(List* l, char* str, int value){
    l->curr = l->tail;
    Node* new_node = create_node(NULL,str, value);
    if (l->head->next == NULL) {
        l->head->next = new_node;
        l->tail = new_node;
    } else {
        l->tail->next = new_node;
        l->tail = new_node; 
    }
    l->count++;
}

char* del(List* l){
    l->curr = l->head;
    Node* temp = l->curr->next;
    char* str = temp->key;
    if (l -> tail == temp){
        l->tail = l->curr;
    }
    l -> curr -> next = temp -> next;
    free(temp);   
    l -> count--;
    return str;
}

void printlist(List* l){
    Node* current = l -> head->next;
    while(current != NULL){
        printf("%d:%s\n", current->value, current->key);
        current = current -> next;
    }
    // printf("\n");
}

Dictionary* createDict(int size, int(*hash)(char*)){
    Dictionary* d = (Dictionary*)malloc(sizeof(Dictionary));
    d->m = size;
    d->cnt = 0;
    d->H = (List**)malloc(d->m * sizeof(List*)); // 'sizeof(struct List*)' retorna o tamanho em bytes de um ponteiro para struct List
    // Multiplicando esse tamanho por 'd->m', q é o tamanho da tabela temos reservado o tamanho necessário para armazenar nossa tabela
    for(int i = 0; i < size; i++){
        d->H[i] = create_list(); // 'H[i]' é um bucket que pode conter uma lista encadeada de nós
    }
    d->hashFun = hash;
    return d;
}

int find(Dictionary* d, char* key) {
    for(int i = 0; i < d->m; i++){
        Node* current = d->H[i]->head->next;
        while(current != NULL){
            if (strcmp(current->key, key) == 0) {
                return i;
            }
            current = current->next;
        }
    }
    return -1;
}

void insertDict(Dictionary* d, char* key, int value){
    if (find(d, key) == -1){
        for (int j = 1; j < 20; j++){
            int pos = (value + (int)pow(j, 2) + 23*j) % 101; // Type cast para int pq pow() é real
            if (d->H[pos]->head->next == NULL){ // mt burro
                List* l = d->H[pos];
                append(l, key, value);
                d->cnt++;
                return;
            }
        }
    }
}

void remove_key(Dictionary* d, char* key){ // mexer aq
    int search = find(d, key);
    if(search != -1){
        del(d->H[search]);
        d->cnt--;
    }
}

void clearDict(Dictionary* d){
    for (int i = 0; i < d->m; i++){
        Node* node = d->H[i]->head;
        while(node!=NULL){
            Node* next_node = node->next;
            free(node);
            node = next_node;
        }
        free(d->H[i]);
    }
    free(d->H);
    free(d);
}