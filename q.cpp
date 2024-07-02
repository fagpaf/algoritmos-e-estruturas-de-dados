#include "Lybrary/AVLTrees.h"

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
// gcc q.c -o q.exe ; Get-Content input.txt | ./q.exe
