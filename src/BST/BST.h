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

// Returns k-th minimum value stored in tree. Returns INT_MIN if k < 0 and INT_MAX if k > size of tree.
int bstKthMin(BST* tree, int k);
