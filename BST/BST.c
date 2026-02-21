#include "BST.h"

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

void deleteNode(Node* node) {
    if (!node) {
        return;
    }

    if (node->leftChild) {
        deleteNode(node->leftChild);
        node->leftChild = NULL;
    }

    if (node->rightChild) {
        deleteNode(node->rightChild);
        node->rightChild = NULL;
    }

    free(node);
}

typedef struct BST {
    struct Node *root;
} BST;

BST* createBST() {
    BST* tree = malloc(sizeof(BST));
    tree->root = NULL;
    return tree;
}

void deleteBST(BST* tree) {
    if (!tree) {
        return;
    }

    if (tree->root) {
        deleteNode(tree->root);
        tree->root = NULL;
    }

    free(tree);
}
