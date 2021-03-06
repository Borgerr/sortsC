// file created for intent to reduce complexity when including
// include all new sorts and header files here

#ifndef __INCLUDE_H_
#define __INCLUDE_H_

#include <iostream>
#include "ActionData.h"
#include "MenuData.h"

// declarations (user_io.cpp)
int getInteger(ActionData& ad, const std::string& prompt);
std::string getString(ActionData& ad, const std::string& prompt);
double getDouble(ActionData& ad, const std::string& prompt);
std::string getChoice(ActionData& ad);
void commentLine(ActionData& ad);
void quit(ActionData& ad);

// declarations (config.cpp)
void showMenu(MenuData& md, ActionData& ad);
void takeAction(const std::string& choice, MenuData& md, ActionData& ad);
int sortMenu(std::istream& is, std::ostream& os);
void configureMenu(MenuData& md);
void templateSort(ActionData& ad, const std::string& sortName);
void refreshVector(ActionData& ad);

// declarations (options.cpp)
void testBST(ActionData& ad);
void quickSort(ActionData& ad);
void counterSort(ActionData& ad);
void bubbleSort(ActionData& ad);
void mergeSort(ActionData& ad);

void newBST(ActionData& ad);
void testBstInsert(ActionData& ad);
void bstInsertSpecific(ActionData& ad);
void testBstSize(ActionData& ad);
void deleteBranch(ActionData& ad);
void bstExistsSpecific(ActionData& ad);

#endif //__INCLUDE_H_
