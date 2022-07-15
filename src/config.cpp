#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include "include.h"
#include "MenuData.h"
#include "ActionData.h"
#include "vector_funcs.h"
#include "sorts.h"

void showMenu(MenuData& md, ActionData& ad) {
	std::vector<std::string> commands = md.getNames();
	unsigned int i;				        // iterator
	unsigned int len = commands.size();	// iterated
	std::string name;
	for (i=0; i < len; i++) {
		name = commands[i];
		ad.getOS() << name << ") " << md.getDescription(name) << std::endl;
	}
}

void takeAction(const std::string& choice, MenuData& md, ActionData& ad) {
	ActionFunctionType func = md.getFunction(choice);
	if (func != 0) {
		func(ad);
	}else if (choice == "menu") {
		showMenu(md, ad);
	}else {
		ad.getOS() << "Unknown action '" << choice << "'." << std::endl;
	}
}

int sortMenu(std::istream& is, std::ostream& os) {
	ActionData ad(is, os);
	MenuData md;
	configureMenu(md);
	std::string choice;

	while ((!ad.getDone()) && (ad.getIS().good())) {
		choice = getChoice(ad);
		takeAction(choice, md, ad);
	}
	return 0;
}

void configureMenu(MenuData& md) {
	// USE THE FOLLOWING TEMPLATE:
	// md.addAction("name", function, "Long description.");
    md.addAction("bubble", bubbleSort, "Test bubble sort implementation.");
    md.addAction("counter", counterSort, "Test counter sort implementation.");
    md.addAction("merge", mergeSort, "Test merge sort implementation.");
    md.addAction("refresh", refreshVector, "Make a new random vector and output its contents.");
	// try to retain some kind of organization in this menu.
    // Quit should be at the bottom of the list.
	md.addAction("quit", quit, "Exit the program.");
}

// menu options
void bubbleSort(ActionData& ad) {
    templateSort(ad, "bubble");
}

void counterSort(ActionData& ad) {
    templateSort(ad, "counter");
}

void mergeSort(ActionData& ad) {
    templateSort(ad, "merge");
}

void templateSort(ActionData& ad, const std::string& sortName) {
    int size = getInteger(ad, "How big of a vector? ");
    ad.newVector(size);

    ad.getOS() << "Original vector: ";
    outputVector(ad, ad.getVector());

    std::time_t startTime, endTime;
    std::vector<int> copy = ad.getVector();
    std::time(&startTime);
    
    if (sortName == "bubble") {
        bubble(copy);
    }else if (sortName == "counter") {
        counter(copy);
    }else if (sortName == "merge") {
        merge(copy);
    }

    std::time(&endTime);
    std::sort(ad.getVector().begin(), ad.getVector().end());

    if (size <= 20) {
        ad.getOS() << sortName << " sorted vector: ";
        outputVector(ad, copy);
        ad.getOS() << "C++ std::sorted vector: ";
        outputVector(ad, ad.getVector());
    }

    compareVectors(ad, copy, ad.getVector());
    ad.getOS() << "Sort took " << std::difftime(endTime, startTime) << " seconds." << std::endl;
}

void refreshVector(ActionData& ad) {
    int size = getInteger(ad, "How big of a vector? ");
    ad.newVector(size);
    ad.getOS() << "New vector: ";
    outputVector(ad, ad.getVector());
}
