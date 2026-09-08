#include <stdio.h>
#include "libs/Quicksort.h"
#include "libs/BinarySearch.h"

int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    Quicksort(arr, 0, n-1);

    int length = sizeof(arr) / sizeof(arr[0]);
    int idx = 0;
    for(int j = 0; j < n - 1; j++){
         
        int alvo = arr[j] + k; // Variável dentro do array q vai satisfazer a "subtração", q vai ter como resultado "k"
        
        int result_search = binary_search(arr, length, alvo); // utilizando a busca binária por ser O(log n)
        
        if(alvo == result_search){ // caso o valor seja encontrado dentro do array acrescenta +1 no contador
            idx++;
        }
    }
    printf("%d", idx);
    return 0;
}