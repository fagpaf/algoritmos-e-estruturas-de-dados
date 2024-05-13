#include <stdio.h>
#include <string.h>

int binary_search(int arr[], int length, int alvo);

int main() {

    int k = 2; 
    int arr[5] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    int idx = 0;
    for(int j = 0; j < length - 1; j++){
         
        int alvo = arr[j] + k;
        int result_search = binary_search(arr, length, alvo);
        
        if(alvo == result_search){
            idx++;
        }
    }
    printf("%d", idx);
    
    return 0;
}


int binary_search(int arr[], int length, int alvo){
    int baixo = 0;
    int alto = length - 1;

    while (baixo <= alto){
        int meio = (baixo + alto) / 2;
        int chute = arr[meio];

        if(chute == alvo){
            return chute;
        }
        else if(chute > alvo){
            alto = meio -1;
        }
        else{
            baixo = meio + 1;
        }
    }
    return 0;
}