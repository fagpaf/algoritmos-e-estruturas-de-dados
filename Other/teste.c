#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Boolean{
    False = 0,
    True
};

void heapify(int H[], int length);
void del(int H[], int* length);


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
        heapify(arr, length); // Deixando a min heap pronta para resolver a questão

        int cost = 0, current = 0, idx = 0;
        int add [length/2]; 
        int count = length;
        while(count > 0){

            if(cost == 0){ // ok
                current = arr[1] + arr[2];
                add[idx] = current;
                cost += current;
                del(arr, &length); // passando o endereço da variável 'length'
            }
            
            else if(add[idx] < arr[2]){
                current = arr[1] + add[idx]; 
                add[idx] = 0;
                idx++;        
                cost += current;
                del(arr, &length);
            }
            else{
                del(arr, &length);
                current = arr[1] + arr[2];
                cost += current;
            }
            count--;
        }

        printf("%d\n", cost);
        scanf("%d", &operations);
        if(operations == 0){
            loop = False;
        }
    }
    return 0;
}
// gcc teste.c -o teste.exe ; Get-Content input.txt | ./teste.exe

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