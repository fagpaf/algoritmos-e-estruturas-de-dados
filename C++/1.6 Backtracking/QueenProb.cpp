#include <stdbool.h>
#include <stdio.h>

#define N 8

bool isSafe(int board[N][N], int row, int col) {
    int i, j;
    //Este loop verifica todas as colunas à esquerda da coluna atual('col') na mesma linha row
    for (i = 0; i < col; i++)
        if (board[row][i]) // se (board[row][i] é 1), retorna false
            return false;

    // Verifica a diagonal superior esquerda
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    // Para cada passo, tanto i (linha) quanto j (coluna) são decrementados, movendo-se para cima e para a esquerda.
        if (board[i][j])
            return false;

    // Verifica a diagonal inferior esquerda
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    // Para cada passo, i (linha) é incrementado e j (coluna) é decrementado, movendo-se para baixo e para a esquerda.
        if (board[i][j])
            return false;

    // Se não houver nenhuma rainha na linha e nas diagonais à esquerda, é seguro colocar a rainha
    return true;
}

bool solveNQUtil(int board[N][N], int col) {
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1))
                return true;
            board[i][col] = 0; // backtrack
        }
    }
    return false;
}

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

void solveNQ() {
    int board[N][N] = { { 0 } };
    if (solveNQUtil(board, 0) == false) {
        printf("Solution does not exist");
        return;
    }
    printSolution(board);
}

int main() {
    solveNQ();
    return 0;
}

// Testar isso
// bool qns(int l, int M[n][n]){
//     if(l == n) return true;

//     else{
//         for (int i = 0; i < n; i++){
//             if(valid(M, l, i)){
//                 M[l][i] = 1;
//                 if(qns(l+1, M)) return true;
//             }
//             else{
//                 M[l][i] = 0;
//             }
//         }
//         return false;
//     }
// }