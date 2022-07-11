// file made for ease of use with different vector types
#ifndef __VECTOR_FUNCS_H_
#define __VECTOR_FUNCS_H_

#include <vector>
#include "ActionData.h"

template < typename T >
void outputVector(ActionData& ad, std::vector< T >& myvector) {
    for (auto it = myvector.begin(); it != myvector.end(); it++) {
        ad.getOS() << *it;
        if (it != myvector.end() - 1) {
            ad.getOS() << ", ";
        }
    }
    ad.getOS() << std::endl;
}

#endif //__VECTOR_FUNCS_H_
