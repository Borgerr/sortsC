#ifndef __BST_H_
#define __BST_H_
#include "Branch.h"

template < typename T >
class BST {

public:
    BST();
    ~BST();
    void insert(const T item);
    void remove(const T& item);
    bool exists(const T& item) const;
    int size() const;
    //T retrieve(const T& item) const;

private:
    Branch< T >* pRoot;  // pointer to root branch
    Branch< T >* insertR(Branch< T >* ptr, Branch< T >* current);
    Branch< T >* removeR(const T& item, Branch< T >* current);
    bool existsR(const T& item, Branch< T >* current) const;
    void sizeR(int& counter, Branch< T >* current) const;
    //T retrieveR(const T& item) const;

};

template < typename T >
BST< T >::BST()
    : pRoot(0) {
}

template < typename T >
BST< T >::~BST() {
    delete pRoot;
}

template < typename T >
void BST< T >::insert(const T item) {
    // relies on correct BST::exists() implementation
    if (!(exists(item))) {
        Branch< T >* ptr = new Branch< T >;
        ptr->getItem() = item;
        pRoot = insertR(ptr, pRoot);
    }
}

template < typename T >
void BST< T >::remove(const T& item) {
    if (exists(item)) {
        pRoot = removeR(item, pRoot);
    }
}

template < typename T >
bool BST< T >::exists(const T& item) const {
    return existsR(item, pRoot);
}

template < typename T >
int BST< T >::size() const {
    int i = 0;
    sizeR(i, pRoot);
    return i;
}

/*
 *  recursive portions of methods
 */

template < typename T >
Branch< T >* BST< T >::insertR(Branch< T >* ptr, Branch< T >* current) {
    if (current == 0) {
        current = ptr;
    }else if (current->getItem() < ptr->getItem()) {
        current->setRight(insertR(ptr, current->getRight()));
    }else {
        current->setLeft(insertR(ptr, current->getLeft()));
    }
    return current;
}

template < typename T >
Branch< T >* BST< T >::removeR(const T& item, Branch< T >* current) {
    if (current->getItem() < item) {
        current->setRight(removeR(item, current->getRight()));
    }else if (current->getItem() > item) {
        current->setLeft(removeR(item, current->getLeft()));
    }else {
        if ((current->getLeft() == 0) && (current->getRight() == 0)) {   // no child case
            delete current;
        }else if (current->getLeft() == 0) {    // right child case
            Branch< T >* pTemp = current;
            current = current->getRight();
            delete pTemp;
        }else if (current->getRight() == 0) {   // left child case
            Branch< T >* pTemp = current;
            current = current->getLeft();
            delete pTemp;
        }else {                                 // both child case
            Branch< T >* pSuccessor = current->getRight();
            while (pSuccessor->getLeft() != 0) {
                pSuccessor = pSuccessor->getLeft();
            }
            current->getItem() = pSuccessor->getItem();
            current->setRight(removeR(pSuccessor->getItem(), current->getRight()));
        }
    }
    return current;
}

template < typename T >
bool BST< T >::existsR(const T& item, Branch< T >* current) const {
    if (current == 0) {
        return false;
    }
    if (current->getItem() == item) {
        return true;
    }
    if (item < current->getItem()) {        // go to the left
        return existsR(item, current->getLeft());
    }else if (item > current->getItem()){   // go to the right
        return existsR(item, current->getRight());
    }
    return false;
}

template < typename T >
void BST< T >::sizeR(int& counter, Branch< T >* current) const {
    if (current != 0) {
        counter++;
        sizeR(counter, current->getLeft());
        sizeR(counter, current->getRight());
    }
}

#endif //__BST_H_
