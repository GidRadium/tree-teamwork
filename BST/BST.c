#include "BST.h"

#include <stdbool.h>
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

BST* bstCreate() {
    BST* tree = malloc(sizeof(BST));
    tree->root = NULL;
    return tree;
}

void insertRecursive(Node* root, int value) {
    if (value < root->value) {
        if (!root->leftChild) {
            root->leftChild = createNode(value);
            return;
        }

        insertRecursive(root->leftChild, value);
    } else if (value > root->value) {
        if (!root->rightChild) {
            root->rightChild = createNode(value);
            return;
        }

        insertRecursive(root->rightChild, value);
    }
}

void bstInsert(BST* tree, int value) {
    if (!tree) {
        return;
    }

    if (!tree->root) {
        tree->root = createNode(value);
        return;
    }

    insertRecursive(tree->root, value);
}

bool containsRecursive(Node* root, int value) {
    if (!root) {
        return false;
    }

    if (value == root->value) {
        return true;
    }

    if (value < root->value) {
        return containsRecursive(root->leftChild, value);
    } else {
        return containsRecursive(root->rightChild, value);
    }
}

bool bstContains(BST* tree, int value) {
    return tree ? containsRecursive(tree->root, value) : false;
}

void bstFree(BST* tree) {
    if (!tree) {
        return;
    }

    if (tree->root) {
        deleteNode(tree->root);
        tree->root = NULL;
    }

    free(tree);
}
