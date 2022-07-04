#ifndef __BUBBLE_H_
#define __BUBBLE_H_

#include <vector>

template < typename T >
void bubble(std::vector< T >& myvector) {
    // remember vector s
    bool sorted = false;
    while( !sorted ) {
        sorted = true;
        for (auto it = myvector.begin(); it != myvector.end(); it++) {
            if (*it > *it+1) {
                *it, *it+1 = *it+1, *it;
                sorted = false;
            }
        }
    }
}

#endif  //__BUBBLE_H_
