#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int(*HashFunction)(char* key, int m);

typedef struct Entry{
    int key;
    int value;
    int occupied;        // Flag para verificar se o entry está ocupado
} Entry;

typedef struct Dictionary{
    int m;
    int cnt;
    int* Perm;
    Entry* H;
    HashFunction hashFun;
} Dictionary;

int h(char* key, int m);

int main() {

    
    
    return 0;
}

int h(char* key, int m){
    int s = strlen(key);
    int sum = 0;
    for(int i = 0; i < s-1; i++){
        sum += sum + key[i];       // A função soma os valores dos caracteres em ASCII
    }
    printf("%d\n", sum);
    return abs(sum)%m;
}

int* create_permutation(int size){ // Cria uma permutação baseada no algoritmo de Fischer-Yates
    int* perm = (int*)malloc((size-1) * sizeof(int));
    for(int i = 0; i < size - 1; i++){
        perm[i] = i + 1;  // Atribui a cada posição o valor correspondente (1, 2, 3, ..., size-1)
    }
    // Algoritmo de Fischer-Yates
    for(int i = size - 2; i > 0; i--){
        int j = rand() % (i+1);   // Gera um índice aleatório 'j' entre 0 e 'i' 
        int temp = perm[i];
        perm[i] = perm[j];
        perm[j] = temp;
        // Esse 'for' faz o embaralhamento do array trocando
    }
    return perm;
}

Dictionary* create_dict(int size, int(*hash)(char*, int)){
    Dictionary* d = (Dictionary*)malloc(size * sizeof(Dictionary));
    d->m = size;
    d->cnt = 0;
    d->H = (Entry*)malloc(sizeof(Entry));
    d->Perm = create_permutation(size);
    d->hashFun = hash;
    return d;
}

