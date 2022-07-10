// Use these functions to get better user input output.
#include <iostream>	// std::cout, std::cin
#include <string>	// std::string
#include "include.h"// allows for export
#include "ActionData.h"

int getInteger(ActionData& ad, const std::string& prompt) {
	int i;
	ad.getOS() << prompt;
	ad.getIS() >> i;
	return i;
}

std::string getString(ActionData& ad, const std::string& prompt) {
	std::string i;
	ad.getOS() << prompt;
	ad.getIS() >> i;
	return i;
}

double getDouble(ActionData& ad, const std::string& prompt) {
	double i;
	ad.getOS() << prompt;
	ad.getIS() >> i;
	return i;
}

std::string getChoice(ActionData& ad) {
	return getString(ad, "Choice? ");
}

void commentLine(ActionData& ad) {
	char current;
	while ((current != '\n') && (ad.getIS().good())) {
		ad.getIS().read((char *) &current, sizeof(current));
	}
}

void quit(ActionData& ad) {
	ad.setDone();
}
