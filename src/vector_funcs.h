// file made for ease of use with different vector types
#ifndef __VECTOR_FUNCS_H_
#define __VECTOR_FUNCS_H_

#include <vector>
#include "ActionData.h"

template < typename T >
void outputVector(ActionData& ad, std::vector< T >& myvector) {
    if (myvector.size() > 20) {
        return;
    }
    for (auto it = myvector.begin(); it != myvector.end(); it++) {
        ad.getOS() << *it;
        if (it != myvector.end() - 1) {
            ad.getOS() << ", ";
        }
    }
    ad.getOS() << std::endl;
}

template < typename T >
void compareVectors(ActionData& ad, const std::vector< T >& v1, const std::vector< T >& v2) {
    if (v1.size() != v2.size()) {
        ad.getOS() << "Vectors do not match." << std::endl;
    }
    bool matching = true;
    int i, max;
    max = v1.size();
    for (i = 0; i < max; i++) {
        if (v1[i] != v2[i]) {
            matching = false;
            break;
        }
    }
    if (matching) {
        ad.getOS() << "Vectors match." << std::endl;
    }else {
        ad.getOS() << "Vectors do not match." << std::endl;
    }
}

#endif //__VECTOR_FUNCS_H_
