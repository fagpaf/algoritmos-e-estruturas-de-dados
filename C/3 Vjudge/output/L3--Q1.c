#include "libs/OpenHash.h"

const int TAM = 101;
int hash(char* key);

int main() {

    Dictionary* d = createDict(TAM, hash); // Cria um dicionário com uma tabela hash de tamanho 10
    int test, n1;
    scanf("%d", &test);
    scanf("%d", &n1);
    
    char add[4] = "ADD";
    char del[4] = "DEL";
    char command[4];
    char str[16];
    
    for(int i = 0; i < test; i++){
        while (n1-- > 0){
            scanf("%s", command);
            if (strcmp(command, add) == 0){
                sscanf(command, "ADD:%s", str);
                
                int h = hash(str);
                insertDict(d, str, h);
            }
            else if (strcmp(command, del) == 0){
                sscanf(command, "DEL:%s", str);
                remove_key(d, str);
            }
            
        }
    }
    printf("%d\n", d->cnt);
    
    for(int i = 0; i < d->cnt; i++){
        print_list_keys(d->H[i]);
    }
    clearDict(d);
    return 0;
}

int hash(char* key){
    int value = 0;
    for (int i = 19; i > 0; i--){
        int mod = (key[i] % TAM);
        if(mod < 0){
            mod += TAM;
        }
        value += i * mod;
    } 
    return value;
}
// gcc L3--Q1.c -o L3--Q1.exe ; Get-Content input.txt | ./L3--Q1.exe
