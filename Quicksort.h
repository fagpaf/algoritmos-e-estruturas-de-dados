#ifndef QUICKSORT_H
#define QUICKSORT_H

void swap(Entry *a, Entry *b);
void Quicksort(Entry A[], int l, int r);
int HoareParticion(Entry A[], int l, int r);

void Quicksort(Entry A[], int l, int r){
    if (l < r){
        int s = HoareParticion(A, l, r);
        Quicksort(A, l, s - 1);
        Quicksort(A, s + 1, r);
    }
}

int HoareParticion(Entry A[], int l, int r){
    int pivo = A[l].value;
    int i = l;
    int j = r + 1;
    while (!(i >= j)){
        do { 
            i++;
        } while (!(A[i],value >= pivo || i >= r));
        do{
            j--;
        } while (!(A[j].value <= pivo));
        swap(&A[i], &A[j]); 
    }
    swap(&A[i], &A[j]); 
    swap(&A[l], &A[j]); 
    return j;
}

void swap(Entry *a, Entry *b) {
    Entry temp = *a;
    *a = *b;
    *b = temp;
}
#endif