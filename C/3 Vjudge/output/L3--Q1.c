#include "libs/OpenHash.h"

int main() {

    Dictionary* d = createDict(3, hash); // Cria um dicionário com uma tabela hash de tamanho 10
    insertDict(d, 0, 10); // Insere a chave 1 com o valor 10 no dicionário
    insertDict(d, 2, 20); // Insere a chave 2 com o valor 20 no dicionário
    for(int i = 0; i < d->m; i++){
        print_list_elements(d->H[i]);
    }
    
    clearDict(d);
    
    return 0;
}