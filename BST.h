//
// Created by michael on 02/01/19.
//

#ifndef DS_VIS_BST_H
#define DS_VIS_BST_H

#include <iostream>
#include "Node.h"

#define null nullptr
using namespace std;



class BST {
private:
    Node* root;

    int height(Node* t);

    bool isBalanced(Node* t);

    Node* newNode(Node* left, Node* right, Node* par, int val, int w);

    Node* insert(Node* t, int val, Node* par);

    Node* remove(Node* t, int val);

    Node* mn(Node* t);

    Node* mx(Node* t);

    void inorder_print(Node* t);

    void preorder_print(Node* t);

    void postorder_print(Node* t);

    void destroy(Node *t);
public:


    int height();


    bool isBalanced();


    void insert(int val);


    void remove(int val);

    void inorder_print();

    void preorder_print();

    void postorder_print();

    void destroy();
    BST(){
        root = null;
    }
};


#endif //DS_VIS_BST_H
