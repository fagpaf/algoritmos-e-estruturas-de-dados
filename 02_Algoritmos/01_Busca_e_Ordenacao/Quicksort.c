// #include <stdio.h>

// void print_list(int A[], int length);
// void swap(int *a, int *b);
// void Quicksort(int A[], int l, int r);
// int HoareParticion(int A[], int l, int r);

// int main() {

//     int arr[10] = {2, 8, 15, 7, 9, 1, 3, 10, 16, 0};
//     int length = sizeof(arr)/ sizeof(arr[0]);
//     print_list(arr, length);

//     Quicksort(arr, 0, length - 1);

//     print_list(arr, length);
//     return 0;
// }

// void Quicksort(int A[], int l, int r){
//     if (l < r){
//         int s = HoareParticion(A, l, r);
//         Quicksort(A, l, s - 1);
//         Quicksort(A, s + 1, r);
//     }
// }

// int HoareParticion(int A[], int l, int r){
//     int pivo = A[l];
//     int i = l;
//     int j = r + 1;
//     while (!(i >= j)){
//         do { 
//             i++;
//         } while (!(A[i] >= pivo || i >= r));
//         do{
//             j--;
//         } while (!(A[j] <= pivo));
//         swap(&A[i], &A[j]); 
//     }
//     swap(&A[i], &A[j]); 
//     swap(&A[l], &A[j]); 
//     return j;
// }

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void print_list(int arr[], int length) {
//     printf("[");
//     for (int i = 0; i < length; i++) {
//         printf("%d", arr[i]);
//         if (i < length - 1) {
//             printf(", ");
//         }
//     }
//     printf("]\n");
// }

#include <stdio.h>

void print_list(int A[], int length);
void swap(int *a, int *b);
void Quicksort(int A[], int l, int r, int depth, int length);
int HoareParticion(int A[], int l, int r);

int main() {
    int arr[10] = {2, 8, 15, 7, 9, 1, 3, 10, 16, 0};
    int length = sizeof(arr)/ sizeof(arr[0]);
    
    printf("Antes da ordenação:\n");
    print_list(arr, length);

    Quicksort(arr, 0, length - 1, 0, length);

    printf("Depois da ordenação (parcial - até 4 partições):\n");
    print_list(arr, length);
    return 0;
}

void Quicksort(int A[], int l, int r, int depth, int length){
    if (l < r && depth < 4){
        int s = HoareParticion(A, l, r);
        
        // Mostrar a lista após cada particionamento
        printf("depth=%d, l=%d, r=%d, s=%d -> ", depth, l, r, s);
        print_list(A, length);
        
        // Chamadas recursivas com incremento na profundidade
        Quicksort(A, l, s - 1, depth + 1, length);
        Quicksort(A, s + 1, r, depth + 1, length);
    }
}

int HoareParticion(int A[], int l, int r){
    int pivo = A[l];
    int i = l;
    int j = r + 1;
    while (!(i >= j)){
        do { 
            i++;
        } while (!(A[i] >= pivo || i >= r));
        do{
            j--;
        } while (!(A[j] <= pivo));
        swap(&A[i], &A[j]); 
    }
    swap(&A[i], &A[j]); 
    swap(&A[l], &A[j]); 
    return j;
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
