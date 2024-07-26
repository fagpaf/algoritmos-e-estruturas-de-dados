#include <bits/stdc++.h>

using namespace std;

int knapsack(int n, int W, int w[], int v[], int** F);
int** createBoard(int n, int W);

int main() {
    
    int n = 4; // Número de itens
    int W = 7; // Capacidade da mochila
    int w[] = {2, 1, 3, 2}; // Pesos dos itens
    int v[] = {12, 10, 20, 15}; // Valores dos itens        
    int** F; // Matriz de programação dinâmica (com um tamanho grande para evitar problemas de limite)

    F = createBoard(n, W);
    knapsack(n, W, w, v, F);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            cout << F[i][j] << " ";
        }
        cout << endl;
    }

    // int maxVal = knapsack(n, W, w, v, F);
    // cout << "O valor maximo que pode ser colocado na mochila e " << maxVal << endl;
    
    // Liberar a memória alocada
    // for (int i = 0; i <= n; i++) {
    //     free(F[i]);
    // }
    // free(F);

    return 0;
}

int knapsack(int n, int W, int w[], int v[], int** F) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (i == 0 || j == 0) {
                F[i][j] = 0;
            }
            if (w[i - 1] <= j) {
                F[i][j] = max(F[i - 1][j], v[i - 1] + F[i - 1][j - w[i - 1]]);
            } else {
                F[i][j] = F[i - 1][j];
            }
        }
    }
    return F[n][W];
}

int** createBoard(int n, int W) {
    int** matrix = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        matrix[i] = (int*)malloc((W + 1) * sizeof(int)); // alocando os espaços para matriz
        for (int j = 0; j <= W; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}
