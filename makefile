# Sudoku Solver Makefile
# Written by Aric Landy on 12/23/2018

# Name of executaable
EXECUTABLE = solve
TESTEX = test

# Name of the compiler
CXX = g++

# Compile arguments
CFLAGS = -Wall -Werror -Wextra -pedantic -O3


make solve:
	$(CXX) main.cpp Solver.cpp $(CFLAGS) -o $(EXECUTABLE)

make test:
	$(CXX) sudoku_tests.cpp $(CFLAGS) -o $(TESTEX) 


clean:
	rm -f $(binaries) $(objects) *.o $(EXECUTABLE) $(TESTEX)

.PHONY: solve clean test
