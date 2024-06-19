#include <stdio.h>
#include <stdlib.h>

enum bool{
    False = 0,
    True
};

void bottomUp(int H[], int length);
void heapify(int H[], int length);

int main() {

    int H[8] = {-999, 2, 9, 7, 6, 5, 8, 10};
    // int H[5] = {-1, 10, 40, 50, 5};
    int length = sizeof(H)/sizeof(H[0]);
    bottomUp(H, length);
    for (int i = 1; i < length; i++){
        printf("%d ", H[i]);
    }
    
    return 0;
}

void heapify(int H[], int length){  // MIN HEAP
    int n = length - 1;
    for(int i = n/2; i > 0; i--){
        int k = i;                  // Posição do nó atual com índice "i"
        int v = H[k];               // Valor do nó atual
        enum bool heap = False;
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

void bottomUp(int H[], int length){
    heapify(H, length);
}

// void heapify(int H[], int length){  // MAX HEAP
//     int n = length - 1;
//     for(int i = n/2; i > 0; i--){
//         int k = i;                  // Posição do nó atual com índice "i"
//         int v = H[k];               // Valor do nó atual
//         enum bool heap = False;
//         while(!heap && 2*k <= n){ // Encontrando o local para o nó
            
//             int j = 2*k;          // Posição do  primeiro filho
//             if(j < n && H[j] < H[j+1]){ // Se "H[j] < H[j+1]" tem dois filhos encontra o filho maior
//                 j++;
//             }
//             if(v >= H[j]){
//                 heap = True;          // É uma heap se v for ≥ que o maior filho
//             }
//             else{
//                 // coloca o maior filho em 'H[k]' e atualiza "k"
//                 H[k] = H[j];
//                 k = j;
//             }
//         }
//         H[k] = v;
//     }
// }

