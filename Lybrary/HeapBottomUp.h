#ifndef HEAPBOTTOMUP_H
#define HEAPBOTTOMUP_H

#include <stdio.h>
#include <stdlib.h>

enum bool{
    False = 0,
    True
};

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

#endif