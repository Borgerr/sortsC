#include <iostream>
#include "include.h"
#include "MenuData.h"
#include "ActionData.h"

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

	// try to retain some kind of organization in this menu.
    // Quit should be at the bottom of the list.
	md.addAction("quit", quit, "Exit the program.");
}


// menu options
void bubbleSort(ActionData& ad) {
    int size = getInteger(ad, "How big of a vector? ");
    ad.newVector(size);
    //int i;
    // TODO: output vector and then sort using bubble sort. then output vector again

}
