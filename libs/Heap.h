#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

enum Boolean{
    False = 0,
    True
};

void heapify(int H[], int length);
void del(int H[], int* length);

void heapify(int H[], int length){  // MIN HEAP
    int n = length - 1;
    for(int i = n/2; i > 0; i--){
        int k = i;                  // Posição do nó atual com índice "i"
        int v = H[k];               // Valor do nó atual
        enum Boolean heap = False;
        while(!heap && 2*k <= n){ // Encontrando o local para o nó
            
            int j = 2*k;          // Posição do  primeiro filho
            if(j < n && H[j+1] < H[j]){ // Se "H[j+1] < H[j]" tem dois filhos encontra o menor filho 
                j++;
            }
            if(v <= H[j]){
                heap = True;          // É uma heap se 'v' for <= que o menor filho
            }
            else{
                // Coloca o menor filho em 'H[k]' e atualiza 'k'
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}

void del(int H[], int* length){
    H[1] = H[*length -1]; // O primeiro recebe o último
    (*length)--; // O tamanho do array é decrementado diretamente através do ponteiro, isso garante que a variável 'length' no 'main' seja atualizada
    // Os parênteses servem para desreferenciar o ponteiro antes de decrementar
    heapify(H, *length); 
}

#endif