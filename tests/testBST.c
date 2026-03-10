#include "BST.h"
#include <assert.h>

int main(void)
{
    BST* tree = bstCreate();
    bstInsert(tree, 1);
    assert(bstContains(tree, 1));

    return 0;
}
