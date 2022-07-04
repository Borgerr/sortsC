#include <cstdlib>
#include <iostream>
#include "ActionData.h"

ActionData::ActionData(std::istream& is, std::ostream& os) 
	: mIs(is), mOs(os), done(false) {
}

std::istream& ActionData::getIS() {
	return mIs;
}

std::ostream& ActionData::getOS() {
	return mOs;
}

bool ActionData::getDone() const {
	return done;
}

void ActionData::setDone() {
	done = true;
}

ActionData::~ActionData() {
	if (mVector != 0) {
		delete mVector;
	}
}

std::vector<int>& ActionData::getVector() {
    return *mVector;
}

void ActionData::newVector(const int& size) {
    if (mVector != 0) {
        delete mVector;
    }
    mVector = new std::vector<int>;
    getVector().resize(size);

    int i, tempValue;
    for (i = 0; i < size; i++) {
        tempValue = std::rand() % size + 1;
        getVector()[i] = tempValue;
    }
}
