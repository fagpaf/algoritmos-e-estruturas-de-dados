#include <stdio.h>

// Primeiro se declara a função antes da main e dps dela se define
int soma(int, int); 

int main() {

    int a, b;
    
    scanf("%d %d", &a, &b);

    int result = soma(a, b); // *É assim q se chama uma função em C*
    
    printf("%d\n", result);
    
    return 0;
}

// Define a função após a main

int soma(x, y){

    return x + y;
}