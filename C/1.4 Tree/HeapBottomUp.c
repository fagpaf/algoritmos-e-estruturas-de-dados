#include <stdio.h>
#include <stdlib.h>

enum bool{
    False = 0,
    True
};

void bottomUp(int H[], int length);

int main() {

    int H[7] = {2, 9, 7, 6, 5, 8, 10};
    int length = sizeof(H)/sizeof(H[0]);
    bottomUp(H, length);
    for (int i = 0; i < length; i++){
        printf("%d ", H[i]);
    }
    
    return 0;
}

void bottomUp(int H[], int length){
    int n = length - 1;
    for(int i = n/2; i >= 0; i--){
        int k = i;
        int v = H[k];
        enum bool heap = False;
        while(!heap && 2*k + 1 <= n){
            int j = 2*k + 1;
            if(j < n && H[j] < H[j+1]){
                j++;
            }
            if(v >= H[j]){
                heap = True;
            }
            else{
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}