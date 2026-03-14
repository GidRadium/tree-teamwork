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

void testEmptyTreesMerge()
{
    BST* tree1 = bstCreate();
    assert(tree1);
    BST* tree2 = bstCreate();
    assert(tree2);

    BST* tree3 = bstMerge(tree1, tree2);
    assert(tree3);

    bstInsert(tree3, 3);
    bstInsert(tree2, 3);
    BST* tree4 = bstMerge(tree3, tree2);
    assert(bstContains(tree4, 3));

    BST* tree5 = bstMerge(tree4, tree1);
    assert(bstContains(tree5, 3));
}

void testMergeTrees()
{
    BST* tree1 = bstCreate();
    assert(tree1);
    BST* tree2 = bstCreate();
    assert(tree2);

    int from = -20;
    int to = 100;

    for (int i = from; i < to; ++i) {
        bstInsert(tree1, i);
        bstInsert(tree2, -i);
    }

    BST* tree = bstMerge(tree1, tree2);
    assert(tree);
    assert(!bstContains(tree, -to));
    assert(!bstContains(tree, to));
    for (int i = 1 - to; i < to; ++i) {
        assert(bstContains(tree, i));
    }

    bstFree(tree1);
    bstFree(tree2);
    bstFree(tree);
}

int main(void)
{
    testCreateEmptyTree();
    testSingleInsert();
    testDublicatedInsert();
    testMultipleGrowingInserts();
    testMultipleDiffrentInserts();
    testMergeTrees();

    return 0;
}
