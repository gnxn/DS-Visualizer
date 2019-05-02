//
// Created by michael on 02/01/19.
//

#ifndef DS_VIS_BST_H
#define DS_VIS_BST_H

#include <iostream>
#include "Node.h"
using namespace std;

#define max(a,b) a < b ? b : a

#define min(a,b) a < b ? a : b

#define null nullptr

#define abs(a) a < 0 ? -a : a

class BST {
private:
    Node* root;


public:

    static int height(Node* t);

    int height();

    bool isBalanced(Node* t);

    bool isBalanced();

    Node* newNode(Node* left, Node* right, Node* par, int val, int w);

    Node* insert(Node* t, int val, Node* par);

    void insert(int val);

    Node* remove(Node* t, int val);

    void remove(int val);

    Node* mn(Node* t);

    Node* mx(Node* t);

    BST(){
        root = null;
    }
};


#endif //DS_VIS_BST_H
