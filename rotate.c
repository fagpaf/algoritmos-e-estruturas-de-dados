#include "Lybrary/BinarySearchTree.h"

int main() {

    BST* tree = create_bst();
    int n, pi;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &pi);
        insertNode(tree, pi, i);
    }
    
    printf("Pre order :");
    preorder(tree->root);
    printf("\n");

    printf("In order  :");
    inorder(tree->root);
    printf("\n");

    printf("Post order:");
    postorder(tree->root);
    
    return 0;
}
// g++ rotate.c -o rotate.exe ; Get-Content input.txt | ./rotate.exe