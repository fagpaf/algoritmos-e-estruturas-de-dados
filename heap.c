#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Boolean{
    False = 0,
    True
};

void bottomUp(int H[], int length);
void heapify(int H[], int length);
void del(int H[], int length);

int main() {
    int operations;
    scanf("%d", &operations);

    enum Boolean loop = True;
    while(loop){
        int length = operations + 1;
        int arr[length];
        arr[0] = -1;

        for(int j = 1; j < length; j++){
            scanf("%d", &arr[j]);
        }
        bottomUp(arr, length); // Deixando a min heap pronta para resolver a questão

        // Tô errando a soma
        int cost = 0;
        int add = arr[1]; // 'add' recebe a raiz da min heap, pois ela já está pronta
        for(int i = 1; i < length - 1; i++){
            del(arr, length);
            bottomUp(arr, length);
            int current = add + arr[1]; // Soma o valor atual de 'add' com o primeiro elemento de 'arrcpy' e armazena em 'current'
            add = current;              // Atualiza 'add' com o valor de 'current' para fazer a soma do custo correto
            cost += current;
        }   
        printf("%d\n", cost);
        scanf("%d", &operations);
        if(operations == 0){
            loop = False;
        }
    }
    return 0;
}
// gcc heap.c -o heap.exe ; Get-Content input.txt | ./heap.exe

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

void bottomUp(int H[], int length){
    heapify(H, length);
}

void del(int H[], int length){
    H[1] = H[length -1]; // O primeiro recebe o último
    length--; //e decresce o tamanho do array
}