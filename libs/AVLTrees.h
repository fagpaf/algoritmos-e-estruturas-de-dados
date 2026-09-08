#ifndef AVLTREES_H
#define AVLTREES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode{
    int size;
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
int findRank(BSTNode* root, int k);
BSTNode* rightRotate(BSTNode* root);
BSTNode* leftRotate(BSTNode* root);
void clear_bst(BST* bst);
void clear_root(BSTNode* root);
int max(int l, int r);
int rank(BSTNode* root);
int getBalance(BSTNode* root);
int h(BSTNode* root);
void preorder(BSTNode* root);
void inorder(BSTNode* root);
void postorder(BSTNode* root);

int rank(BSTNode* root){
    if(root == NULL){
        return 0;
    }
    return root->size;
}

void clear_bst(BST* bst){
    clear_root(bst->root);
    free(bst);
}

void clear_root(BSTNode* root){
    if (root != NULL) {
        clear_root(root->left);
        clear_root(root->right);
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

int getBalance(BSTNode* root){ 
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
    n->size = 1;
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
    return findRank(bst->root, k);
}

int findRank(BSTNode* root, int k){
    if(root == NULL){
        return -1;
    }
    if(root->key > k){
        return findRank(root->left, k);
    }
    else if(root->key < k){
        int size_left = rank(root->left);
        int res = findRank(root->right, k);
        if(res == -1){
            return -1;
        }
        else{
            return (size_left + 1 + res);
        }
    }
    else{
        return rank(root->left) + 1;
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
    root->size = 1 + rank(root->left) + rank(root->right);

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
    BSTNode* l = root->left; // Nó esquerdo da raiz
    BSTNode* lr = l->right; // é a subarvore direita do nó esquerdo
    l->right = root; // a subarvore direita q era vazia recebe a raiz
    root->left = lr;
    
    root->height = max(h(root->left), h(root->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
    
    root->size = 1 + rank(root->left) + rank(root->right);
    l->size = 1 + rank(l->left) + rank(l->right);

    return l;
}

BSTNode* leftRotate(BSTNode* root){
    BSTNode* r = root->right;
    BSTNode* rl = r->left;
    r->left = root;
    root->right = rl;
    
    root->height = max(h(root->left), h(root->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    
    root->size = 1 + rank(root->left) + rank(root->right);
    r->size = 1 + rank(r->left) + rank(r->right);
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