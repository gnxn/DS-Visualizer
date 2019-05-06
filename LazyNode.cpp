//
// Created by michael on 03/05/19.
//

#include "LazyNode.h"

int LazyNode ::getL() {
    return l;
}

int LazyNode ::getR() {
    return r;
}

int LazyNode ::getMN() {
    return mn;
}

int LazyNode ::getMX() {
    return mx;
}


int LazyNode ::getLz() {
    return lazy;
}

void LazyNode::setR(int right) {
    r = right;
}

void LazyNode ::setL(int left) {
    l = left;
}

void LazyNode ::setMN(int upd) {
    mn = upd;
}

void LazyNode ::setMX(int MX) {
    mx = MX;
}


void LazyNode ::setLz(int val) {
    lazy = val;
}
