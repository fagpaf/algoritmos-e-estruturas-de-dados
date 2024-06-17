#ifndef AVLTREES_H
#define AVLTREES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode{
    int key;
    int value;
    int height;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

typedef struct BST{
    BSTNode* root;
    int nodecnt;
} BST;

BSTNode* create_bstnode(int key, int value);
BST* create_bst();
void insertNode(BST* bst, int key, int value);
BSTNode* inserthelp(BSTNode* root, int key, int value);
int find(BST* bst ,int k);
int findhelp(BSTNode* root, int k);
void preorder(BSTNode* root);
void inorder(BSTNode* root);
void postorder(BSTNode* root);
//-----------------------------------------------------
BSTNode* rightRotate(BST* bst);
BSTNode* leftRotate(BSTNode* root);
void free_bst(BSTNode* root);
int max(int l, int r);
int getBalance(BSTNode* root);
int h(BSTNode* root);


void free_bst(BST* bst){
    BSTNode* root = bst->root;
    if (root != NULL) {
        free_bst(root->left);
        free_bst(root->right);
        free(root);
    }
}

int max(int l, int r){
    if(l > r){
        return l;
    }
    else{
        return r;
    }
}

int getBalance(BSTNode* root){ // fator de balanceamento da árvore
    if (root == NULL){
        return 0;
    }
    return h(root->left) - h(root->right);
}

int h(BSTNode* root){
    if (root == NULL){
        return -1;
    }
    return root->height;
}

BSTNode* create_bstnode(int key, int value){
    BSTNode* n = (BSTNode*)malloc(sizeof(BSTNode));
    n->key = key;
    n->value = value;
    n->height = 0;
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

void insertNode(BST* bst, int key, int value){
    bst->root = inserthelp(bst->root, key, value);
    bst->nodecnt++;
}

BSTNode* inserthelp(BSTNode* root, int key, int value){ // Chaves repetidas vão para a posição certa
    if(root == NULL){
        return create_bstnode(key, value); // Retornando areferência para o novo nó
    }
    if(root->key > key){
        root->left = inserthelp(root->left, key, value); // Retornando a referência ao nó atual
    }
    else{
        root->right = inserthelp(root->right, key, value);
    }
    // PARAR PARA LER ISSO
    root->height = 1 + max(h(root->left), h(root->right));
    int balance = getBalance(root);
    
    if(balance < -1 && key >= root->right->key){
        return leftRotate(root);
    }
    if(balance > 1 && key < root->left->key){
        return rightRotate(root);
    }
    if(balance > 1 && key >= root->left->key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && key < root->right->key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}


BSTNode* rightRotate(BSTNode* root){
    BSTNode* l = root->left;
    BSTNode* lr = l->right; // é a subarvore direita do nó esquerdo
    l->right = root;
    root->left = lr;
    root->height = max(h(root->left), h(root->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
    return l;
}

BSTNode* leftRotate(BSTNode* root){
    BSTNode* r = root->right;
    BSTNode* rl = r->left;
    r->left = root;
    root->right = rl;
    root->height = max(h(root->left), h(root->right)) + 1;
    r->height = max(h(root->left), h(root->right)) + 1;
    return r;
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