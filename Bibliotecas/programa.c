#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main() {

    int x = 0;
    List* l = create_list();
    
    insert(l, 10);
    insert(l, 20);
    printlist(l);
    
    move_to_start(l);
    x = curr_pos(l);
    printf("%d\n", x);
    
    insert(l, 30); // Inserir 30 após a posição do cursor (que está no início)
    insert(l, 40); // Inserir 40 após a posição do cursor (que agora está após 30)
    
    move_to_end(l);
    insert(l, 50); // Inserir 50 no final da lista
    
    printf("Lista: ");
    printlist(l); // Deveria imprimir: 10 30 40 20 50
    
    clear(l);
    
    return 0;
}