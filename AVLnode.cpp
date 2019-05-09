//
// Created by michael on 06/05/19.
//

#include "AVLnode.h"

int AVLnode::getVal() {
    return val;
}

int AVLnode::getHt() {
    return height;
}

int AVLnode::getWt() {
    return weight;
}

AVLnode* AVLnode::getR() {
    return right;
}

AVLnode* AVLnode::getL() {
    return left;
}

void AVLnode::setR(AVLnode *r) {
    right = r;
}

void AVLnode::setL(AVLnode *l) {
    left = l;
}

void AVLnode::setVal(int v) {
    val = v;
}

void AVLnode::setHt(int h) {
    height = h;
}

void AVLnode::setWt(int w) {
    weight = w;
}