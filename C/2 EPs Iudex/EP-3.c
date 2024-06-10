#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int(*HashFunction)(int key, int mod);

typedef struct Entry{
    int key;
    int value;
    int occupied;
} Entry;

typedef struct Dictionary{
    int m;
    int cnt;
    int* Perm;
    Entry* H;
    HashFunction hashFun;
} Dictionary;

int h(int key, int mod);
Entry* create_entry(int key, int value);
Dictionary* create_dict(int size, int(*hash)(int, int));
int search(Dictionary* d, int key);
void insert(Dictionary* d, int key, int value);
void clearDict(Dictionary* d);

int main(){ // Erro no case 3

    int m;
    scanf("%d", &m);

    new_dict: // Etiqueta para retornar a esta linha
    Dictionary* d = create_dict(m, h);
    for(int i = 0; i < m - 1; i++){
        scanf("%d", &d->Perm[i]);
    }
    int n;
    scanf("%d", &n);
    char str[5];
    char add[4] = "add";
    char find[5] = "find";
    
    int operations = n;
    while (operations-- > 0){
        scanf("%s", str);
        if(strcmp(str, add) == 0){
            int key, value;
            scanf("%d %d", &key, &value);
            insert(d, key, value);
        }
        else if(strcmp(str, find) == 0){
            int key_search;
            scanf("%d", &key_search);
            int idx = search(d, key_search);
            if (idx != -1){
                printf("%d %d\n", idx, d->H[idx].value);
            }
            else{
                printf("-1\n");
            }
        }
    }   
    scanf("%d", &m);
    if(m != 0){
        clearDict(d);
        goto new_dict;
    }
    return 0;
}
// gcc EP-3.c -o EP-3.exe ; Get-Content input3.txt | ./EP-3.exe


int h(int key, int mod){
    int temp = (int) floor((((double) key) / ((double) mod)));
    return (key - (mod * temp)); 
    }

Entry* create_entry(int key, int value){
    Entry* e = (Entry*)malloc(sizeof(Entry));
    e->key = key;
    e->value = value;
    e->occupied = 1; // terei q adequar o valor disso 
    return e;
}

Dictionary* create_dict(int size, int(*hash)(int, int)){
    Dictionary* d = (Dictionary*)malloc(sizeof(Dictionary));
    d->m = size;
    d->cnt = 0;
    d->H = (Entry*)malloc(size * sizeof(Entry));
    d->Perm = (int*)malloc(size * sizeof(int));
    d->hashFun = hash;
    for(int i = 0; i < size; i++){
        d->H[i].occupied = 0;
    }
    return d;
}

int search(Dictionary* d, int key){
    for (int i = 0; i < d->m; i++){
        if (d->H[i].key == key){ 
            return i;
        }
    }
    return -1;
}

void insert(Dictionary* d, int key, int value){
    if (d->cnt < d->m && search(d, key) == -1){
        int pos = d->hashFun(key, d->m);
        if (d->H[pos].occupied != 0){ // conferir o valor de 'occupied'
            int i = 0;
            int new_pos;
            do{
                i = i + 1;
                int offset = d->Perm[i - 1]; // Gera um número aleatório entre 0 e m-1
                new_pos = (pos + offset) % d->m;
                if (new_pos < 0){
                    new_pos += d->m;
                }
            } while(d->H[new_pos].occupied == 1);
            pos = new_pos;        
        }
        Entry* entry = create_entry(key, value);
        d->H[pos] = *entry;
        // Como 'entry' é um ponteiro para struct "Entry" é preciso desreferenciar ele, para acessar apenas o valor dele q é do tipo 'struct'
        d->cnt++;
    }
}
void clearDict(Dictionary* d){
    free(d->H);
    free(d->Perm);
    free(d);
}