#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode{
    int key;
    int value;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

typedef struct BST{
    BSTNode* root;
    int nodecnt;
} BST;

BSTNode* create_bstnode(int k, int value);
BST* create_bst();
int find(BST* bst ,int k);
int findhelp(BSTNode* root, int k);
void insertNode(BST* bst, int k, int value);
BSTNode* inserthelp(BSTNode* root, int k, int value);
int removeNode(BST* bst, int k);
BSTNode* removehelp(BSTNode* root, int k);
BSTNode* getmin(BSTNode* root);
BSTNode* deletemin(BSTNode* root);
void preorder(BSTNode* root);
void inorder(BSTNode* root);
void postorder(BSTNode* root);


BSTNode* create_bstnode(int k, int value){
    BSTNode* n = (BSTNode*)malloc(sizeof(BSTNode));
    n->key = k;
    n->value = value;
    n->left = n->right = NULL;
    return n;
}

BST* create_bst(){
    BST* bst = (BST*)malloc(sizeof(BST));
    bst->root = NULL;
    bst->nodecnt = 0;
    return bst;
}

int find(BST* bst ,int k){
    return findhelp(bst->root, k);
}

int findhelp(BSTNode* root, int k){
    if(root == NULL){
        return -1;
    }
    if(root->key > k){
        return findhelp(root->left, k);
    }
    else if(root->key == k){
        return root->value;
    }
    else{
        return findhelp(root->right, k);
    }
}

void insertNode(BST* bst, int k, int value){
    bst->root = inserthelp(bst->root, k, value);
    bst->nodecnt++;
}

BSTNode* inserthelp(BSTNode* root, int k, int value){ // Chaves repetidas vão para a posição certa
    if(root == NULL){
        return create_bstnode(k, value); // Retornando areferência para o novo nó
    }
    if(root->key > k){
        root->left = inserthelp(root->left, k, value); // Retornando a referência ao nó atual
    }
    else{
        root->right = inserthelp(root->right, k, value);
    }
    return root;
}

int removeNode(BST* bst, int k){
    int temp = findhelp(bst->root, k);
    if(temp != -1){
        bst->root = removehelp(bst->root, k);
        bst->nodecnt--;
    }
    return temp;
}

// ENTENDER COMO ISSO FUNCIONA
BSTNode* removehelp(BSTNode* root, int k){
    if(root == NULL){
        return NULL;
    }
    if(root->key > k){
        root->left = removehelp(root->left, k);
    }
    else if(root->key < k){
        root->right = removehelp(root->right, k);
    }
    else{
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        else{
            BSTNode* temp = getmin(root->right);
            root->value = temp->value;
            root->key = temp->key;
            root->right = deletemin(root->right);
        }
    }
    return root;
}

BSTNode* getmin(BSTNode* root){
    if(root->left == NULL){
        return root;
    }
    return getmin(root->left);
}

BSTNode* deletemin(BSTNode* root){
    if(root->left == NULL){
        return root->right;
    }
    root->left = deletemin(root->left);
    return root;
}

void preorder(BSTNode* root){
    if(root != NULL){
        printf(" %d", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(BSTNode* root){
    if(root != NULL){
        inorder(root->left);
        printf(" %d", root->key);
        inorder(root->right);
    }
}

void postorder(BSTNode* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" %d", root->key);
    }
}

#endif