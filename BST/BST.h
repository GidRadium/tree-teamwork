#pragma once

struct BST;

void bstInsert(BST* tree, int value);
bool bstContains(BST* tree, int value);
void bstFree(BST* tree);

void bstInorder(BST* tree);
void bstPreorder(BST* tree);
void bstPostorder(BST* tree);

int bstHeight(BST* tree);
int bstSize(BST* tree);
// Returns Max of int if empty
int bstMin(BST* tree);
// Returns Min of int if empty
int bstMax(BST* tree);
