//
// Created by michael on 02/05/19.
//

#ifndef DS_VIS_SEGMENTTREE_H
#define DS_VIS_SEGMENTTREE_H

#include "SegNode.h"
#include <vector>
#include <limits.h>
#include <iostream>

#include "Utilities.h"

#define null nullptr

#define l(x) x<<1
#define r(x) x<<1|1

using namespace std;

class SegmentTree {

private:
    vector<SegNode> tree;

    int N;

    int get(int idx, int l, int r, int(*op)(int,int), char cmd);

    void psUp(int idx);

    void bld(int idx, int l, int r);

    void upd(int idx, int l, int r, int val);

    void print(int idx, int l, int r);
public:
    explicit SegmentTree(int n):tree((int) (2 * pow(2.0, ceil(log2((double) n))))){
        N = n;
        bld(1, 1, n);
    }

    SegNode getidx(int idx);


    int getMN(int l, int r);

    int getMX(int l, int r);

    int getGCD(int l, int r);

    void upd(int idx, int val);

    void print();
};


#endif //DS_VIS_SEGMENTTREE_H
