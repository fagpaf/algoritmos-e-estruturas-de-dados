#include "AVLTrees.h"

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
            printf("obla di\n");
        }
        else{
            int x = find(tree, pi);
            if(x != -1){
                printf("bla da %d\n", x);
            }
        }
    }
    clear_bst(tree);
    return 0;
}
// gcc s.c -o s.exe ; Get-Content input.txt | ./s.exe