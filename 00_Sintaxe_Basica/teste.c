#include <stdio.h>
#include <stdbool.h> // Para implementar booleanos precisa adicionar a biblioteca "stdbool.h"

// Comando "puts" já faz a quebra de linha sem precisar do "\n"

int main(){

    bool booleana = true;
    // const float PI = 3.14159; // Constante se declara com o valor e em caixa alta
    int num = 7;
    int num2 = 2;
    float result = (int) num / num2; // Convertendo uma divisão de inteiros em float, é assim q faz um conversão
    char a = 65; // valor da letra "A" na tabela ASCII
    char nome = 'F'; // Para char tem q usar aspas simples ''
    char carac[] = "Flavinho"; // as strings são arrays de caracteres
    float x = 2.7e3; // número de base 10
    double y = 1.9;
    
    int numbers[5] = {2,3,5,7,11}; // Assim se declara um "array": nome, tipo e tamanho

    // Caso não declarado o tamanho do array podemos usar esse artifício
    //1
    //printf("%lu\n", sizeof(numbers)); // Retorna o tamanho do array em bytes ocupados na memória
    
    //2
    int length = sizeof(numbers) / sizeof(numbers[0]); // Funciona como o "len()" de listas em .py, em "char" ele conta o \0 o caracter nulo do array
    
    printf("%d\n", length); // Desse modo o "sizeof" retorna os elementos do array

    /* 
    Operador ternário "(result >= 2.5)" é a condição a ser analisada T or F
    "?" significa que a condição é True e retorna 'printf("Tautologia\n")'
    ":" caso a condição seja False retorna 'printf("Contradição\n")'   */
    
    (result >= 2.5) ? printf("Tautologia\n") : printf("Contradicao\n"); 

    printf("%c\n%c\n", nome, a); // "%c" é o especificador de formato da variável tipo char
    
    printf("This is the number of perfection: %d\n", num); // os especificadores determinam a posição da variável 
    
    printf("%s\n", carac); // "%s" é usado em arrays de caracteres(strings em C)
    
    printf("%f\n", x);

    printf("%.3lf\n", y); // "%.3" determina a quantidade de casas decimais que eu quero 
    
    printf("%d\n", ++num); // "++num" soma 1 a variável e "--num" desencrementa (-1) dela  

    printf("%d\n", booleana); // Usa-se "%d" pq o resultado é dado em binário "0" ou "1"

    printf("Hello World""\n""\n");

    printf("%.1f\n", result);
    
    /* Um modo diferente de criar uma string

    char greetings[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
    printf("%s", greetings);
    
    \0 é conhecido como o "caractere de terminação nulo"
    */

    return 0;
}
