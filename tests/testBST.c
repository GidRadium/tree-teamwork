#include "BST.h"
#include "Iterator.h"
#include <assert.h>

void testCreateEmptyTree()
{
    BST* tree = bstCreate();
    assert(tree);
    assert(!bstContains(tree, 42));

    bstFree(tree);
}

void testSingleInsert()
{
    BST* tree = bstCreate();
    assert(tree);

    bstInsert(tree, 100);
    assert(bstContains(tree, 100));
    assert(!bstContains(tree, -100));
    assert(!bstContains(tree, 0));

    bstFree(tree);
}

void testDublicatedInsert()
{
    BST* tree = bstCreate();
    assert(tree);

    bstInsert(tree, 100);
    assert(bstContains(tree, 100));
    assert(!bstContains(tree, -100));
    assert(!bstContains(tree, 0));
    bstInsert(tree, 100);
    assert(bstContains(tree, 100));
    bstInsert(tree, -100);
    assert(bstContains(tree, 100));
    assert(bstContains(tree, -100));
    assert(!bstContains(tree, 0));
    bstInsert(tree, -100);
    assert(bstContains(tree, -100));
    assert(bstContains(tree, 100));

    bstFree(tree);
}

void testMultipleGrowingInserts()
{
    int count = 100;

    BST* tree = bstCreate();
    assert(tree);

    for (int i = 0; i < count; ++i) {
        bstInsert(tree, i);
    }

    for (int i = 0; i < count; ++i) {
        assert(bstContains(tree, i));
    }

    assert(!bstContains(tree, -1));
    assert(!bstContains(tree, count));

    bstFree(tree);
}

void testMultipleDiffrentInserts()
{
    int values[] = { 1, 2, 3, -1, -2, 0, 4, -4 };
    int count = 8;

    BST* tree = bstCreate();
    assert(tree);

    for (int i = 0; i < count; ++i) {
        bstInsert(tree, values[i]);
    }

    for (int i = 0; i < count; ++i) {
        assert(bstContains(tree, values[i]));
    }

    assert(!bstContains(tree, 5));
    assert(!bstContains(tree, -5));

    bstFree(tree);
}

void testIteratorEmpty()
{
    BST* tree = bstCreate();
    Iterator* it = iteratorInit(tree);
    assert(it);
    assert(iteratorHasNext(it) == 0);

    iteratorFree(it);
    bstFree(tree);
}

void testIteratorSingleNode()
{
    BST* tree = bstCreate();
    assert(tree);

    bstInsert(tree, 42);

    Iterator* it = iteratorInit(tree);
    assert(it);

    assert(iteratorHasNext(it) == 1);

    int value = iteratorNext(it);
    assert(value == 42);

    assert(iteratorHasNext(it) == 0);

    iteratorFree(it);
    bstFree(tree);
}

void testIteratorInorder()
{
    BST* tree = bstCreate();
    assert(tree);

    bstInsert(tree, 5);
    bstInsert(tree, 3);
    bstInsert(tree, 7);
    bstInsert(tree, 2);
    bstInsert(tree, 4);
    bstInsert(tree, 8);

    Iterator* it = iteratorInit(tree);
    assert(it);

    int expected[] = { 2, 3, 4, 5, 7, 8 };
    int index = 0;
    while (iteratorHasNext(it)) {
        int val = iteratorNext(it);
        assert(val == expected[index]);
        index++;
    }

    assert(index == 6);

    iteratorFree(it);
    bstFree(tree);
}

void testIteratorUnbalanced()
{
    BST* tree = bstCreate();
    assert(tree);

    bstInsert(tree, 1);
    bstInsert(tree, 2);
    bstInsert(tree, 3);
    bstInsert(tree, 4);

    Iterator* it = iteratorInit(tree);
    assert(it);

    int expected[] = { 1, 2, 3, 4 };

    for (int i = 0; i < 4; i++) {
        assert(iteratorHasNext(it) == 1);
        int val = iteratorNext(it);
        assert(val == expected[i]);
    }

    assert(iteratorHasNext(it) == 0);

    iteratorFree(it);
    bstFree(tree);
}


int main(void)
{
    testCreateEmptyTree();
    testSingleInsert();
    testDublicatedInsert();
    testMultipleGrowingInserts();
    testMultipleDiffrentInserts();
    testIteratorEmpty();
    testIteratorSingleNode();
    testIteratorInorder();
    testIteratorUnbalanced();

    return 0;
}
