//
// Created by michael on 04/01/19.
//

#include "SegNode.h"


int SegNode :: getL(){
    return l;
}

int SegNode ::getR() {
    return r;
}

int SegNode ::getGcd() {
    return gcd;
}

int SegNode ::getMN() {
    return mn;
}

int SegNode ::getMX() {
    return mx;
}


void SegNode ::setL(int left) {
    l = left;
}

void SegNode ::setR(int right) {
    r = right;
}

void SegNode ::setGCD(int GCD) {
    gcd = GCD;
}

void SegNode ::setMX(int MX) {
    mx = MX;
}

void SegNode ::setMN(int MN) {
    mn = MN;
}