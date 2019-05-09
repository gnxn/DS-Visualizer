//
// Created by michael on 06/05/19.
//

#ifndef DS_VIS_AVL_H
#define DS_VIS_AVL_H

#include "Utilities.h"
#include "AVLnode.h"

using namespace std;

class AVL {
private:
    int N;
    AVLnode* root = null;

    int getSz(AVLnode* node);

    int getHt(AVLnode* node);

    int heightDif(AVLnode* node);

    int getRk(AVLnode* node,int val);

    bool contains(AVLnode* node, int val);

    void upd(AVLnode* node);

    void valuesSorted(AVLnode* node, vector<int> &vec);

    void valuesBetween(AVLnode* node, int l, int h, vector<int> &vec);

    AVLnode* insert(AVLnode* node, int val);

    AVLnode* rotateR(AVLnode* node);

    AVLnode* rotateL(AVLnode* node);

    AVLnode* balance(AVLnode* node);

    AVLnode* getMin(AVLnode* node);

    AVLnode* getMax(AVLnode* node);

    AVLnode* removeMin(AVLnode* node);

    AVLnode* removeMax(AVLnode* node);

    AVLnode* remove(AVLnode* node, int val);

    AVLnode* select(AVLnode* node, int idx);
public:

    int getSz();

    int getHt();

    int getRk(int val);

    void insert(int val);

    void remove(int val);

    bool isEmpty();

    bool contains(int val);

    vector<int> valuesSorted();

    vector<int> valuesBetween(int l, int h);

};


#endif //DS_VIS_AVL_H
