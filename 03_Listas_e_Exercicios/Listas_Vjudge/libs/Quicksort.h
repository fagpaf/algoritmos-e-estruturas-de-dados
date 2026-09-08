#ifndef QUICKSORT_H
#define QUICKSORT_H

void swap(int *a, int *b);
void Quicksort(int A[], int l, int r);
int HoareParticion(int A[], int l, int r);

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

#endif