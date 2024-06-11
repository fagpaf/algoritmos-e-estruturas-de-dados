#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int (*HashFunction)(char* key);

typedef struct Entry{
    char* key;
    int value;
    int occupied;
} Entry;

typedef struct Dictionary{
    int m;
    int cnt;
    Entry* H;
    HashFunction hashFun;
} Dictionary;

Entry* create_entry(char* key, int value);
Dictionary* create_dict(int size, int(*hash)(char*));
int search(Dictionary* d, char* key);
void insert(Dictionary* d, char* key, int value);
void clearDict(Dictionary* d);
void remove_key(Dictionary* d, char* key);
void printDict(Dictionary* d);
void swap(Entry *a, Entry *b);
void Quicksort(Entry A[], int l, int r);
int HoareParticion(Entry A[], int l, int r);

const int TAM = 101;

int hash(char* key);

int main() {

    int test, n1;
    scanf("%d", &test);

    char input[20];
    char command[4];
    char str[16];
    
    for(int i = 0; i < test; i++){
        scanf("%d", &n1);
        Dictionary* d = create_dict(TAM, hash);
        for(int j = 0; j < n1; j++){
            scanf("%s", input);
            sscanf(input, "%3s:%15s", command, str);
            if (strcmp(command, "ADD") == 0){
                int h = hash(str);
                insert(d, str, h);
            }
            else if (strcmp(command, "DEL") == 0){
                remove_key(d, str);
            }
        }
        printf("%d\n", d->cnt);
        printDict(d);
        clearDict(d);
    }
    return 0;
}

int hash(char* key){ // ok
    int value = 0;
    int length = strlen(key);
    for (int i = 0; i < length; i++){
        value += (key[i] *(i + 1));   
    }
    value *= 19;
    return value % TAM;
}

Entry* create_entry(char* key, int value){ // ok
    Entry* e = (Entry*)malloc(sizeof(Entry));
    e->key = strdup(key);
    e->value = value;
    e->occupied = 1;
    return e;
}

Dictionary* create_dict(int size, int(*hash)(char*)){ // ok
    Dictionary* d = (Dictionary*)malloc(sizeof(Dictionary));
    d->m = size;
    d->cnt = 0;
    d->H = (Entry*)malloc(size * sizeof(Entry));
    d->hashFun = hash;
    return d;
}

int search(Dictionary* d, char* key){ //ok
    for(int i = 0; i < d->m; i++){
        if(d->H[i].occupied == 1){
            if(strcmp(d->H[i].key, key)== 0){ 
                return i;
            }
        }   
    }
    return -1;
}

void insert(Dictionary* d, char* key, int value){ //ok
    if (d->cnt < d->m && search(d, key) == -1){
        for(int i = 1; i < 20; i++){
            int pos = (value + i*i + 23*i) % d->m;
            if(d->H[pos].occupied != 1){
                Entry* entry = create_entry(key, value);
                d->H[pos] = *entry;
                free(entry);
                d->cnt++;
                return;
            }
        }
    }
}

void remove_key(Dictionary* d, char* key){
    int idx = search(d, key);
    if(idx != -1){
        free(d->H[idx].key);
        d->H[idx].occupied = 0;
        d->cnt--;
    }
}

void printDict(Dictionary* d){
    Entry* entries = (Entry*)malloc((d->cnt) * sizeof(Entry));
    int j = 0;
    for(int i =0; i < d->m; i++){
        if(d->H[i].occupied == 1){
            entries[j++] = d->H[i];
        }
    }
    Quicksort(entries, 0, d->cnt - 1);

    for (int i = 0; i < d->cnt; i++) {
        printf("%d:%s\n", entries[i].value, entries[i].key);
    }
    free(entries);
}

void Quicksort(Entry A[], int l, int r){
    if (l < r){
        int s = HoareParticion(A, l, r);
        Quicksort(A, l, s - 1);
        Quicksort(A, s + 1, r);
    }
}

int HoareParticion(Entry A[], int l, int r){
    int pivo = A[l].value;
    int i = l;
    int j = r + 1;
    while (!(i >= j)){
        do { 
            i++;
        } while (!(A[i].value >= pivo || i >= r));
        do{
            j--;
        } while (!(A[j].value <= pivo));
        swap(&A[i], &A[j]); 
    }
    swap(&A[i], &A[j]); 
    swap(&A[l], &A[j]); 
    return j;
}

void swap(Entry *a, Entry *b) {
    Entry temp = *a;
    *a = *b;
    *b = temp;
}

void clearDict(Dictionary* d){ // ok
    for (int i = 0; i < d->cnt; i++) {
        if (d->H[i].occupied == 1){
            free(d->H[i].key);
        }
    }
    free(d->H);
    free(d);
}
