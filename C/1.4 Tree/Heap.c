#include <stdio.h>
#include <stdlib.h>

enum bool{
    False = 0,
    True
};

void bottomUp(int H[], int length);

int main() {


    int length = sizeof(H)/sizeof(H[0]);

    return 0;
}

void bottomUp(int H[], int length){
    int n = length;
    for(int i = n/2; i > 0; i--){
        int k = i;
    }
    int k = i;
    int v = H[k];
    enum bool heap = False;
    do{
        int j = 2*k;
        if(j < n){
            if(H[j] < H[j+1]){
                j++;
            }
        }
        if(v >= H[j]){
            heap = True;
        }
        else{
            H[k] = H[j];
            k = j;
        }
    }
    while(!(heap && 2*k <= n))
    H[k] = v;
}