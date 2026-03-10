#include "BST.h"
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
    int values[] = {1, 2, 3, -1, -2, 0, 4, -4};
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

int main(void)
{
    testCreateEmptyTree();
    testSingleInsert();
    testDublicatedInsert();
    testMultipleGrowingInserts();
    testMultipleDiffrentInserts();

    return 0;
}
