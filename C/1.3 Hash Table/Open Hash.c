#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bib/List.h"

// Fazer as alterações para o open hash e verificar oq eu alterei hj 


typedef struct Dictionary{
    int m;                // tamanho da tabela
    int cnt;              // 
    Node ** H;
} Dictionary;

int hashTable(int x, int size);

int main() {

    
    
    return 0;
}

int hashTable(int x, int size){
    int value = x % size;
    if(value < 0){
        value += size;
    }
    return value;
}

 Dictionary* create_dict(int size, int m){

}
