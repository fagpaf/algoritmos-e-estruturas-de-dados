#include <stdio.h>
#include <string.h>

void Quicksort(int A[], int l, int r);
int HoareParticion(int A[], int l, int r);
void swap(int *a, int *b);

int main() {

    int n, m;
    scanf("%d", &n);

    int ai[n]; // array dos valores de cada barra de chocolate
    
    long long custo_tot = 0; // long long para quando a soma do array seja mt grande
    
    for (int i=0; i < n; i++){
        scanf("%d", &ai[i]);
        custo_tot += ai[i]; // realizando a soma do array após a entrada para evitar um "for" futuro para dx mais rápido o algoritmo
    }

    scanf("%d", &m);

    int qi[m]; // array dos cupons
    for(int i = 0; i < m; i++){
        scanf("%d", &qi[i]);
    }

    Quicksort(ai, 0, n-1);

    for(int j = 0; j < m; j++){ // Percorrendo todos os cupons

        int retirar = n - qi[j]; // criando variável para ser o indice da barra de graça

        long long custo_final = custo_tot - ai[retirar]; // fazendo a subtração do elemento de graça

        printf("%llu\n", custo_final);
    }

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