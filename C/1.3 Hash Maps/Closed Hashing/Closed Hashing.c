#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DELETED -1

typedef int(*HashFunction)(int key, int mod); // Definindo o tipo do ponteiro para função

typedef struct Entry{ // Estrutura para entrada Para acessar os membros dela é  só usar 'Entry.key'...
    int key;
    int value;
    int occupied;        // Flag para verificar se a entrada está ocupada
} Entry;

typedef struct Dictionary{
    int m;      // capacidade da hash table
    int cnt;    // tamnho atual da tabela
    int* Perm;  // ponterio para o array, q será permutado
    Entry* H;   // minha Hash Table
    HashFunction hashFun; // passando a função hash para o dicionário
} Dictionary;

int h(int key, int mod);
Entry* create_entry(int key, int value);
Dictionary* create_dict(int size, int(*hash)(int, int));
int find(Dictionary* d, int key);
void insert(Dictionary* d, int key, int value);

int main() {

    
    
    return 0;
}

int h(int key, int mod){
    int temp = (int) floor((((double) key) / ((double) mod)));
    return (key - (mod * temp)); // retorna o valor da chave
}

Entry* create_entry(int key, int value){
    Entry* e = (Entry*)malloc(sizeof(Entry));
    e->key = key;
    e->value = value;
    e->occupied = 0; // terei q adequar o valor disso 
    return e;
}

Dictionary* create_dict(int size, int(*hash)(int, int)){
    Dictionary* d = (Dictionary*)malloc(sizeof(Dictionary));
    d->m = size;
    d->cnt = 0;
    d->H = (Entry*)malloc(size * sizeof(Entry));
    d->Perm = (int*)malloc((size-1) * sizeof(int));
    d->hashFun = hash;
    for(int i = 0; i < size - 1; i++){
        d->H[i].occupied = -1;
    }
    return d;
}

int find(Dictionary* d, int key){
    for (int i = 0; i < d->m - 1; i++){
        if (d->H[i].key == key){ // 'd->H[i].occupied != 0' verifica para n ocorrer colisão
            return i;
        }
    }
    return -1;
}

void insert(Dictionary* d, int key, int value){
    if (d->cnt < d->m && find(d, key) == -1){
        int pos = d->hashFun(key, d->m);
        if (d->H[pos].occupied != -1 && d->H[pos].key != DELETED){ // conferir o valor de 'occupied'
            int new_pos;
            do{
                int offset = rand() % d->m; // Gera um número aleatório entre 0 e m-1
                new_pos = (pos + offset) % d->m;
                if (new_pos < 0){
                    new_pos += d->m;
                }
            } while(d->H[new_pos].occupied != -1 || d->H[new_pos].key != DELETED); // pelo slide 'repeat, until' é um "do while" com uma negação
            pos = new_pos;        
        }
        Entry* entry = create_entry(key, value);
        d->H[pos] = *entry;
        // Como 'entry' é um ponteiro para struct "Entry" é preciso desreferenciar ele, para acessar apenas o valor dele q é do tipo 'struct'
        d->cnt++;
    }
}

void clearDict(Dictionary* d){

}