#pragma once

#include "BST.h"
#include <stdbool.h>

// Binary tree iterator.
typedef struct Iterator Iterator;

// Creates an iterator for the tree.
Iterator* iteratorInit(BST* tree);

// Checking if an iterator has the next element.
bool iteratorHasNext(Iterator* it);

/*
* Returns the value of the next node and advances the iterator.
* If the iterator is exhausted, returns -1.
 */
int iteratorNext(Iterator* it);

// Frees the memory occupied by the iterator.
void iteratorFree(Iterator* it);