#include "libs/AVLTrees.h"

int main() {
    BST* tree = create_bst();

    int operations;
    scanf("%d", &operations);
    int command, pi;

    for(int i = 0; i < operations; i++){
        scanf("%d", &command);
        scanf("%d", &pi);
        if(command == 1){
            insertNode(tree, pi, i);
        }
        else if(command == 2){
            int rank = find(tree, pi);
            if(rank == -1){
                printf("Data tidak ada\n");
            }
            else{
                printf("%d\n", rank);
            }
        }
    }
    clear_bst(tree);
    return 0;
}
// gcc L4--Q1.c -o L4--Q1.exe ; Get-Content input.txt | ./L4--Q1.exe