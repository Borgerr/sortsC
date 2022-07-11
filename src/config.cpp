#include <iostream>
#include <bits/stdc++.h>
#include "include.h"
#include "MenuData.h"
#include "ActionData.h"
#include "vector_funcs.h"
// sorts
#include "bubble.h"

void showMenu(MenuData& md, ActionData& ad) {
	std::vector<std::string> commands = md.getNames();
	unsigned int i;				// iterator
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
    md.addAction("refresh", refreshVector, "Make a new random vector and output its contents.");
	// try to retain some kind of organization in this menu.
    // Quit should be at the bottom of the list.
	md.addAction("quit", quit, "Exit the program.");
}

// menu options
void bubbleSort(ActionData& ad) {   // TODO: verify that this function works the way it should
    int size = getInteger(ad, "How big of a vector? ");
    ad.newVector(size);

    ad.getOS() << "Original vector: ";
    outputVector(ad, ad.getVector());
    
    std::vector<int> copy = ad.getVector();
    bubble(copy);
    std::sort(ad.getVector().begin(), ad.getVector().end());

    ad.getOS() << "Bubble sorted vector: ";
    outputVector(ad, copy);
    ad.getOS() << "C++ std::sorted vector: ";
    outputVector(ad, ad.getVector());
}

void refreshVector(ActionData& ad) {
    int size = getInteger(ad, "How big of a vector? ");
    ad.newVector(size);
    ad.getOS() << "New vector: ";
    outputVector(ad, ad.getVector());
}
