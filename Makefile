#------------------------------------------------------------------------------ 
# This Makefile is designed to compile and generate a shared library called 
# libelus.so.1.0. This library is built from two source files in C++ and C 
# in the src and src/Logger directories, respectively. The generated object
# files are stored in the obj directory. In addition, there are two additional 
# targets: cmain and cxmain, which can be used to compile a test program in C and
# C++ using the generated library.
# 
# 
# To compile the source files, the C++ compiler g++ and the C compiler gcc are used. 
# The -fPIC flag is used to generate position independent objects. The generated 
# library file is stored in the lib directory.
#------------------------------------------------------------------------------ 

0=o
# Application paths
SRC_DIR		= ./src
INC_DIR		= ./inc
OBJ_DIR		= ./obj
LSO_DIR		= ./lso
TEST		= ./test

# Module list
OBJ_LIST	= 	$(OBJ_DIR)/WLogger.$(0)	\
				$(OBJ_DIR)/Logger.$(0)

# Flags Compilers
CC 			=	gcc
CXX			=	g++
INCLUDES	=	-I$(INC_DIR) -I$(INC_DIR)/Logger
FLAGS		=	-O0 -Wall -Wextra -g -fPIC
LIBNAME 	=	-Wl,-soname,libelus.so.1.0
LIBSO 		=	./lib/libelus.so.1.0
LIB			=	./lib

# Export LD_LIBRARY_PATH variable
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib

# Rules of construction of shared librarie
install: $(OBJ_LIST)
	$(CXX) $(FLAGS) $(LIBNAME) -o $(LIBSO) $(OBJ_LIST) -shared

# Rules of construction of objects
$(OBJ_DIR)/%.$(0): $(SRC_DIR)/%.c
	$(CC) $(FLAGS)  $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.$(0): $(SRC_DIR)/Logger/%.cpp
	$(CXX) $(FLAGS)  $(INCLUDES) -c $< -o $@

# Rules to compile testing files
cmain: 
	$(CC) $(FLAGS) $(TEST)/main.c  $(INCLUDES) -o main -L$(LIB) -lelus

cxmain: 
	$(CXX) $(FLAGS) $(TEST)/main.cpp $(INCLUDES) -o main -L$(LIB) -lelus

# Rule to clean all generated objects and library
clean:
	rm -rf obj/*.o lib/libelus.*

# Create symbolic links for libelus.so.1.0
.PHONY: links
links:
	ln -sf ${LSRC}/lib/libelus.so.1.0 ${LSRC}/lib/libelus.so.1
	ln -sf ${LSRC}/lib/libelus.so.1 ${LSRC}/lib/libelus.so