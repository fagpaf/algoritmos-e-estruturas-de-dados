#include <bits/stdc++.h>

using namespace std;

int max(int l, int r);
int knapsack(int n, int W, int w[], int v[], int** F);
int** createBoard(int n, int W);
void clearBoard(int** board, int n);

int main() {
    int W; // Capacidade da mochila
    int n; // Número de itens
    cin >> W >> n;

    int w[n];// Pesos dos itens
    int v[n];// Valores dos itens
    for (int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }

    int** F;
    F = createBoard(n, W);
    int maxVal = knapsack(n, W, w, v, F);
    cout << maxVal << endl;

    clearBoard(F, n);
    return 0;
}
// g++ KnapsackBottomUP.cpp -o KnapsackBottomUP.exe ; Get-Content input.txt | ./KnapsackBottomUP.exe

int max(int l, int r){
    if(l > r){
        return l;
    }
    else{
        return r;
    }
}

int knapsack(int n, int W, int w[], int v[], int** F) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
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

void clearBoard(int** board, int n){
    for (int i = 0; i <= n; i++) {
        free(board[i]);
    }
    free(board);
}

// int knapsack(int n, int W, int weight_of[], int value_of[], int** F) {
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= W; j++) {
//             int current = F[i][j];
//             int notInsert = F[i-1][j];
//             int insert = value_of[i] + F[i-1][j-weight_of[i]];
//             if (weight_of[i] <= j) {
//                 current = max(notInsert, insert);
//             } else {
//                 current = notInsert;
//             }
//         }
//     }
//     return F[n][W];