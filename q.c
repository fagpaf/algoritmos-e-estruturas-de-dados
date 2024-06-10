#include "OpenHash.h"

const int TAM = 101;
int hash(char* key);
int main() {

    Dictionary* d = createDict(TAM, hash);
    char str[10] = "ziemii";
    char carac[7] = "z";

    int h = hash(str);
    printf("%d\n", h);
    int ca = hash(carac);
    printf("%d\n", ca);

    insertDict(d, str, h);
    int x = find(d, str);
    printf("%d\n", x);

    insertDict(d, carac, ca);
    int y = find(d, carac);
    printf("%d\n", y);

    remove_key(d, str);
    x = find(d, str);
    printf("%d\n", x);
    
    // int test, n1;
    // scanf("%d", &test);

    // char input[20];
    // char command[4];
    // char str[16];
    
    // for(int i = 0; i < test; i++){
    //     scanf("%d", &n1);
    //     for(int j = 0; j < n1; j++){
    //         scanf("%s", input);
    //         sscanf(input, "%3s:%15s", command, str);
    //         if (strcmp(command, "ADD") == 0){
    //             int h = hash(str);
    //             insertDict(d, str, h);
    //         }
    //         else if (strcmp(command, "DEL") == 0){
    //             remove_key(d, str);
    //         }
    //     }
    // }
    printf("%d\n", d->cnt);

    for(int i = 0; i < TAM; i++){
        Node* current = d->H[i]->head->next;
        while(current != NULL){
            printf("%d:%s\n", current->value, current->key);
            current = current -> next;
        }
    }
    //clearDict(d);
    return 0;
}

int hash(char* key){
    int value = 0;
    int length = strlen(key);
    for (int i = 0; i < length; i++){
        value += (key[i] *(i + 1));   
    }
    value *= 19;
    return value % TAM;
}
// gcc q.c -o q.exe ; Get-Content input.txt | ./q.exe