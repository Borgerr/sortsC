#ifndef __COUNTER_H_
#define __COUNTER_H_

#include <vector>

template < typename T >
// T should be countable in an integer sense. 
// any differences in instances in T should be convertable to an integer
void counter(std::vector< T >& myvector) {  // TODO: figure out why this function sometimes doesn't sort the last two elements correctly
    std::vector< T > c; // again, should be convertable to integers
    int k, i, j, size;
    T temp;
    size = myvector.size();
    c.resize(size);
    for (i = 0; i < size; i++) {
        c[myvector[i]]++;
    }
    k = 0;
    for (i = 0; i < size; i++) {
        temp = c[i];
        for (j = 0; j < temp; j++) {
            myvector[k] = i;
            k++;
        }
    }
}

#endif //__COUNTER_H_
