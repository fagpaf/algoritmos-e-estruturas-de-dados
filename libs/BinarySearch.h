#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

int binary_search(int arr[], int length, int alvo);

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

#endif