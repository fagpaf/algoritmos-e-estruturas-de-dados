#include "libs/Heap.h"

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

        int cost = 0, current = 0;
        int count = length;
        while(count > 2){
            current = arr[1];
            del(arr, &length); // o 'arr[1]' vira o próximo menor elemento
            current += arr[1]; // fazendo a soma dos dois menores valores da heap
            arr[1] = current;  // inserindo o valor somado na heap novamente
            cost += current;
            heapify(arr, length); // refazendo a min heap para o próximo caso
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

// gcc L4--Q2.c -o L4--Q2.exe ; Get-Content input.txt | ./L4--Q2.exe

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
// }// int main() {
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