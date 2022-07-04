#ifndef __ACTIONDATA_
#define __ACTIONDATA_

#include <iostream>
#include <vector>

class ActionData {
public:
	ActionData(std::istream& is, std::ostream& os);
	std::istream& getIS();
	std::ostream& getOS();
	bool getDone() const;
	void setDone();
    std::vector<int>& getVector();
    void newVector(const int& size);
	~ActionData();
protected:
	std::istream& mIs;
	std::ostream& mOs;
	bool done;
    std::vector<int>* mVector;
};

#endif //__ACTIONDATA_
