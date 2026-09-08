#ifndef QUICKSORT_H
#define QUICKSORT_H

void swap(int *a, int *b);
void Quicksort(int A[], int l, int r);
int HoareParticion(int A[], int l, int r);

void Quicksort(int A[], int l, int r){
    if (l < r){
        int s = HoareParticion(A, l, r);
        Quicksort(A, l, s - 1);
        Quicksort(A, s + 1, r);
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
#endif