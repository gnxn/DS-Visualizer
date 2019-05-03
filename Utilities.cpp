//
// Created by michael on 01/05/19.
//

#include "Utilities.h"

int gcd(int a, int b){
    if(a == 0){
        return b;
    }

    return gcd(b % a, a);
}

int mid(int a, int b){
    return a + (b - a)/2;
}

int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a > b ? b : a;
}

int abs(int a){
    return a < 0 ? -a : a;
}


