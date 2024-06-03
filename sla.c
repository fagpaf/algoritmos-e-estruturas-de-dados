#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

 
int h(int key, int mod){
    int temp = (int) floor((((double) key) / ((double) mod)));
    return (key - (mod * temp)); 
    }

int main(){



    return 0;
}