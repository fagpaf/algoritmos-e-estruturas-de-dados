#include <stdio.h>
#include <stdlib.h>

void f(void){
    int* s = malloc(50 * sizeof(int));
    s[50] = 0; /* obtém a memória */
}
int main(void){
    f();
    return 0;
}