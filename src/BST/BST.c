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

Node* deleteNode(Node* node, int value)
{
    if (node == NULL) {
        return NULL;
    }

    if (value < node->value) {
        node->leftChild = deleteNode(node->leftChild, value);
    } else if (value > node->value) {
        node->rightChild = deleteNode(node->rightChild, value);
    } else {
        if (node->leftChild == NULL) {
            Node* temp = node->rightChild;
            free(node);
            return temp;
        } else if (node->rightChild == NULL) {
            Node* temp = node->leftChild;
            free(node);
            return temp;
        } else {
            Node* minNode = node->rightChild;
            while (minNode->leftChild != NULL) {
                minNode = minNode->leftChild;
            }
            node->value = minNode->value;
            node->rightChild = deleteNode(node->rightChild, minNode->value);
        }
    }
    return node;
}

void bstDelete(BST* tree, int value)
{
    if (tree == NULL) {
        return;
    }

    tree->root = deleteNode(tree->root, value);
}