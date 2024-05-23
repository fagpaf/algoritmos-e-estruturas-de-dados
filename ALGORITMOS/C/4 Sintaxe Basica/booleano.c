#include <stdio.h>
#include <stdbool.h> // Para implementar booleanos precisa adicionar esta biblioteca 
#include <string.h> // É a biblioteca das fucionalidades de strings

int main() {
    bool booleana = true; // retorna qualquer valor != de "0"
    
    // Diferente das funções booleanas de C, strcmp retorna "0", quando a comparação for verdadeira
    char str1[] = "Hello";
    char str2[] = "Hello";
    printf("%d\n", strcmp(str1, str2)); // O resultado será "0", pois as strings são iguais
/*
int strcmp ( const char * str1, const char * str2 );

O método strcmp testa a igualdade das Strings.

Retorna um número negativo se str1 for menor que str2;
Retorna zero se as duas strings são iguais;
Retorna um número positivo se str1 é maior que str2.
*/
    return 0;
}