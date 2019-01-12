# Sudoku Solver
[![Build Status](https://travis-ci.org/AricLandy/Sudoku-Solver.svg?branch=master)](https://travis-ci.org/AricLandy/Sudoku-Solver)
## How it works
This solver uses a backtracking algorithm. 
A custom iterator starts at the top left of the puzzle and moves down to the bottom right. When it is at each element, it tests all possible values (starting at 1 all the way to 9). When an element is considered promising (see "Promising"), the iterator stopt incrementing hte value and moves on to the next element. If all possibilities are exhausted and none are "promising", the program moves back to the previous element and starts incrementing it from where it previously left off. When the program reaches a "promising" value at the last element, the puzzle is solved  
### Promising
An element is considered promising if it is valid in terms of the Sudoku puzzle rules. This means that there can not be any elements of the same value in the same row, column, or box
## How to Run
1) Clone this repository
``` shell
git clone https://github.com/AricLandy/Sudoku-Solver.git
```
2) Build and run with the test-1-input.txt
``` shell
make solve
./solve
```
## Further Expansion Ideas
1) This puzzle only works for a standard 9x9 puzzle but since most of the code is wrtten generically, a few minor modifications could allow it to work for Sudoku puzzles of any size
2) The main way to run this program is to create a textfile and then edit main.cpp to take in that specific text file. Adding a graphical way to input data would be very helpfull (coming soon)
