#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    
    // int arr[5];
    // arr[0] = -1;
    // for (int i = 1; i < 5; i++){
    //     arr[i] = i;
    // }


    
    // for (int i = 0; i <5; i++){
    //     printf("%d ", arr[i]);
    // }




    // Original array
    int arr[] = {-1, 1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);

    // Novo tamanho do array reduzido
    int temp = length -1;

    // Array para copiar
    int arrcpy[temp];

    // Copiando o array usando memcpy
    memcpy(arrcpy, arr + 1, temp * sizeof(int));

    // Verificando a cópia
    printf("Original array: ");
    for(int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    // arrcpy[0] = -9234;
    printf("\nCopied array: ");
    for(int i = 0; i < temp; i++){
        printf("%d ", arrcpy[i]);
    }







    // for (int i = 1; i <4; i++){
    //     printf("%d ", arr[i]);
    // }
    

    // int cost = 0;
    // int add = arr[1];
    // for (int i = 2; i < 5; i++){
    //     int current = add + arr[i];
    //     add = current;
    //     cost += current;
    // }
    // int cost = 0;
    // int add = 0;
    // int count = length;

    // while(count > 1){ // Continuar até que reste apenas um elemento
    //     bottomUp(arrcpy, count);
    //     int current = arrcpy[1] + arrcpy[2];
    //     add = current;
    //     cost += current;

    //     // Atualizar a heap: remover os dois menores e adicionar a soma
    //     arrcpy[1] = current;
    //     arrcpy[2] = arrcpy[count - 1]; // Mover o último elemento para a posição do segundo menor
    //     count--; // Reduz o tamanho da heap
    //     bottomUp(arrcpy, count); // Reorganizar a heap com o novo tamanho
    // }



    // printf("%d", cost);

    return 0;
}

/*
char *vnome;
    
    // Alocando espaço suficiente para armazenar a string
    vnome = (char *) malloc(30); // Supondo que a string tenha no máximo 30 caracteres

    fgets(vnome, 30, stdin); // "sizeof" é o tamanho máximo do buffer, "stdin" indica entrada padrão
    printf("%s", vnome);
    free(vnome);
    printf("%s", vnome);
------------------------------------------------------------
    int arr[3 +1] = {-1};
    for (int i = 1; i < 4; i++){
        arr[i] = i;
    }
    for (int i = 0; i <4; i++)
    {
        printf("%d ", arr[i]);
    }
    
*/
