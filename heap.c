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
        bottomUp(arr, length); // Deixando a min heap pronta para resolver a questão

        // Tô errando a soma
        int cost = 0, current = 0;
        int add = arr[1]; // 'add' recebe a raiz da min heap, pois ela já está pronta
        del(arr, length); // deletando para quando entrar no loop formar a min heap
        for(int i = 1; i < length - 1; i++){
            bottomUp(arr, length);
            if(add > arr[2]){
                current = arr[1] + arr[2];
                cost += current;
                del(arr, length);
            }
            else{
                current = arr[1] + add; // Soma o valor atual de 'add' com o primeiro elemento de 'arrcpy' e armazena em 'current'
                add = current;          // Atualiza 'add' com o valor de 'current' para fazer a soma do custo correto
                cost += current;
                del(arr, length);
            }
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

void del(int H[], int* length){
    H[1] = H[length -1]; // O primeiro recebe o último
    length--; //e decresce o tamanho do array
    heapify(H[], length);
}

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


// int main() {
//     int operations;
//     scanf("%d", &operations);

//     enum Boolean loop = True;
//     while(loop){
//         int length = operations + 1;
//         int arr[length];
//         arr[0] = -1;

//         for(int j = 1; j < length; j++){
//             scanf("%d", &arr[j]);
//         }
//         bottomUp(arr, length); // Deixando a min heap pronta para resolver a questão

//         int cost = 0;
//         int add = arr[1]; // 'add' recebe a raiz da min heap, pois ela já está pronta
//         int temp = length - 1; // Define 'temp' como a quantidade de elementos menos um (ignora o índice 0).

        // for(int i = 1; i < length - 1; i++){
        //     // Declara um array cópia 'arrcpy' com tamanho 'temp'
        //     int arrcpy[temp];

        //     // Copia 'temp' elementos do array 'arr' começando do índice 'i' para 'arrcpy'
        //     memcpy(arrcpy, arr + i, temp * sizeof(int));
            
        //     // Soma o valor atual de 'add' com o primeiro elemento de 'arrcpy' e armazena em 'current'
        //     int current = add + arrcpy[1];
            
        //     // Atualiza 'add' com o valor de 'current' para fazer a soma do custo correto
        //     add = current;
            
        //     cost += current;
        //      // Constrói uma heap a partir do array 'arrcpy' com 'temp' elementos
        //     bottomUp(arrcpy, temp);
            
        //     temp--;// Reduz o valor de 'temp' para diminuir o tamanho do array a ser copiado na próxima iteração
        // }   
//         printf("%d\n", cost);
//         scanf("%d", &operations);
//         if(operations == 0){
//             loop = False;
//         }
//     }
//     return 0;
// }