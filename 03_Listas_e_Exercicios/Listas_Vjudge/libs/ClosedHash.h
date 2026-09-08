#ifndef CLOSEDHASH_H
#define CLOSEDHASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int TAM = 101;

typedef int (*HashFunction)(char* key);

typedef struct Entry{
    char* key;
    int occupied;
} Entry;

typedef struct Dictionary{
    int m;
    int cnt;
    Entry* H;
    HashFunction hashFun;
} Dictionary;

Entry* create_entry(char* key);
Dictionary* create_dict(int size, int(*hash)(char*));
int search(Dictionary* d, char* key, int value);
void insert(Dictionary* d, char* key, int value);
void clearDict(Dictionary* d);
void remove_key(Dictionary* d, char* key, int value);
void printDict(Dictionary* d);
int hash(char* key);

int hash(char* key){ // ok
    int value = 0;
    int length = strlen(key);
    for (int i = 0; i < length; i++){
        value += (key[i] *(i + 1));   
    }
    value *= 19;
    return value % TAM;
}

Entry* create_entry(char* key){ // *
    if(key == NULL || strlen(key) == 0){
        return NULL;
    }
    Entry* e = (Entry*)malloc(sizeof(Entry));
    e->key = (char*)malloc(strlen(key) + 1);
    strcpy(e->key, key);
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

int search(Dictionary* d, char* key, int value){ //ok
    for(int i = 0; i < 20; i++){
        int pos = (value + i*i + 23*i) % d->m;
        if(pos < 0){
            pos += d->m;
        }
        if(d->H[pos].occupied == 1){
            if(strcmp(d->H[pos].key, key) == 0){ 
                return pos;
            }
            else if(i == 19){
                return -1;
            }
        }   
    }
    return -1;
}

void insert(Dictionary* d, char* key, int value){ //ok
    if (d->cnt < d->m && search(d, key, value) == -1){
        for(int i = 0; i < 20; i++){
            int pos = (value + i*i + 23*i) % d->m;
            if(d->H[pos].occupied != 1){
                Entry* entry = create_entry(key);
                if(entry == NULL){
                    return;
                }
                d->H[pos] = *entry;
                d->cnt++;
                return;
            }
        }
    }
}

void remove_key(Dictionary* d, char* key, int value){
    int idx = search(d, key, value);
    if(idx != -1){
        d->H[idx].key = "";
        d->H[idx].occupied = -1;
        d->cnt--;
    }
}

void printDict(Dictionary* d){
    printf("%d\n", d->cnt);
    for(int i =0; i < d->m; i++){
        if(d->H[i].occupied == 1){
            printf("%d:%s\n", i, d->H[i].key);
            d->H[i].occupied = 0;
        }
    }
}

void clearDict(Dictionary* d){// ok
    free(d->H);
    free(d);
}
#endif