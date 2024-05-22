#include <stdio.h>
#include <stdlib.h> // Necessário para alocação dinâmica
int main() {

    // Sintaxe:
    
    // int *ptr1, *ptr2;
    // ptr1 = malloc(sizeof(*ptr1));
    // ptr2 = calloc(1, sizeof(*ptr2));
    
     // sizeof ñ consegue medir o tamnho da alocação dps de feita ----> temos que calcular isso multiplicando a quantidade de itens pelo tamanho do tipo de dados:

    // EX:

    int *students;
    int numStudents = 12;
    students = calloc(numStudents, sizeof(*students));
    printf("%d\n", numStudents * sizeof(*students)); // 48 bytes
    // ------------------------------------------------------------------------

    // OBS:
    
    // A memória dinâmica não possui tipo de dados próprio, é apenas uma sequência de bytes. Os dados na memória podem ser interpretados como um tipo baseado no tipo de dados do ponteiro.

    // Neste exemplo, um ponteiro para quatro bytes pode ser interpretado como um intvalor (4 bytes) ou como uma matriz de 4 charvalores (1 byte cada).
    
    int *ptr1 = malloc(4);
    char *ptr2 = (char*) ptr1;
    ptr1[0] = 1684234849;
    printf("%d is %c %c %c %c\n", *ptr1, ptr2[0], ptr2[1], ptr2[2], ptr2[3]);
    
    // Desalocando Memória:
    int *ptr;
    ptr = malloc(sizeof(*ptr));

    free(ptr);
    ptr = NULL;
    printf("%p\n", ptr);

    // BOAS PRÁTICAS:

    // 1º  Lembre-se de verificar se há erros ( NULLvalores de retorno) para descobrir se a alocação de memória foi bem-sucedida ou não
    
    // 2º  Evite vazamentos de memória - lembre-se sempre de liberar memória que não é mais usada, caso contrário o programa poderá ter um desempenho inferior ou, pior ainda, travar se ficar sem memória

    // 3º  Defina o ponteiro para NULLdepois de liberar memória para que você não possa continuar a usá-lo acidentalmente

    // REALLOC:
    
    // int *ptr2 = realloc(ptr1, size); tem dois parâmetros o ponteiro para memória redimensionada e o novo tamanho a ser alocado

    // *** Se não for possível redimensionar a memória no endereço atual, ele alocará memória em um endereço diferente e retornará o novo endereço. ***

    /*Nota: Quando realloc()retorna um endereço de memória diferente, a memória no endereço original não está mais reservada e não é segura para uso.
    Quando a realocação for feita é bom atribuir o novo ponteiro à variável anterior para que o ponteiro antigo não possa ser usado acidentalmente. 
    */
    
    int *ptr5, *ptr6, size;

    // Allocate memory for four integers
    size = 4 * sizeof(*ptr1);
    ptr5 = malloc(size);

    printf("%d bytes allocated at address %p \n", size, ptr5);

    // Resize the memory to hold six integers
    size = 6 * sizeof(*ptr5);
    ptr6 = realloc(ptr5, size);

    printf("%d bytes reallocated at address %p \n", size, ptr6);
        
    return 0;
}
