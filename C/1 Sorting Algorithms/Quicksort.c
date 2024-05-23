#include <stdio.h>

void print_list(int A[], int length);
void swap(int *a, int *b);
void Quicksort(int A[], int l, int r);
int HoareParticion(int A[], int l, int r);

int main() {

    int arr[7] = {7, 1, 3, 1, 4, 10, 8};
    int length = sizeof(arr)/ sizeof(arr[0]);
    print_list(arr, length);

    Quicksort(arr, 0, length - 1);

    print_list(arr, length);
    return 0;
}

void Quicksort(int A[], int l, int r){

    if (l < r){
        
        int s = HoareParticion(A, l, r);
        
        // Chama recursivamente a função para ordenar as partições à esquerda e à direita do pivô
        Quicksort(A, l, s - 1);

        Quicksort(A, s + 1, r);
    }
}

int HoareParticion(int A[], int l, int r){
    
    int pivo = A[l];
    int i = l;
    int j = r + 1;

    while (!(i >= j)){
        
        // Enquanto i não ultrapassar j, o loop continua
        do { 
            i++;
        } while (!(A[i] >= pivo || i >= r));

        do{
            j--;
        } while (!(A[j] <= pivo));

        swap(&A[i], &A[j]); // Troca os elementos se i ainda não ultrapassou j

    }
    swap(&A[i], &A[j]); // Troca o pivô com o último elemento menor ou igual ao pivô

    swap(&A[l], &A[j]); // Coloca o pivô na posição correta
    

    return j; // Retorna o índice do pivô
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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