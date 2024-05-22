#include <stdio.h>

int main(){

    int n = 2;
    int i = 0;

    while (i < 2) {
        printf("%d\n", i);
        i++;
    }
    
    printf("\n");
    //---------------------------------------------------------------

    //loop do/while sempre executa o código uma vez antes da condicional, pq o código vem antes da condição
    do {
        printf("%d\n", n);
        n++;
    }
    while (n < 0);

    printf("\n");
    //---------------------------------------------------------------
    
    for (int x = 3; x <= 12; x*=2){ // Pode-se declarar a variável no próprio "for"
        printf("%d\n", x);
    }

    /*
    for (variável de controle; condicional; incremento/decremento){
        comandos
    }
    
    variável de controle: é executada (uma vez) antes da execução do bloco de código.
    
    condicional: define a condição para execução do bloco de código.

    incremento/decremento: é executada (sempre) após a execução do bloco de código.
    */
    //---------------------------------------------------------------

    // For aninhado
    int a, j;

    for (a = 1; a <= 2; ++a) {
        printf("Outer: %d\n", a);

        for (j = 1; j <= 3; ++j) {
            printf(" Inner: %d\n", j);
        }
    }

   return 0;
}