//
// Created by michael on 01/01/19.
//

#ifndef DS_VIS_NODE_H
#define DS_VIS_NODE_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

using namespace std;

class Node {
private:
    Node *left;
    Node *right;
    // This is for successor and predecessor search

    // The successor of node X is the node
    // with the smallest key greater than X.

    // The predecessor of node X is the node with the
    // greatest key smaller than X.
    Node *parent;

    int val;

    int weight;
public:
    Node *getLeft();

    Node *getRight();

    Node *getParent();

    int getVal();

    int getWeight();

    void setVal(int v);

    void setRight(Node* r);

    void setLeft(Node* l);

    void setParent(Node* par);

    void setWeight(int w);

};


#endif //DS_VIS_NODE_H
