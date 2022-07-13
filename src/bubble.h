#ifndef __BUBBLE_H_
#define __BUBBLE_H_

#include <vector>

template < typename T >
void bubble(std::vector< T >& myvector) {
    // remember vector s
    T placeholder;
    bool sorted = false;
    while( !sorted ) {
        sorted = true;
        for (auto it = myvector.begin(); it != myvector.end()-1; it++) {
            if (*it > *(it+1)) {
                placeholder = *it;
                *it = *(it+1);
                *(it+1) = placeholder;
                sorted = false;
            }
        }
    }
}

#endif  //__BUBBLE_H_
