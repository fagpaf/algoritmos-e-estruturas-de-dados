#include <stdio.h>
// Precisa ser revisto
void clear_buffer(void);

int main(void) {
    char a, b, c;
    a = getchar();
    clear_buffer();

    b = getchar();
    clear_buffer();
    
    c = getchar();
    clear_buffer();
    
    printf("%c\n", a);
    printf("%c\n", b);
    printf("%c\n", c);
    return 0;
}

void clear_buffer(void){
    char c;
    while((c = getchar()) != "\n" && c != EOF);
}