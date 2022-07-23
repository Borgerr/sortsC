#ifndef __BRANCH_H_
#define __BRANCH_H_

template < typename T >
class Branch {

public:
    Branch();
    ~Branch();
    T& getItem();
    Branch* getLeft();    // returns pointer to left node
    Branch* getRight();   // returns pointer to right node
    void setLeft(Branch< T >* ptr);
    void setRight(Branch< T >* ptr);
    bool operator==(const Branch& rhs) const;
    bool operator!=(const Branch& rhs) const;
    bool operator< (const Branch& rhs) const;
    bool operator> (const Branch& rhs) const;
    bool operator<=(const Branch& rhs) const;
    bool operator>=(const Branch& rhs) const;

private:
    T* pItem;            // pointer to own item
    Branch< T >* pLeft;  // pointer to the left branch
    Branch< T >* pRight; // pointer to the right branch

};

template < typename T >
Branch< T >::Branch() 
    : pItem(0), pLeft(0), pRight(0) {
        pItem = new T;
}

template < typename T >
Branch< T >::~Branch< T >() {
    if (pItem != 0) {
        delete pItem;
    }
}

template < typename T >
T& Branch< T >::getItem() {
    return (*pItem);
}

template < typename T >
Branch< T >* Branch< T >::getLeft() {
    return pLeft;
}

template < typename T >
Branch< T >* Branch< T >::getRight() {
    return pRight;
}

template < typename T >
void Branch< T >::setLeft(Branch< T >* ptr) {
    pLeft = ptr;
}

template < typename T >
void Branch< T >::setRight(Branch< T >* ptr) {
    pRight = ptr;
}

template < typename T >
bool Branch< T >::operator==(const Branch& rhs) const {
    return (getItem() == rhs.getItem());
}

template < typename T >
bool Branch< T >::operator!=(const Branch& rhs) const {
    return !(operator==(rhs.getItem()));
}

template < typename T >
bool Branch< T >::operator< (const Branch& rhs) const {
    return (getItem() < rhs.getItem());
}

template < typename T >
bool Branch< T >::operator> (const Branch& rhs) const {
    return (operator!=(rhs) && !operator<(rhs));
}

template < typename T >
bool Branch< T >::operator<=(const Branch& rhs) const {
    return (operator<(rhs) || operator==(rhs));
}

template < typename T >
bool Branch< T >::operator>=(const Branch& rhs) const {
    return (operator>(rhs) || operator==(rhs));
}

#endif //__BRANCH_H_
