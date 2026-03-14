#include "BST.h"

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

bool nodeIsValid(Node* node, Node* minNode, Node* maxNode)
{
    if (node == NULL) {
        return true;
    }

    if (minNode != NULL && node->value <= minNode->value) {
        return false;
    }
    
    if (maxNode != NULL && node->value >= maxNode->value) {
        return false;
    }

    if (!nodeIsValid(node->leftChild, minNode, node)) {
        return false;
    }
    if (!nodeIsValid(node->rightChild, node, maxNode)) {
        return false;
    }

    return true;
}

bool bstIsValid(BST* tree)
{
    if (tree == NULL) {
        return false;
    }
    return nodeIsValid(tree->root, NULL, NULL);
}