#pragma once

#include <stdbool.h>

typedef struct BST BST;

BST* bstCreate();
void bstInsert(BST* tree, int value);
bool bstContains(BST* tree, int value);
void bstFree(BST* tree);

// Inorder depth-first traversal
void bstInorder(BST* tree);
// Preorder depth-first traversal
void bstPreorder(BST* tree);
// Postorder depth-first traversal
void bstPostorder(BST* tree);

int bstHeight(BST* tree);
int bstSize(BST* tree);
// Returns Max of int if empty
int bstMin(BST* tree);
// Returns Min of int if empty
int bstMax(BST* tree);
