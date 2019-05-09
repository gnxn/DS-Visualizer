//
// Created by michael on 06/05/19.
//

#include "AVL.h"

int AVL::getSz(AVLnode *node) {
    if(node){
        return node->getWt();
    }

    return 0;
}

int AVL::getSz() {
    return getSz(root);
}

int AVL::getHt(AVLnode *node) {
    if(node){
        return node->getHt();
    }
    return -1;
}

int AVL::getHt() {
    return getHt(root);
}

void AVL::upd(AVLnode *node) {
    if(node){
        node->setWt(1 + (node->getR() ? node->getR()->getWt() : 0)
                      + (node->getL() ? node->getL()->getWt() : 0));
        node->setHt(1 + max( (node->getL() ? node->getL()->getHt() : 0),
                             (node->getR() ? node->getR()->getHt() : 0)));
    }
}

int AVL::heightDif(AVLnode *node) {
    int hL = getHt(node->getL());
    int hR = getHt(node->getR());

    return (hL - hR);

}

AVLnode* AVL::rotateR(AVLnode *node) {
    AVLnode* temp = node->getL();
    node->setL(temp->getR());
    temp->setR(node);
    upd(node);
    upd(temp);

    return temp;
}

AVLnode* AVL::rotateL(AVLnode *node){
    AVLnode* temp = node->getR();
    node->setR(temp->getL());
    temp->setL(node);
    upd(node);
    upd(temp);
    return temp;
}

AVLnode* AVL::balance(AVLnode* node){
    int dif = heightDif(node);

    // If the left is much shorter, rotate to left
    if(dif < -1){
        if(heightDif(node->getL()) > 0 ){
            node->setR(rotateR(node->getR()));
        }

        node = rotateL(node);
    }
    // If the left is much longer, rotate to the right
    else if(dif > 1){
        if(heightDif(node->getR()) > 0){
            node->setL(rotateL(node->getL()));
        }

        node = rotateR(node);
    }

    return node;
}

AVLnode* AVL::insert(AVLnode *node, int val) {
    if(node == null){
        return new AVLnode(val, 0 , 1); // height 0, weight 1
    }


    if(node->getVal() > val){
        node->setL(insert(node->getL(), val));
    }else if(node->getVal() < val){
        node->setR(insert(node->getR(), val));
    }

    return balance(node);
}

void AVL::insert(int val){
    root = insert(root, val);
}

bool AVL::isEmpty() {
    return root ? false : true;
}

AVLnode* AVL::getMin(AVLnode *node) {
    // Going to the left regardless

    if(node && node->getL() == null){
        return node;
    }

    return getMin(node->getL());
}

AVLnode* AVL::getMax(AVLnode *node) {
    // Going to the right regardless

    if(node && node->getR() == null){
        return node;
    }

    return getMax(node->getR());
}

bool AVL::contains(AVLnode *node, int val) {
    if(node){
        if(node->getVal() == val){
            return true;
        }
        if(node->getVal() < val){
            return contains(node->getR(), val);
        }
        if(node->getVal() > val){
            return contains(node->getL(), val);
        }
    }
    return false;
}

bool AVL::contains(int val) {
    return contains(root, val);
}

AVLnode* AVL::removeMin(AVLnode *node) {
    if(node){
        if(node->getL() == null){
            return node;
        }
        node->setL(removeMin(node->getL()));
    }

    return balance(node);
}

AVLnode* AVL::removeMax(AVLnode *node) {
    if(node){
        if(node->getR() == null){
            return node;
        }
        node->setR(removeMax(node->getR()));
    }

    return balance(node);
}

void AVL::valuesSorted(AVLnode *node, vector<int> &vec) {
    if(node){
        valuesSorted(node->getL(), vec);
        vec.push_back(node->getVal());
        valuesSorted(node->getR(), vec);
    }
}

vector<int> AVL::valuesSorted() {
    vector<int> vec = {};
    valuesSorted(root, vec);
    return vec;
}

// rank is the number of node that are smaller or equal to the asked value
int AVL::getRk(AVLnode *node, int val) {

    if(node == null){
        return 0;
    }

    if(val <= node->getVal()){
        return getRk(node->getL(), val);
    }

    // The node itself, the number in the right subtree, the entire left subtree
    return 1 + getRk(node->getR(), val) + getSz(node->getL());
}

int AVL::getRk(int val) {
    return getRk(root, val);
}

// Return the node that is idx largest in the "array"
AVLnode* AVL::select(AVLnode *node, int idx) {
    if(node == null){
        return node;
    }

    int wt = getSz(node->getL());

    if(idx > wt){
        return select(node->getR(), idx - wt - 1); // Total - all left - current node
    }
    if(idx < wt){
        return select(node->getL(), idx);
    }

    // It is equal

    return node;
}

void AVL::valuesBetween(AVLnode *node, int l, int h, vector<int> &vec) {
    if(node){
        if(node->getVal() < l){
            valuesBetween(node->getR(), l, h, vec);
        }
        if(node->getVal() >= l && node->getVal() <= h){
            vec.push_back(node->getVal());
        }
        if(node->getVal() > h){
            valuesBetween(node->getL(), l, h, vec);
        }
    }
}

vector<int> AVL::valuesBetween(int l, int h) {
    vector<int> vec = {};
    valuesBetween(root, l, h, vec);
    return vec;
}

AVLnode* AVL::remove(AVLnode *node, int val) {
    if(node == null){
        return node;
    }

    if(node->getVal() < val){
        node->setR(remove(node->getR(), val));
    }else if(node->getVal() > val){
        node->setL(remove(node->getL(), val));
    }else{
        // The value is now equal
        if(node->getL() == null){
            return node->getR();
        }else if(node->getR() == null){
            return node->getL();
        }else{
            AVLnode* temp = node;

            node = getMin(node->getR());
            node->setR(removeMin(temp->getR()));
            node->setL(temp->getL());
            free(temp);
        }
    }
    return balance(node);
}

void AVL::remove(int val) {
    remove(root, val);
}

