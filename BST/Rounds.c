#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node* createNode(int value) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

typedef struct BST {
    Node *root;
} BST;

BST* bstCreate() {
    BST* tree = malloc(sizeof(BST));
    tree->root = NULL;
    return tree;
}


void bstInorder(BST* tree) {
    Node* current = tree->root;
    if (current == NULL) {
        return;
    }
    printf("%d", current->value);
    bstInorder(current->leftChild);
    bstInorder(current->rightChild);
}

void bstPreorder(BST* tree) {
    Node* current = tree->root;
    if (current == NULL) {
        return;
    }
    bstPreorder(current->leftChild);
    printf("%d", current->value);
    bstPreorder(current->rightChild);
}

void bstPostorder(BST* tree) {
    Node* current = tree->root;
    if (current == NULL) {
        return;
    }
    bstPostorder(current->leftChild);
    bstPostorder(current->rightChild);
    printf("%d", current->value);
}