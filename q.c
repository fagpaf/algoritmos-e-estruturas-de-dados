#include "OpenHash.h"

const int TAM = 101;
int hash(char* key);

int main() {

    Dictionary* d = createDict(TAM, hash);
    char str[6] = "marsz";
    char carac[10] = "Dabrowski";

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

    
    // int test = 1;
    // int n1 = 1;
    
    // char input[20] = "ADD:Polski";
    // char command[4];
    // char* str = (char*)malloc(16);
    
    // for(int i = 0; i < test; i++){
    //     for(int j = 0; j < n1; j++){
            
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


    // -----------------------------------------------------------------------------------------------------------------
    // int test, n1;
    // scanf("%d", &test);
    
    
    // char input[20];
    // char command[4];
    
    
    // for(int i = 0; i < test; i++){
    //     scanf("%d", &n1);
    //     for(int j = 0; j < n1; j++){
    //         scanf("%s", input);
    //         char* str = (char*)malloc(16);
    //         sscanf(input, "%3s[^:]:%15s", command, str);

    //         if (strcmp(command, "ADD") == 0){
    //             int h = hash(str);
    //             insertDict(d, str, h);
    //         }
    //         else if (strcmp(command, "DEL") == 0){
    //             remove_key(d, str);
    //         }
    //         free(str);
    //     }
    // }
    printf("%d\n", d->cnt);
    
    for(int i = 0; i < d->m -1; i++){
        if (d->H[i]->head->next != NULL){
            printlist(d->H[i]);
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