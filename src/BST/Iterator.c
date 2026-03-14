#include "Iterator.h"
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

struct BST {
    Node* root;
};

typedef struct StackNode {
    Node* treeNode;
    struct StackNode* next;
} StackNode;

struct Iterator {
    StackNode* stackTop;
};

void pushLeftChildren(Iterator* it, Node* node)
{
    while (node != NULL) {
        StackNode* newStackNode = malloc(sizeof(StackNode));
        newStackNode->treeNode = node;
        newStackNode->next = it->stackTop;
        it->stackTop = newStackNode;
        node = node->leftChild;
    }
}

Iterator* iteratorInit(BST* tree)
{
    if (tree == NULL) {
        return NULL;
    }

    Iterator* it = malloc(sizeof(Iterator));
    if (it == NULL) {
        return NULL;
    }

    it->stackTop = NULL;
    pushLeftChildren(it, tree->root);

    return it;
}

bool iteratorHasNext(Iterator* it)
{
    return it != NULL && it->stackTop != NULL;
}

int iteratorNext(Iterator* it)
{
    if (it == NULL || it->stackTop == NULL) {
        return -1;
    }

    StackNode* top = it->stackTop;
    Node* currentNode = top->treeNode;
    it->stackTop = top->next;
    free(top);

    if (currentNode->rightChild != NULL) {
        pushLeftChildren(it, currentNode->rightChild);
    }

    return currentNode->value;
}

void iteratorFree(Iterator* it)
{
    if (it == NULL) {
        return;
    }

    while (it->stackTop != NULL) {
        StackNode* temp = it->stackTop;
        it->stackTop = temp->next;
        free(temp);
    }

    free(it);
}
