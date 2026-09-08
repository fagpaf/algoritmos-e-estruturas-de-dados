#include <bits/stdc++.h>

using namespace std;

int max(int a, int b);
int MFKnapsack(int i, int j, int w[], int v[], int** F);
int** createBoard(int n, int W);

int main() {
    
    int n = 4; // Número de itens
    int W = 5; // Capacidade da mochila
    int w[] = {2, 1, 3, 2}; // Pesos dos itens
    int v[] = {12, 10, 20, 15}; // Valores dos itens        
    int** F; // Matriz de programação dinâmica (com um tamanho grande para evitar problemas de limite)

    F = createBoard(n, W);

    int maxVal = MFKnapsack(n, W, w, v, F);
    cout << "O valor maximo que pode ser colocado na mochila e " << maxVal << endl;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            cout << F[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i <= n; i++) {
        free(F[i]);
    }
    free(F);

    return 0;
}

int max(int a, int b){
    if(a > b) return a;
    return b;
}


int MFKnapsack(int i, int j, int w[], int v[], int** F) {
    if (i == 0 || j == 0) return 0;

    if (F[i][j] < 0) {
        if (j < w[i-1]) {
            F[i][j] = MFKnapsack(i - 1, j, w, v, F);
        } else {
            F[i][j] = max(MFKnapsack(i - 1, j, w, v, F), v[i-1] + MFKnapsack(i - 1, j - w[i-1], w, v, F));
        }
    }
    return F[i][j];
}

// int MFKnapsack(int i, int j, int w[], int v[], int** F) {
//     if (i == 0 || j == 0) return 0;

//     if (F[i][j] < 0) {
//         int value;
//         if (j < w[i-1]) {
//             value = MFKnapsack(i - 1, j, w, v, F);
//         }
//         else{
//             value = max(MFKnapsack(i - 1, j, w, v, F), v[i-1] + MFKnapsack(i - 1, j - w[i], w, v, F));
//         }  
//         F[i][j] = value;
//     }
//     return F[i][j];
// }

int** createBoard(int n, int W) {
    int** matrix = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        matrix[i] = (int*)malloc((W + 1) * sizeof(int)); // alocando os espaços para matriz
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                matrix[i][j] = 0;
                continue;
            }
            matrix[i][j] = -1;
        }
    }
    return matrix;
}
