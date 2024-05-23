#include <stdio.h>

void swap(int *a, int *b);
void Quicksort(int A[], int l, int r);
int binary_search(int arr[], int length, int alvo);
int HoareParticion(int A[], int l, int r);

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

int binary_search(int arr[], int length, int alvo){
    int baixo = 0;
    int alto = length - 1;

    while (baixo <= alto){
        int meio = (baixo + alto) / 2;
        int chute = arr[meio];

        if(chute == alvo){
            return chute;
        }
        else if(chute > alvo){
            alto = meio -1;
        }
        else{
            baixo = meio + 1;
        }
    }
    return 0;
}