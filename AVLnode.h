//
// Created by michael on 06/05/19.
//

#ifndef DS_VIS_AVLNODE_H
#define DS_VIS_AVLNODE_H

#include "Utilities.h"

using namespace std;

class AVLnode {

private:
    int val;
    int height;
    int weight;
    AVLnode *left = null;
    AVLnode *right = null;

public:

    int getVal();

    int getHt();

    int getWt();

    AVLnode* getL();

    AVLnode* getR();

    void setVal(int v);

    void setHt(int h);

    void setWt(int w);

    void setL(AVLnode* l);

    void setR(AVLnode* r);

    AVLnode(int v, int h, int w){
        val = v;
        height = h;
        weight = w;
    }


};


#endif //DS_VIS_AVLNODE_H
