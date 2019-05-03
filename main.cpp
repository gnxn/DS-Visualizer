#include <iostream>

#include "BST.h"
#include "SegmentTree.h"

using namespace std;

int main() {
    BST* bst = new BST();

    bst->insert(10);

    bst->insert(11);
    bst->insert(9);
    bst->insert(0);

//    bst->inorder_print();

//    printf("\n%d\n",bst->height());
    bst->remove(10);
//    bst->inorder_print();

    bst->destroy();

    SegmentTree *segT = new SegmentTree(3);

    segT->print();
    printf("%d\n",segT->getGCD(1, 3));
    printf("%d\n",segT->getMN(1, 3));
    printf("%d\n",segT->getMX(1, 3));
//

}