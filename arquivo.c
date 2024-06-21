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
BSTNode* rightRotate(BSTNode* root);
BSTNode* leftRotate(BSTNode* root);
void clear_bst(BST* bst);
void clear_root(BSTNode* root);
int max(int l, int r);
int getbalance(BSTNode* root);
int h(BSTNode* root);

int main(){

    int cases;
    scanf("%d", &cases);
    
    while (cases--){
        BST* tree = create_bst();
        int operations;
        scanf("%d", &operations);
        int input;
        for (int i = 0; i < operations; i++){
            scanf("%d", &input);
            insertNode(tree, input, i);
        }
        preorder(tree->root);
        printf("END\n");

        clear_bst(tree);
    }
    return 0;
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

int getbalance(BSTNode* root){
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

BSTNode* inserthelp(BSTNode* root, int key, int value){
    if(root == NULL){
        return create_bstnode(key, value);
    }
    if(root->key > key){
        root->left = inserthelp(root->left, key, value);
    }
    else{
        root->right = inserthelp(root->right, key, value);
    }

    root->height = 1 + max(h(root->left), h(root->right));
    int balance = getbalance(root);
    
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
    BSTNode* lr = l->right;
    l->right = root;
    root->left = lr;
    root->height = 1 + max(h(root->left), h(root->right));
    l->height = 1 + max(h(l->left), h(l->right));
    return l;
}

BSTNode* leftRotate(BSTNode* root){
    BSTNode* r = root->right;
    BSTNode* rl = r->left;
    r->left = root;
    root->right = rl;
    root->height = 1 + max(h(root->left), h(root->right));
    r->height = 1 + max(h(r->left), h(r->right));
    return r;
}

void preorder(BSTNode* root){
    if(root != NULL){
        printf("%d\n", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}