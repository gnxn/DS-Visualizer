//
// Created by michael on 04/01/19.
//

#ifndef DS_VIS_SEGNODE_H
#define DS_VIS_SEGNODE_H


class SegNode {
private:
    int l, r;

    int gcd;

    int mx;

    int mn;

public:

    int getL();

    int getR();

    int getGcd();

    int getMX();

    int getMN();

    void setL(int left);

    void setR(int right);

    void setGCD(int GCD);

    void setMX(int MX);

    void setMN(int MN);

};


#endif //DS_VIS_SEGNODE_H
