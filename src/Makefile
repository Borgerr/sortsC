CXX := g++
CXXFLAGS := -Werror -Wall -Wextra -Wpedantic
#CXXFLAGS := -Werror -Wall -Wextra -Wpedantic -g#debugger
LPFLAGS := -lpthread
SORTFILES := bubble.h

all: sort_menu


#programs
sort_menu: sort_menu.o MenuData.o ActionData.o config.o
	$(CXX) $(CXXFLAGS) -o sort_menu $^


#object files
sort_menu.o: sort_menu.cpp $(SORTFILES)
	$(CXX) $(CXXFLAGS) -c -o sort_menu.o sort_menu.cpp

MenuData.o: MenuData.cpp MenuData.h
	$(CXX) $(CXXFLAGS) -c -o MenuData.o MenuData.cpp

ActionData.o: ActionData.cpp ActionData.h
	$(CXX) $(CXXFLAGS) -c -o ActionData.o ActionData.cpp

config.o: config.cpp
	$(CXX) $(CXXFLAGS) -c -o config.o config.cpp


clean:
	rm -f *.o
	rm -f sort_menu
