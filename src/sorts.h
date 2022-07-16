#ifndef __SORTS_H_
#define __SORTS_H_

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

template < typename T >
// T should be countable in an integer sense. 
// any differences in instances in T should be convertable to an integer
void counter(std::vector< T >& myvector) {
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

template < typename T >
void merge(std::vector< T >& myvector) {
    if (myvector.size() <= 1) {
        return;
    }
    std::vector< T > left, right;
    int midpoint = myvector.size() / 2;
    int i;
    for (i = 0; i < midpoint; i++) {
        left.push_back(myvector[i]);
    }
    int s = myvector.size();
    for (i = midpoint; i < s; i++) {
        right.push_back(myvector[i]);
    }
    merge(left);
    merge(right);
    i = 0;      // left iterator
    int j = 0;  // right iterator
    int k = 0;  // center iterator
    int leftSize = left.size();
    int rightSize = right.size();

    while ((i < leftSize) && (j < rightSize)) {
        if (left[i] < right[j]) {
            myvector[k] = left[i];
            i++;
        }else {
            myvector[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < leftSize) {
        myvector[k] = left[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        myvector[k] = right[j];
        j++;
        k++;
    }
}

template < typename T >
void quick_r(std::vector< T >& myvector, const int& start, const int& end) {
    if (end - start <= 0) {
        return;
    }
    int pivot = start;
    int lgmt = start + 1;
    int i;
    T temp;
    for (i = start+1; i < end+1; i++) {
        if (myvector[i] < myvector[pivot]) {
            temp = myvector[i];
            myvector[i] = myvector[lgmt];
            myvector[lgmt] = temp;
            lgmt++;
        }
    }
    pivot = lgmt-1;
    temp = myvector[pivot];
    myvector[pivot] = myvector[start];
    myvector[start] = temp;

    quick_r(myvector, start, pivot-1);
    quick_r(myvector, pivot+1, end);
}

template < typename T >
void quick(std::vector< T >& myvector) {
    quick_r(myvector, 0, myvector.size()-1);
}

#endif  //__SORTS_H_
