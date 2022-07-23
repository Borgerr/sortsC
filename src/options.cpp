#include <iostream>
#include <vector>
#include <ctime>
#include "include.h"
#include "ActionData.h"
#include "BST.h"
#include "vector_funcs.h"

void bubbleSort(ActionData& ad) {
    templateSort(ad, "bubble");
}

void counterSort(ActionData& ad) {
    templateSort(ad, "counter");
}

void mergeSort(ActionData& ad) {
    templateSort(ad, "merge");
}

void quickSort(ActionData& ad) {
    templateSort(ad, "quick");
}

/*
 *  BST FUNCTIONS VVVVVVV
 */

void newBST(ActionData& ad) {
    ad.newBST();
}

void testBstInsert(ActionData& ad) {
    if (ad.getBST() != 0) {
        int size = getInteger(ad, "How many items? ");
        ad.newVector(size);

        if (size <= 20) {
            ad.getOS() << "Original vector: ";
            outputVector(ad, ad.getVector());
        }

        int i;
        std::clock_t startTime, endTime;
    
        startTime = std::clock();
        for (i = 0; i < size; i++) {
            ad.getBST()->insert(ad.getVector()[i]);
        }
        endTime = std::clock();

        ad.getOS() << "Insert method took " << std::difftime(endTime, startTime) / 1000 << " ms" << std::endl;
    
        for (i = 0; i < size; i++) {
            if (!ad.getBST()->exists(ad.getVector()[i])) {
                ad.getOS() << "Insertion did not insert " << ad.getVector()[i] << " for some reason." << std::endl;
            }
        }
    }else {
        ad.getOS() << "No active BST." << std::endl;
    }
}

void testBstSize(ActionData& ad) {
    if (ad.getBST() != 0) {
        std::clock_t startTime, endTime;

        startTime = std::clock();
        ad.getOS() << "BST size is " << ad.getBST()->size() << " branches." << std::endl;
        endTime = std::clock();

        ad.getOS() << "Size method took " << std::difftime(endTime, startTime) / 1000 << " ms" << std::endl;
    }else {
        ad.getOS() << "No active BST." << std::endl;
    }
}

void deleteBranch(ActionData& ad) {
    if (ad.getBST() != 0) {
        std::clock_t startTime, endTime;
        int deleted = getInteger(ad, "What integer would you like to delete? ");

        startTime = std::clock();
        ad.getBST()->remove(deleted);
        endTime = std::clock();

        ad.getOS() << "Remove method took " << std::difftime(endTime, startTime) / 1000 << " ms" << std::endl;
    }else {
        ad.getOS() << "No active BST." << std::endl;
    }
}

void bstInsertSpecific(ActionData& ad) {
    if (ad.getBST() != 0) {
        std::clock_t startTime, endTime;
        int inserted = getInteger(ad, "What integer would you like to insert? ");
        
        startTime = std::clock();
        ad.getBST()->insert(inserted);
        endTime = std::clock();

        ad.getOS() << "Insert method took " << std::difftime(endTime, startTime) / 1000 << " ms" << std::endl;
    }else {
        ad.getOS() << "No active BST." << std::endl;
    }
}

void bstExistsSpecific(ActionData& ad) {
    if (ad.getBST() != 0) {
        std::clock_t startTime, endTime;
        int exister = getInteger(ad, "What integer would you like to check? ");
        
        startTime = std::clock();
        if (ad.getBST()->exists(exister)) {
            ad.getOS() << exister << " exists in the BST." << std::endl;
        }else {
            ad.getOS() << exister << " does not exist in the BST." << std::endl;
        }
        endTime = std::clock();

        ad.getOS() << "Exist method took " << std::difftime(endTime, startTime) / 1000 << " ms" << std::endl;
    }else {
        ad.getOS() << "No active BST." << std::endl;
    }
}
