//
// Created by michael on 03/05/19.
//

#ifndef DS_VIS_LAZYNODE_H
#define DS_VIS_LAZYNODE_H


class LazyNode {

private:
    int l, r;
    int mx,mn;
    int lazy;

    int N;
public:
    int getL();

    int getR();

    int getMN();

    int getMX();

    int getLz();

    void setL(int left);

    void setR(int right);

    void setMN(int MN);

    void setMX(int MX);

    void setLz(int val);
};


#endif //DS_VIS_LAZYNODE_H
