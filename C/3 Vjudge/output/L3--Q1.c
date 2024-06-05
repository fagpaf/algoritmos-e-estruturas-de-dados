#include "libs/OpenHash.h"

const int TAM = 101;
int hash(char* key);

int main() {

    Dictionary* d = createDict(TAM, hash); // Cria um dicionário com uma tabela hash de tamanho 10
    int t, n1;
    scanf("%d", &t);
    scanf("%d", &n1);
    
    char add[4] = "ADD";
    char del[4] = "DEL";
    char command[4];
    char str[16];
    while (n1-- > 0){
        scanf("%s", command);
        if (strcmp(command, add) == 0){
            sscanf(input, "ADD:%s", str);
            int h = hash(str)
            insertDict(d, command, h);
        }
        else if (strcmp(command, del) == 0){
            sscanf(input, "DEL:%s", str);
            // remove_key(d, str);
        }
         
    }
    
    // for(int i = 0; i < d->cnt; i++){
    //     print_list_elements(d->H[i]);
    // } printf("%d\n", d->cnt);
    
    clearDict(d);
    
    return 0;
}

int hash(char* key){
    int value = 0 
    for (int i = 19; i > 0; i--){
        mod = (key % TAM)
        if(mod < 0){
            mod += TAM;
        }
        value += i * mod;
    } 
    return value;
}
// gcc L3--Q1.c -o L3--Q1.exe ; Get-Content input.txt | ./L3--Q1.exe