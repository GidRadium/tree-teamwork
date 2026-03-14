#pragma once

#include <stdbool.h>

// Binary Search Tree
typedef struct BST BST;

// Allocates memory for tree with no elements in it.
BST* bstCreate();

// Inserts value to the tree. Allocates memory for it. Do nothing if BST already contains it.
void bstInsert(BST* tree, int value);

// Checks if value is in tree.
bool bstContains(BST* tree, int value);

// Free all allocated memory for tree and values in it.
void bstFree(BST* tree);

// Traverses each node in the tree and outputs its value using In-order traversal.
void bstInorder(BST* tree);

// Traverses each node in the tree and outputs its value using Pre-order traversal.
void bstPreorder(BST* tree);

// Traverses each node in the tree and outputs its value using Post-order traversal.
void bstPostorder(BST* tree);