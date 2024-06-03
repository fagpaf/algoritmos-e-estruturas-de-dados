#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// Fazer a substring para pode ptestar o código

int h(char* key, int m);
int hashTable(int x, int size);
int sfold(char* key, int m);

int main() {




}

int hashTable(int x, int size){
    int value = x % size;
    if(value < 0){
        value += size;
    }
    return value;
}

int h(char* key, int m){
    int s = strlen(key);
    int sum = 0;
    for(int i = 0; i < s-1; i++){
        sum += sum + key[i];       // A função soma os valores dos caracteres em ASCII
    }
    printf("%d\n", sum);
    return abs(sum)%m;
}

int sfold(char* key, int m){ // Hash functions para string
    int length = strlen(key) / 4;
    int sum = 0;
    
    for(int i = 0; i <= length - 1; i++){
        char sub[4] = substring(key, i * 4, (i * 4) + 4); // Definir substring
        int mult = 1;
        for(int j = 0; j <= 3; j++){
            sum += sub[j] * mult;
            mult *= 256;
        }
    }
    char sub[4] = substring(key, length * 4);
    int mult = 1;
    int s = strlen(sub);
    for(int j = 0; j <= s - 1; j++){
        sum += + sub[j] * mult;
        mult *= 256;
    }
    return abs(sum) % m;
}