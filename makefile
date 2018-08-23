# John McBride - Final Space - CS 162 project 10
# Dec 6th 2017

# Compiler
CXX = g++

# Compile Flags
CXXFLAGS = -Wall
CXXFLAGS += -std=c++0x
CXXFLAGS += -pedantic-errors

# Valgrind flag
VGFLAGS = --tool=memcheck --leak-check=full

# Basic Source files
SRCS = main.cpp block.cpp chain.cpp sha256.cpp

# Basic object files
OBJS = main.o block.o chain.o sha256.o

# Basic headers
HEADERS = block.hpp chain.hpp sha256.hpp

# Name of the executable file
PROJECT_NAME = cpp_bc

# Rules for making the executable from the objects and headers
${PROJECT_NAME}: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${PROJECT_NAME}

# Rules for making the object files
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

# Rules for creating the zip
.PHONY: zip
zip: 
	zip ${ZIP_NAME}.zip ${SRCS} ${HEADERS} makefile ${TXT} ${PDF}

# Rules for running valgrind and checking mem leaks
.PHONY: valgrind 
valgrind:
	valgrind ${VGFLAGS} ${PROJECT_NAME}

# Rule for cleaning up the object files
.PHONY: clean 
clean: 
	rm *.o ${PROJECT_NAME}