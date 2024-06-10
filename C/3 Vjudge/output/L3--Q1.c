#include "libs/OpenHash.h"

const int TAM = 101;
int hash(char* key);

int main() {

    Dictionary* d = createDict(TAM, hash);
    
    int test, n1;
    scanf("%d", &test);
    
    char* input = (char*)malloc(20);
    char* command = (char*)malloc(4);
    char* str = (char*)malloc(16);

    for(int i = 0; i < test; i++){
        scanf("%d", &n1);
        for(int j = 0; j < n1; j++){
            scanf("%s", input);
            
            sscanf(input, "%3s:%15s", command, str);

            if (strcmp(command, "ADD") == 0){
                int h = hash(str);
                insertDict(d, str, h);
            }
            else if (strcmp(command, "DEL") == 0){
                remove_key(d, str);
            }
            free(str);
            free(command);
            free(input);
        }
        printf("%d\n", d->cnt);
    
        for(int i = 0; i < TAM; i++){
            if (d->H[i]->head->next != NULL){
                Node* current = d->H[i]->head->next;
                while(current != NULL){
                    printf("%d:%s\n", current->value, current->key);
                    current = current -> next;
                }
            }
        }
    }
    clearDict(d);
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
// gcc L3--Q1.c -o L3--Q1.exe ; Get-Content input.txt | ./L3--Q1.exe
