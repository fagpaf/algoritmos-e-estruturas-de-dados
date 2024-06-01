#include <stdio.h>
#include "bibs/List.h"

const int MAXLEN = 100001;

int main() {
    char str[MAXLEN];
    
    while(scanf(" %s", str) != EOF) { // É bom dar esse espaço no " %s" para evitar problema
        List* l = create_list();
        
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '[') {
                move_to_start(l);
            } else if (str[i] == ']') {
                move_to_end(l);
            } else {
                insert(l, str[i]);
            }
        }
        printlist(l);
        clear(l);
    }
    return 0;
}