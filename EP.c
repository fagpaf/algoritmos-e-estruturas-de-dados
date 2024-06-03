#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Entry
{
    int key;
    int value;
    int ocupied;
} Entry;

typedef struct Dictionary
{
    int m;
    int cnt;
    Entry* H;
} Dictionary;

int h(int key, int mod);
Dictionary* create_dict(int size);

int main(){

    int m, n;
    scanf("%d", &m);
    Dictionary* d = create_dict(m);
    int* perm = (int*)malloc((m - 1) * sizeof(int));    
    for(int i = 0; i < m - 1; i++){
        int  enter;
        scanf("%d", &enter);
        perm[i] = enter;
    }    

    scanf("%d", n);
    char str[5];
    char add[4] = "add";
    char find[5] = "find";
    while (n-- > 0){
        scanf("%s", str);        
        if(strcmp(str, add) == 0){
            // insert();
            
        }
        if(strcmp(str, find) == 0){
            // find()
            // if
            // printf(idx)
            // else
            // printf(-1)
        }
    }
    

    return 0;

}
int h(int key, int mod){
    int temp = (int) floor((((double) key) / ((double) mod)));
    return (key - (mod * temp)); 
    }

Dictionary* create_dict(int size){
    Dictionary* d = (Dictionary*)malloc(sizeof(Dictionary));
    d->m = size;
    d->cnt = 0;
    d->H = (Entry*)malloc((size - 1) * sizeof(Entry)); // conferir se isso voga msm
    for(int i = 0; i < size; i++){
        d->H[i].ocupied = 0; // Quando tiver ocupado muda para '1'
    }
    return d;
}

void insert(Dictionary* d, int key){

    return 0;
}

void find(){

}
