// #include "Lybrary/Graph.h"

// using namespace std;

// int main() {
    

    
//     return 0;
// }
// g++ teste.cpp -o teste.exe ; Get-Content input.txt | ./teste.exe

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int n, int W, int w[], int v[]) {
    vector<vector<int>> F(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (w[i - 1] <= j) {
                F[i][j] = max(F[i - 1][j], v[i - 1] + F[i - 1][j - w[i - 1]]);
            } else {
                F[i][j] = F[i - 1][j];
            }
        }
    }
    return F[n][W];
}

int main() {
    int n = 4; // Número de itens
    int W = 7; // Capacidade da mochila
    int w[] = {1, 3, 4, 5}; // Pesos dos itens
    int v[] = {1, 4, 5, 7}; // Valores dos itens

    int maxVal = knapsack(n, W, w, v);
    cout << "O valor maximo que pode ser colocado na mochila e: " << maxVal << endl;

    return 0;
}
