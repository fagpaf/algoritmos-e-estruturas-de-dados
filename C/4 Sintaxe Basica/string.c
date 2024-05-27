#include <stdio.h>
#include <string.h> // É a biblioteca das fucionalidades de strings

int main(){  // "\n" é um array de sting e '\n' é o caracter de nova linha

    //STRINGS:

    //Tamanho
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("%d\n", strlen(alphabet)); // Com a funcionalidade "strlen" vc tem os elementos contidos no array eliminando o \0 diferente do "sizeof"

    // Desse modo abaixo conta o \0 e printa 27 elementos no array
    int length = sizeof(alphabet) / sizeof(alphabet[0]);
    printf("%d\n", length);
    //-------------------------------------------------------------

    // Concatenação
    char str1[20] = "Hello "; // Veja q tem um espaço ao final da string
    char str2[] = "World!";

    strcat(str1, str2); // Concatena str1 e str2 (o resultado é armazenado em str1, pq é a primeira variável q aparece)
    printf("%s\n", str1);
    //-------------------------------------------------------------

    //Cópia
    char str3[20] = "HELLO WORLD!";
    char str4[20];

    strcpy(str4, str3); // Lê-se "str4" copia 'str3'
    printf("%s\n", str4);
    //-------------------------------------------------------------

    //Comparação
    char str5[] = "Hello";
    char str6[] = "Hello";
    char str7[] = "Hi";
    
    printf("%d\n", strcmp(str5, str6)); // O resultado será "0", pois as strings são iguais

    printf("%d\n", strcmp(str5, str7)); // Retorna um valor != 0, porque as strings não são iguais
    //-------------------------------------------------------------






    return 0;
}