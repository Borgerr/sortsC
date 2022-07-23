#ifndef __ACTIONDATA_
#define __ACTIONDATA_

#include <iostream>
#include <vector>
#include "BST.h"

class ActionData {
public:
	ActionData(std::istream& is, std::ostream& os);
	std::istream& getIS();
	std::ostream& getOS();
	bool getDone() const;
	void setDone();
    std::vector<int>& getVector();
    void newVector(const int& size);
    void newBST();
    BST<int>* getBST();     // I know, I know, this isn't the best formatting, but I was lazy when I implemented this. sorry.
	~ActionData();
protected:
	std::istream& mIs;
	std::ostream& mOs;
	bool done;
    std::vector<int>* mVector;
    BST<int>* mBST;
};

#endif //__ACTIONDATA_
