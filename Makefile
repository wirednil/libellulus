CC 			= gcc
CXX			= g++
FLAGS		= -Wall -Wextra -g
LIBNAME 	= -Wl,-soname,libelus.so.1
LIBINC		= -Iinc -Iinc/Logger
LIBSO 		= ./lib/libname.so.1.0
OBJ			= ./obj
SRC			= ./src
TEST		= ./test


main: $(OBJ)/*.o
	$(CXX) $(FLAGS) $(TEST)/main.cc $(LIBINC) -o main $(OBJ)/*.o

# g++ -Wall -Wextra -g -c ./src/Logger/Logger.cpp -o ./obj/Logger.o -Iinc -Iinc/Logger
Logger.o: Logger.cpp
	$(CXX) $(FLAGS) -c $(SRC)/Logger/Logger.cpp -o $(OBJ)/Logger.o $(LIBINC)