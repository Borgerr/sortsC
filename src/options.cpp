#include <iostream>
#include "include.h"
#include "ActionData.h"
#include "MenuData.h"   // may not actually need to be used
//#include "BST.h"

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
