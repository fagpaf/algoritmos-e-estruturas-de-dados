#include"Lybrary/ClosedHash.h"

int main() {

    int test, n1;
    scanf("%d", &test);

    char input[20];
    char command[4];
    char str[16];
    
    for(int i = 0; i < test; i++){
        scanf("%d", &n1);
        Dictionary* d = create_dict(TAM, hash);
        for(int j = 0; j < n1; j++){
            scanf("%s", input);
            sscanf(input, "%3s:%15s", command, str);
            int h = hash(str); // calculando a hash apenas uma vez
            if (strcmp(command, "ADD") == 0){
                insert(d, str, h);
            }
            else if (strcmp(command, "DEL") == 0){
                remove_key(d, str, h); // passando o valor para otimização
            }
        }
        printDict(d);
        clearDict(d);
    }
    return 0;
}
// gcc q.c -o q.exe ; Get-Content input.txt | ./q.exe