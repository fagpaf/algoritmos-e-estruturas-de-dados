#include "libs/BinarySearchTree.h"

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
    posorder(tree->root);
    
    return 0;
}
// gcc L3--Q2.c -o L3--Q2.exe ; Get-Content input.txt | ./L3--Q2.exe