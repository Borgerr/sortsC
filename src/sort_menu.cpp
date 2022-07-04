#include <cstdlib>
#include <ctime>
#include <iostream>
#include "include.h"

int main() {
	std::srand(std::time(0));
	return sortMenu(std::cin, std::cout);
}
