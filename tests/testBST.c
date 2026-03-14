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

void testDeleteValue()
{
    BST* tree1 = bstCreate();
    assert(tree1);
    bstInsert(tree1, 10);
    bstDelete(tree1, 10);
    assert(!bstContains(tree1, 10));
    bstFree(tree1);

    BST* tree2 = bstCreate();
    assert(tree2);
    bstInsert(tree2, 1);
    bstInsert(tree2, 2);
    bstInsert(tree2, 3);
    bstDelete(tree2, 1);
    assert(!bstContains(tree2, 1));
    assert(bstContains(tree2, 2));
    assert(bstContains(tree2, 3));
    bstFree(tree2);

    BST* tree3 = bstCreate();
    assert(tree3);
    bstDelete(tree3, 10);
    bstFree(tree3);

    BST* tree4 = bstCreate();
    assert(tree4);
    bstInsert(tree4, 5);
    bstInsert(tree4, 3);
    bstInsert(tree4, 7);
    bstDelete(tree4, 7);
    assert(!bstContains(tree4, 7));
    assert(bstContains(tree4, 5));
    assert(bstContains(tree4, 3));
    bstFree(tree4);

    BST* tree5 = bstCreate();
    bstInsert(tree5, 5);
    bstInsert(tree5, 3);
    bstInsert(tree5, 7);
    bstInsert(tree5, 2);
    bstInsert(tree5, 4);
    bstInsert(tree5, 6);
    bstInsert(tree5, 8);
    bstDelete(tree5, 5);
    assert(!bstContains(tree5, 5));
    assert(bstContains(tree5, 3));
    assert(bstContains(tree5, 7));
    assert(bstContains(tree5, 2));
    assert(bstContains(tree5, 4));
    assert(bstContains(tree5, 6));
    assert(bstContains(tree5, 8));
    bstFree(tree5);
}

int main(void)
{
    testCreateEmptyTree();
    testSingleInsert();
    testDublicatedInsert();
    testMultipleGrowingInserts();
    testMultipleDiffrentInserts();
    testDeleteValue();
    return 0;
}
