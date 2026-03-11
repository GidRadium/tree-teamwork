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

// Returns tree height. O(size).
int bstHeight(BST* tree);

// Returns tree size. O(size).
int bstSize(BST* tree);

// Returns smallest value stored in tree. INT_MAX from <limits.h> if tree is empty or NULL.
int bstMin(BST* tree);

// Returns biggest value stored in tree. INT_MIN from <limits.h> if tree is empty or NULL.
int bstMax(BST* tree);
