# Sudoku Solver Makfile
# Written by Aric Landy on 12/23/2018

# Name of executaable
EXECUTABLE = solve

# Name of the compiler
CXX = g++

# Compile arguments
CFLAGS = -Wall -Werror -Wextra -pedantic -O3


make solve:
	$(CXX) main.cpp Solver.cpp $(CFLAGS) -o $(EXECUTABLE)

clean:
	rm -f $(binaries) $(objects) *.o $(EXECUTABLE)
#	rm -Rf *.dSYM

.PHONY: solve clean
