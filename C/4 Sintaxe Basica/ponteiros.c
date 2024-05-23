#include <stdio.h>

int main(){

    // ENDEREÇO DE MEMÓRIA:

    char x = 1;

    printf("O valor de x e: %c\n", x); // Imprime o valor de x
    
    printf("O endereco de memoria de x e: %p\n", &x); // Imprime o endereço de memória de x "%p" é o especificador de formato dos ponteiros
    //-------------------------------------------------------------

    // PONTEIROS: Ponteiros devem ser manuseados com cuidado, pois é possível danificar dados armazenados em outros endereços de memória.
    
    // Criando Ponteiros

    int idade = 13;
    int* ptr = &idade; /*Usamos "&" para atribuir o endereço de memória da variável ao ponteiro
    int *ptr é outro modo de declarar*/ 

    printf("%d\n", idade);
    
    printf("%p\n", &idade);
    
    printf("%p\n", ptr); // Ao invés de colocarmos a variável "&idade" no código usaremos "ptr" para acessar o slot de memória em quaisquer parte do código

    printf("%d\n", *ptr); // Utilizando o operador de desreferência temos o valor da variável e não seu endereço
    //--------------------------------------------------------------------------

    
    return 0;
}