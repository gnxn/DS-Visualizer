#include <iostream>

#include "BST.h"

int main() {
    BST* bst = new BST();

    bst->insert(10);

    bst->insert(11);
    bst->insert(9);
    bst->insert(0);

    bst->remove(10);
    bst->inorder_print();

    bst->destroy();
}