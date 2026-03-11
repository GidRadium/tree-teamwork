#include "BST.h"

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node Node;

typedef struct Node {
    int value;
    Node* leftChild;
    Node* rightChild;
} Node;

Node* nodeCreate(int value)
{
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }

    node->value = value;
    node->leftChild = NULL;
    node->rightChild = NULL;

    return node;
}

void nodeFree(Node* node)
{
    if (node == NULL) {
        return;
    }

    if (node->leftChild != NULL) {
        nodeFree(node->leftChild);
        node->leftChild = NULL;
    }

    if (node->rightChild != NULL) {
        nodeFree(node->rightChild);
        node->rightChild = NULL;
    }

    free(node);
}

typedef struct BST {
    Node* root;
} BST;

BST* bstCreate()
{
    BST* tree = malloc(sizeof(BST));
    if (tree == NULL) {
        return NULL;
    }

    tree->root = NULL;

    return tree;
}

void insertRecursive(Node* root, int value)
{
    if (value < root->value) {
        if (root->leftChild == NULL) {
            root->leftChild = nodeCreate(value);
            return;
        }

        insertRecursive(root->leftChild, value);
    } else if (value > root->value) {
        if (root->rightChild == NULL) {
            root->rightChild = nodeCreate(value);
            return;
        }

        insertRecursive(root->rightChild, value);
    }
}

void bstInsert(BST* tree, int value)
{
    if (tree == NULL) {
        return;
    }

    if (tree->root == NULL) {
        tree->root = nodeCreate(value);
        return;
    }

    insertRecursive(tree->root, value);
}

bool containsRecursive(Node* root, int value)
{
    if (root == NULL) {
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

bool bstContains(BST* tree, int value)
{
    if (tree == NULL) {
        return false;
    }

    return containsRecursive(tree->root, value);
}

void bstFree(BST* tree)
{
    if (tree == NULL) {
        return;
    }

    if (tree->root) {
        nodeFree(tree->root);
        tree->root = NULL;
    }

    free(tree);
}

int kthMinRecursive(Node* root, int k, int* count)
{
    if (root == NULL) {
        return INT_MAX;
    }

    int leftResult = kthMinRecursive(root->leftChild, k, count);
    if (k <= *count) {
        return leftResult;
    }

    (*count)++;
    if (k == *count) {
        return root->value;
    }

    return kthMinRecursive(root->rightChild, k, count);
}

int bstKthMin(BST* tree, int k)
{
    if (k <= 0) {
        return INT_MIN;
    }

    if (tree == NULL) {
        return INT_MAX;
    }

    int count = 0;
    return kthMinRecursive(tree->root, k, &count);
}
