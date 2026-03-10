#include "BST.h"
#include <stdio.h>

int main(void)
{
    BST* tree = bstCreate();
    bstInsert(tree, 1);
    if (bstContains(tree, 1)) {
        printf("It is working!\n");
    } else {
        printf("Something went wrong...\n");
    }
    bstFree(tree);

    return 0;
}
