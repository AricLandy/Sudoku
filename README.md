# Sudoku Solver

[![Build Status](https://travis-ci.org/AricLandy/Sudoku.svg?branch=master)](https://travis-ci.org/AricLandy/Sudoku)


## How it works
This program is build around a backtracking algorithm. Moving throug the puzzle (see "Iterator Class"), each empty element is tested with all possibilites [1, 2, 3...9]. When one number is considered promising (see "Promising"), the program moves on to the next element. If all possibilities are exhausted and none are "promising", the program moves back to the previous element. When the program reaches a "promising" value at the last element, the puzzle is solved  

### Iterator class
The traversal of the puzzle is done with a custom iterator. The iterator starts at the top left of the puzzle and each increment operator moves it to the right. Incrementing it at the far right will move it to the start of the next row.


### Promising
An element is considered promising if it is valid in terms of the Sudoku puzzle rules. This means that there can not be any elements of the same value in the same row, column, or box
