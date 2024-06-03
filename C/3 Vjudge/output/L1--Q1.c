#include <stdio.h>
#include <string.h>
#include "libs/Quicksort.h"

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