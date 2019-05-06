//
// Created by michael on 03/05/19.
//

#ifndef DS_VIS_LAZYSEG_H
#define DS_VIS_LAZYSEG_H

#include "LazyNode.h"
#include "Utilities.h"
#include <limits.h>
#include <vector>
#include <stdio.h>

using namespace std;

class LazySeg {
private:
    vector<LazyNode> tree;

    int N;

    void psUp(int idx);

    void bld(int idx, int l, int r);

    void upd(int idx, int l, int r, int val);

    void psDown(int idx);

    int qry(int idx, int l, int r, char cmd, int(*op)(int, int));

    void print(int idx);

    void print_inorder(int idx);

    void print_preorder(int idx);

    void print_postorder(int idx);

public:
    LazySeg(int n):tree(n*3 + 1){
        N = n;
    }

    void bld();

    void upd(int l, int r, int val);

    int getMN(int l, int r);

    int getMX(int l, int r);

    void print_inorder();

    void print_preorder();

    void print_postorder();



};


#endif //DS_VIS_LAZYSEG_H
