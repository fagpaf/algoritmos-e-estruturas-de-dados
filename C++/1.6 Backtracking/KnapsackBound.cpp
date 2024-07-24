// int ub = v + (W - w) * (v[i+1] / w[i+1]); // Upper Bound

#include <bits/stdc++.h>

using namespace std;

int max(int l, int r);
int knapsack(int n, int W, int w[], int v[], int F[n][W]);

int main() {
    
    int n = 4; // Número de itens
    int W = 7; // Capacidade da mochila
    int w[] = {1, 3, 4, 5}; // Pesos dos itens
    int v[] = {1, 4, 5, 7}; // Valores dos itens
    int F[1001][1001]; // Matriz de programação dinâmica (com um tamanho grande para evitar problemas de limite)

    int maxVal = knapsack(n, W, w, v, F);
    cout << "O valor máximo que pode ser colocado na mochila é " << maxVal << endl;
    
    return 0;
}

int max(int l, int r){
    if(l > r){
        return l;
    }
    else{
        return r;
    }
}

int knapsack(int n, int W, int w[], int v[], int F[n][W]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < W; j++){
            if(i == 0 || j == 0){
                F[i][j] = 0;
            }
            else if(w[i] <= j){
                F[i][j] = max(F[i - 1][j], v[i] + F[i - 1][j - w[i]]);
            }
            else{
                F[i][j] = F[i - 1][j];
            }
        }
    }
    return F[n][W];
}