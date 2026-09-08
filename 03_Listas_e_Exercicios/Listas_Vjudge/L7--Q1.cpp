#include "Lybrary/Graph.h"

#define N 10

void createBoard(int board[N][N], int skip, int length, int col, int* numVertex);

int main() {
    
    int n;
    while(true){
        cin >> n;
        if(n == 0) break;
        int board[N][N] = { { 0 } }; // '{ { 0 } }' é um inicializador de lista onde os elementos da matriz deve ser 0
        
        // Criando o tabuleiro que o cavalo vai percorrer
        int numVertex = 0; // Vai ser passado por desreferência para contabilizar as casas válidas para o cavalo
        int skip, length;
        for (int col = 0; col < n; col++){
            cin >> skip >> length;
            createBoard(board, skip, length, col, &numVertex); 
        }

        Graph* g = createGraph(numVertex);




        for (int i = 0; i < n; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        
        // cout << "Case " << i << ", " << num << " squares can not be reached." << endl;
        // i++;

    }

    return 0;
}
// g++ q.cpp -o q.exe ; Get-Content input.txt | ./q.exe

void createBoard(int board[N][N], int skip, int length, int col, int* numVertex){
    for (int row = 0; row < N; row++){
        if(row < skip) continue;

        if(row < skip + length){
            board[col][row] = 1;  // Definindo o Tabuleiro
            (*numVertex)++;
        }
        else{
            return;
        } 
    }
}