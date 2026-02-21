#include "BST.h"
#include <stdio.h>

struct Node {
    int value = 0;
    struct Node* leftChild = NULL;
    struct Node* rightChild = NULL;
};

struct BST {
    struct Node *root;
};

void bstInorder(BST* tree) {
    struct Node* current = tree->root;
    if (current == NULL) {
        return;
    }
    printf("%d", current->value);
    bstInorder(current->leftChild);
    bstInorder(current->rightChild);
}

void bstPreorder(BST* tree) {
    struct Node* current = tree->root;
    if (current == NULL) {
        return;
    }
    bstPreorder(current->leftChild);
    printf("%d", current->value);
    bstPreorder(current->rightChild);
}

void bstPostorder(BST* tree) {
    struct Node* current = tree->root;
    if (current == NULL) {
        return;
    }
    bstPostorder(current->leftChild);
    bstPostorder(current->rightChild);
    printf("%d", current->value);
}