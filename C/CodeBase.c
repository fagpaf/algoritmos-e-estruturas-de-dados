#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ano[6];
    char idade[4]; // Array de caracteres para armazenar "ADD"
    char s[20]; // Aloca memória para s

    // Copia a string "ADD: 50" para o buffer s
    // strcpy(s, "ADD: 50");
    s = "ADD:asdad";

    // Usa sscanf para extrair a parte da string e o número
    sscanf(s, "%3s:%5s", idade, ano);

    // Imprime os valores extraídos
    printf("-> %s\n", s);
    printf("-> idade: %s, ano: %s\n", idade, ano);

    // Libera a memória alocada
    free(s);

    return 0;
}

// char *vnome;
    
//     // Alocando espaço suficiente para armazenar a string
//     vnome = (char *) malloc(30); // Supondo que a string tenha no máximo 30 caracteres

//     fgets(vnome, 30, stdin); // "sizeof" é o tamanho máximo do buffer, "stdin" indica entrada padrão
//     printf("%s", vnome);
//     free(vnome);
//     printf("%s", vnome);
