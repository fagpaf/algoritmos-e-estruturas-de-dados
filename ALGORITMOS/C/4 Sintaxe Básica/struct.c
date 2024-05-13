#include <stdio.h>
#include <string.h>

struct Candidatos {
    
    char nome[30];
    int nota;
    int idade;
};

int main() {

    int cargos, inscritos, vagas, notas, idades;
    char pleitiante[30];

    scanf("%d %d %d", &cargos, &inscritos, &vagas);

    for (int i = 0; inscritos; ++i){
        
        printf("\n%d", cargos);

    }

    return 0;
}
