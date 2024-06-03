#include <stdio.h>
#include <string.h>

void print_list(int A[], int length);
void Mergesort(int A[], int l, int r);
void Merge(int A[], int l, int r);

int main() {

    int arr[5] = {5, 2, 1, 7, 0};
    int length = sizeof(arr) / sizeof(arr[0]);
    print_list(arr, length);

    Mergesort(arr, 0, length - 1);
    printf("Array ordenado:");
    print_list(arr, length);

    return 0;
}

void Mergesort(int A[], int l, int r){

    if (l < r){
        
        int meio = (l + r) / 2;
        
        Mergesort(A, l, meio);

        Mergesort(A, meio + 1, r);

        Merge(A, l, r);
    }
}

void Merge(int A[], int l, int r){

    int temp[r+1];
    
    //  void *memcpy(void *dest, const void *src, size_t count);

    memcpy(temp, A, (r+1) * sizeof(int)); // Precisa da biblbioteca <string.h>

    int meio = (l + r) / 2;

    int i1 = l;
    int i2 = meio + 1; 

    for (int j = l; j <= r; j++){ // tinha erro

        // Caso a primeira metade seja totalmente utilizada
        if (i1 == meio + 1){
            
            temp[j] = A[i2];
            i2++;
        }
        // Caso a segunda metade seja totalmente utilizada
        else if(i2 > r){
            
            temp[j] = A[i1];
            i1++;
        }
        // Caso o elemento da primeira metade seja menor ou igual ao elemento da segunda metade
        else if(A[i1] <= A[i2]){
            temp[j] = A[i1];
            i1++;
        }
        // Caso o elemento da segunda metade seja menor que o elemento da primeira metade
        else{
            temp[j] = A[i2];
            i2++;
        }
    }
    // Copiando os elementos mesclados de volta para o array original
    for(int cursor = 0; cursor <= r; cursor++){// tinha erro

        A[cursor] = temp[cursor];
    }
    free(temp);
}

void print_list(int arr[], int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%d", arr[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}