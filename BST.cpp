//
// Created by michael on 02/01/19.
//

#include "BST.h"
#include "Node.h"
#include "Utilities.h"


int BST :: height(Node* t){
    if(t == null){
        return 0;
    }

    if(t->getLeft() == null && t->getRight() == null){
        return 1;
    }

    int ans = max(height(t->getLeft()),height(t->getRight()));

    return ans + 1;
}

int BST :: height(){
    return height(root);
}

Node* BST::newNode(Node* l, Node* r, Node* par, int v,int w) {
    Node* node = new Node();

    node->setLeft(l);
    node->setRight(r);
    node->setParent(par);
    node->setVal(v);
    node->setWeight(w);

    return node;
}

bool BST :: isBalanced(Node* t){
    // If the tree is empty, it is defined to be balanced
    if(t == null){
        return true;
    }

    // If the tree has a single node, it is defined to be balanced
    if(t->getLeft() == null && t->getRight() == null){
        return true;
    }

    // One side is empty, the other side must be of one or no node
    if(t->getLeft() == null){
        return t->getRight() == null ||
               t->getRight()->getWeight() == 1;
    }

    if(t->getRight() == null){
        return t->getLeft() == null ||
               t->getLeft()->getWeight() == 1;
    }

    // Both sides have children, the weight difference must be smaller or equal to 1
    // and both sides must be balanced

    return abs(t->getLeft()->getWeight() - t->getRight()->getWeight()) <= 1 &&
           isBalanced(t->getLeft()) && isBalanced(t->getRight());
}

bool BST :: isBalanced(){
    return isBalanced(root);
}

Node* BST :: insert(Node* t, int val, Node* par){
    if(t == null){
        return newNode(null, null, par, val, 1);
    }

    if(t->getVal() < val){
        t->setRight(insert(t->getRight(),val,t));
    }else if (t->getVal() > val){
        t->setLeft(insert(t->getLeft(),val,t));
    }

    return t;
}

void BST :: insert(int v){
    root = insert(root, v, null);
}

Node* BST :: mn(Node* t){

    Node* temp = null;
    if(t && t->getLeft()){
        temp = mn(t->getLeft());
    }else{
        temp = t;
    }

    return temp;
}

Node* BST :: mx(Node* t){
    Node *temp = null;
    if(t && t->getRight()){
        temp = mx(t->getRight());
    }else{
        temp = t;
    }

    return temp;
}


Node* BST :: remove(Node* t, int val){
    if(t){
        if(t->getVal() < val){
            t->setRight(remove(t->getRight(), val));
        }
        if(t->getVal() > val){
            t->setLeft(remove(t->getLeft(), val));
        }

        if(t->getVal() == val){
            if(t->getLeft() == null && t->getRight() == null){
                free(t);
                t = null;
            }else if(t->getLeft() == null){
                Node* temp = t->getRight();
                free(t);
                return temp;
            }else if(t->getLeft() == null){
                Node* temp = t->getLeft();
                free(t);
                return temp;
            }else{
                Node* nxt = t->getRight();
                Node* parent = null;

                while(nxt->getLeft()){
                    parent = nxt;
                    nxt = nxt->getLeft();
                }

                t->setVal(nxt->getVal());

                if(parent){
                    parent->setLeft(nxt->getRight());
                }else{
                    t->setRight(nxt->getRight());
                }

                free(nxt);
            }
        }
    }

    return t;
}

void BST :: remove(int val){
    remove(root, val);
}

void BST :: inorder_print(Node* t){

    if(t){
        inorder_print(t->getLeft());
        printf("%d ",t->getVal());
        inorder_print(t->getRight());
    }
}

void BST :: inorder_print(){
    inorder_print(root);
}

void BST ::preorder_print(Node *t) {
    if(t){
        printf("%d ",t->getVal());
        preorder_print(t->getLeft());
        preorder_print(t->getRight());
    }
}


void BST ::preorder_print() {
    preorder_print(root);
}


void BST ::postorder_print(Node *t) {
    if(t){
        postorder_print(t->getLeft());
        postorder_print(t->getRight());

        printf("%d ",t->getVal());
    }
}

void BST ::postorder_print() {
    postorder_print(root);
}

void BST :: destroy(Node* t){
    if(t){
        destroy(t->getLeft());
        destroy(t->getRight());

        free(t);
    }
}

void BST :: destroy(){
    destroy(root);
}