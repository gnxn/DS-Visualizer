//
// Created by michael on 02/05/19.
//

#include "SegmentTree.h"


SegNode SegmentTree ::getidx(int idx) {
    return tree[idx];
}

int SegmentTree ::get(int idx, int l, int r, int (*op)(int, int), char cmd) {
    if(tree[idx].getL() == l && tree[idx].getR() == r){
        if(cmd == 'n'){
            return tree[idx].getMN();
        }
        if(cmd == 'x'){
            return tree[idx].getMX();
        }
        if(cmd == 'g'){
            return tree[idx].getGcd();
        }
    }

    int m = mid(tree[idx].getL(),tree[idx].getR());

    if(r <= m){
        return get(l(idx), l, r,op,cmd);
    }

    if(l > m){
        return get(r(idx), l, r, op, cmd);
    }

    return op(get(l(idx), l, m, op, cmd), get(r(idx), m+1, r, op, cmd));
}



int SegmentTree :: getMN(int l, int r){
    int (*minF)(int,int) = min;
    return get(1, l, r, minF, 'n');
}

int SegmentTree ::getMX(int l, int r) {
    int (*maxF)(int,int) = max;
    return get(1, l, r, maxF, 'x');
}

int SegmentTree ::getGCD(int l, int r) {
    int(*gcdF)(int, int) = gcd;
    return get(1, l, r, gcdF, 'g');
}

void SegmentTree ::psUp(int idx) {
    if(tree[idx].getL() != tree[idx].getR()){
        tree[idx].setGCD(gcd(tree[l(idx)].getGcd(), tree[r(idx)].getGcd()));

        tree[idx].setMX(max(tree[l(idx)].getMX(), tree[r(idx)].getMX()));

        tree[idx].setMN(min(tree[l(idx)].getMN(), tree[r(idx)].getMN()));
    }

}

void SegmentTree ::bld(int idx, int l, int r) {
    tree[idx].setL(l);
    tree[idx].setR(r);

    if(l == r){
        int val;
        scanf("%d",&val);
        tree[idx].setMN(val);
        tree[idx].setMX(val);
        tree[idx].setGCD(val);
        return;
    }

    int m = mid(l, r);

    bld(l(idx), l, m);
    bld(r(idx), m+1, r);

    psUp(idx);
}

void SegmentTree ::upd(int idx, int l, int r, int val) {
    if(tree[idx].getL() == l && tree[idx].getR() == r){
        tree[idx].setMN(val);
        tree[idx].setMX(val);
        tree[idx].setGCD(val);
        return;
    }

    int m = mid(l,r);

    if(tree[idx].getL() > r){
        upd(l(idx), l, m, val);
    }else{
        upd(r(idx), m+1, r, val);
    }

    psUp(idx);
}

void SegmentTree :: upd(int idx, int val){
    upd(idx, 1, N, val);
}

void SegmentTree ::print(int idx, int l, int r) {
    if(tree[idx].getL() == tree[idx].getR()){
        printf("Node %d, left range %d, right range %d\n", idx, tree[idx].getL(),tree[idx].getR());
        printf("MX %d, MN %d, GCD %d\n",tree[idx].getMX(), tree[idx].getMN(), tree[idx].getGcd());
        return;
    }

    print(l(idx), l, r);
    print(r(idx), l, r);

    printf("Node %d, left range %d, right range %d\n", idx, tree[idx].getL(),tree[idx].getR());
    printf("MX %d, MN %d, GCD %d\n",tree[idx].getMX(), tree[idx].getMN(), tree[idx].getGcd());

}

void SegmentTree :: print(){
    print(1,1,N);
}

