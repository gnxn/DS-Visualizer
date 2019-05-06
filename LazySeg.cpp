//
// Created by michael on 03/05/19.
//

#include "LazySeg.h"

void LazySeg :: psUp(int idx){
    if(tree[idx].getL() != tree[idx].getR()){
        tree[idx].setMX(max(tree[l(idx)].getMX(), tree[r(idx)].getMX()));

        tree[idx].setMN(min(tree[l(idx)].getMN(), tree[r(idx)].getMN()));
    }
}

void LazySeg ::bld(int idx, int l, int r) {
    tree[idx].setL(l);
    tree[idx].setR(r);

    if(l == r){
        int val;
        scanf("%d", &val);
        tree[idx].setMN(val);
        tree[idx].setMX(val);
        return;
    }

    int m = mid(l, r);

    bld(l(idx), l, m);
    bld(r(idx), m+1, r);

    psUp(idx);
}

void LazySeg:: bld(){
    bld(1, 1, N);
}

void LazySeg::psDown(int idx) {
    if(tree[idx].getL() != tree[idx].getR()){
        tree[l(idx)].setMN(tree[l(idx)].getMN() + tree[idx].getLz());
        tree[r(idx)].setMN(tree[r(idx)].getMN() + tree[idx].getLz());
        tree[l(idx)].setMX(tree[l(idx)].getMX() + tree[idx].getLz());
        tree[r(idx)].setMX(tree[r(idx)].getMX() + tree[idx].getLz());

        tree[l(idx)].setLz(tree[l(idx)].getLz() + tree[idx].getLz());
        tree[r(idx)].setLz(tree[r(idx)].getLz() + tree[idx].getLz());

        tree[idx].setLz(0);
    }
}

void LazySeg::upd(int idx, int l, int r, int val) {
    if(tree[idx].getL() == l && tree[idx].getR() == r){
        tree[idx].setMN(tree[idx].getMN() + val);
        tree[idx].setMX(tree[idx].getMX() + val);
        tree[idx].setLz(tree[idx].getLz() + val);

        return;
    }

    // If the node has things that lazy which needs to be pushed down.
    if(tree[idx].getLz()){
        psDown(idx);
    }

    int m = mid(tree[idx].getL(), tree[idx].getR());

    if(r <= m){
        upd(l(idx), l, m, val);
    }else if(l > m){
        upd(r(idx), m + 1, r, val);
    }else{
        upd(l(idx),l,m,val);
        upd(r(idx),m+1, r, val);
    }

    psUp(idx);
}

void LazySeg::upd(int l, int r, int val) {
    upd(1, l, r, val);
}

int LazySeg::qry(int idx, int l, int r, char cmd, int (*op)(int, int)) {
    if(tree[idx].getL() == l && tree[idx].getR() == r){
        if(cmd == 'm'){
            return tree[idx].getMN();
        }
        if(cmd == 'x'){
            return tree[idx].getMX();
        }
    }

    int m = mid(tree[idx].getL(), tree[idx].getR());

    if(r < m){
        return qry(l(idx), l, r, cmd, op);
    }else if(l >= m){
        return qry(r(idx), l, r, cmd, op);
    }

    return op(qry(l(idx), l, m, cmd, op), qry(r(idx), m+1, r, cmd, op));
}

int LazySeg ::getMN(int l, int r) {
    return qry(1, l, r, 'm', min);
}

void LazySeg ::print(int idx){
     printf("Node MN %d, MX %d, lazy %d, left %d, right %d",
                tree[idx].getMN(),tree[idx].getMX(),tree[idx].getLz(), tree[idx].getL(), tree[idx].getR());

}
int LazySeg ::getMX(int l, int r) {
    return qry(1, l, r, 'x', max);
}

void LazySeg ::print_inorder(int idx) {
    if(tree[idx].getL() != tree[idx].getR()){
        print_inorder(l(idx));
        print(idx);
        print_inorder(r(idx));
        return;
    }
    print(idx);
}

void LazySeg::print_inorder() {
    print_inorder(1);
}

void LazySeg::print_postorder(int idx) {

    if(tree[idx].getL() != tree[idx].getR()){
        print_inorder(l(idx));
        print_inorder(r(idx));
        print(idx);
        return;
    }
    print(idx);
}

void LazySeg::print_postorder() {
    print_postorder(1);
}

void LazySeg::print_preorder(int idx) {

    if(tree[idx].getL() != tree[idx].getR()){
        print(idx);
        print_inorder(l(idx));
        print_inorder(r(idx));
        return;
    }
    print(idx);
}

void LazySeg::print_preorder() {
    print_preorder(1);
}
