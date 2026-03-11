#include "BST.h"

#include <stdbool.h>
#include <stdio.h>
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

void bstInorderNode(Node* node)
{
    if (node == NULL) {
        return;
    }

    bstInorderNode(node->leftChild);
    printf("%d", node->value);
    bstInorderNode(node->rightChild);
}

void bstPreorderNode(Node* node)
{
    if (node == NULL) {
        return;
    }

    printf("%d", node->value);
    bstPreorderNode(node->leftChild);
    bstPreorderNode(node->rightChild);
}

void bstPostorderNode(Node* node)
{
    if (node == NULL) {
        return;
    }

    bstPostorderNode(node->leftChild);
    bstPostorderNode(node->rightChild);
    printf("%d", node->value);
}

void bstInorder(BST* tree)
{
    if (tree == NULL) {
        return;
    }

    bstInorderNode(tree->root);
}

void bstPreorder(BST* tree)
{
    if (tree == NULL) {
        return;
    }

    bstPreorderNode(tree->root);
}

void bstPostorder(BST* tree)
{
    if (tree == NULL) {
        return;
    }

    bstPostorderNode(tree->root);
}