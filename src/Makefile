CXX := g++
CXXFLAGS := -Werror -Wall -Wextra -Wpedantic
#CXXFLAGS := -Werror -Wall -Wextra -Wpedantic -g#debugger
MISC_HEADERS := vector_funcs.h BST.h Branch.h sorts.h	# added so object files that depend on these program specific headers will recompile whenever those headers are changed
LPFLAGS := -lpthread

all: sort_menu


#programs
sort_menu: sort_menu.o MenuData.o ActionData.o config.o user_io.o options.o
	$(CXX) $(CXXFLAGS) -o sort_menu $^


#object files
sort_menu.o: sort_menu.cpp $(MISC_HEADERS)
	$(CXX) $(CXXFLAGS) -c -o sort_menu.o sort_menu.cpp

MenuData.o: MenuData.cpp MenuData.h
	$(CXX) $(CXXFLAGS) -c -o MenuData.o MenuData.cpp

ActionData.o: ActionData.cpp ActionData.h
	$(CXX) $(CXXFLAGS) -c -o ActionData.o ActionData.cpp

config.o: config.cpp sorts.h $(MISC_HEADERS)
	$(CXX) $(CXXFLAGS) -c -o config.o config.cpp

user_io.o: user_io.cpp
	$(CXX) $(CXXFLAGS) -c -o user_io.o user_io.cpp

options.o: options.cpp $(MISC_HEADERS)
	$(CXX) $(CXXFLAGS) -c -o options.o options.cpp


clean:
	rm -f *.o
	rm -f sort_menu
