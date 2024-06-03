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

//<tipo-de-retorno> ( *<nome-da-variável> ) ( <parâmetros> )


// ponteiro de função que aceita char* e retorna int 
int (*fun_ptr)(char *); 

// função que aceita char* e retorna int* 
int *fun_ptr(char *); 

// FuncPtr é um ponteiro para funções que recebem e retornam char*
typedef char *(*FuncPtr)(char *);

// Cria um ponteiro de função e atribui a função gets a ele
FuncPtr ptr = gets;

typedef // Oque isso faz é em vez de escrever:

// char *(*FuncPtr)(char *);

FuncPtr ptr; // e teremos uma declaração mais clara e limpa
