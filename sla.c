#include <stdio.h>
#include <stdalign.h>
#include <string.h>

#define TAM 100 // Defina o tamanho do dicionário conforme necessário

// Estrutura do nó
typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

// Estrutura da lista de cabeçalhos
typedef struct {
    Node* head;
} List;

// Estrutura do dicionário
typedef struct {
    List* H;
    int cnt;
} Dictionary;

// Função de hash
int hash(char* str) {
    // Implemente sua função de hash aqui
    int h = 0;
    while (*str) {
        h = (h * 31 + *str++) % TAM;
    }
    return h;
}

// Função para criar o dicionário
Dictionary* createDict(int size) {
    Dictionary* d = (Dictionary*)malloc(sizeof(Dictionary));
    d->H = (List*)malloc(size * sizeof(List));
    d->cnt = 0;
    for (int i = 0; i < size; i++) {
        d->H[i].head = (Node*)malloc(sizeof(Node));
        d->H[i].head->next = NULL;
    }
    return d;
}

// Função para inserir um valor no dicionário
void insertDict(Dictionary* d, char* key, int value) {
    int h = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = d->H[h].head->next;
    d->H[h].head->next = newNode;
    d->cnt++;
}

// Função para remover uma chave do dicionário
void remove_key(Dictionary* d, char* key) {
    int h = hash(key);
    Node* current = d->H[h].head->next;
    Node* prev = d->H[h].head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            prev->next = current->next;
            free(current->key);
            free(current);
            d->cnt--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Função para liberar a memória do dicionário
void clearDict(Dictionary* d) {
    for (int i = 0; i < TAM; i++) {
        Node* current = d->H[i].head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(d->H);
    free(d);
}

int main() {
    Dictionary* d = createDict(TAM);
    
    int test, n1;
    scanf("%d", &test);

    char input[20];
    char command[4];
    char str[16];
    
    for (int i = 0; i < test; i++) {
        scanf("%d", &n1);
        for (int j = 0; j < n1; j++) {
            scanf("%s", input);
            sscanf(input, "%3s:%15s", command, str);
            if (strcmp(command, "ADD") == 0) {
                int h = hash(str);
                insertDict(d, str, h);
            } else if (strcmp(command, "DEL") == 0) {
                remove_key(d, str);
            }
        }
    }

    printf("%d\n", d->cnt);

    for (int i = 0; i < TAM; i++) {
        Node* current = d->H[i].head->next;
        while (current != NULL) {
            printf("%d:%s\n", current->value, current->key);
            current = current->next;
        }
    }
    
    clearDict(d);
    return 0;
}
// gcc sla.c -o sla.exe ; Get-Content input.txt | ./sla.exe