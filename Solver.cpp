//  Solver.cpp
//  Sudoku
//
//  Created by Aric Landy on 12/21/18.
//  Copyright © 2018 Aric Landy. All rights reserved.



#include "Solver.hpp"



// Element ctors
element::element(int num_in) : num(num_in){ }

element::element() : num(-1), orig(false) { }


// Solver ctor
Solver::Solver(std::vector<std::vector<int> > puzzle_in, int dim)
    : dimension(dim) {
        
        puzzle.resize(dimension);
        bool found_first = false;
        
        // Loop through input values
        for (unsigned i = 0; i < (unsigned)dim; ++i){
            puzzle[i].resize(dim);
            for (unsigned j = 0; j < (unsigned)dim; ++j){
                
                // If found the first changeable element, update first
                if (!found_first && puzzle[i][j].num == -1){
                    found_first = true;
                    first.first = i;
                    first.second = j;
                }
                // If the value is not -1, it is an original element
                // original elements can not be modified by the program
                if (puzzle_in[i][j] != -1){
                    element temp(puzzle_in[i][j]);
                    temp.orig = true;
                    puzzle[i][j] = temp;
                }
            }
        }
    }



// Prints out the puzzle
void Solver::print_puzzle(){
    std::cout << " ------- ------- -------\n";
    
    for (unsigned row = 0; row < puzzle.size(); ++row){
        
        std::cout << "| ";
        
        for (unsigned element = 0; element < puzzle[row].size(); ++element){
            // if the value is -1, it is not an original element
            // therefore print out nothing (spaces for formatting)
            if (puzzle[row][element].num != -1){
                std::cout << puzzle[row][element].num << " ";
            }
            else { std::cout << "  "; }
            if (element % 3 == 2) { std::cout << "| "; }
        }
        
        std::cout << "\n";
        if (row % 3 == 2) { std::cout << " ------- ------- -------\n"; }

    }
}



// Checks the parameter element against all the other elements in the row
// returns false if there is another element of the same value found in the row
bool Solver::check_row(Iterator & it){
    if (it.datum() == -1) { return true; }
    std::pair<int, int> loc = it.location;
    // Loop through the current row
    for (unsigned el = 0; el < (unsigned)dimension; ++el){
        
        // If a different element in the row equals the current element
        if (el != (unsigned)loc.second && puzzle[loc.first][el].num == puzzle[loc.first][loc.second].num){
            return false;
        }
    }
    
    // if there is not an invalid element found, return true
    return true;
}



// Checks the parameter element against all the other elements in the column
// returns false if there is another element of the same value found in the column
bool Solver::check_col(Iterator & it){
    if (it.datum() == -1) { return true; }
    std::pair<int, int> loc = it.location;
    // Loop through the current row
    for (unsigned el = 0; el < (unsigned)dimension; ++el){
        
        // If a different element in the column equals the element in the current row
        if (el != (unsigned)loc.first && puzzle[el][loc.second].num == puzzle[loc.first][loc.second].num){
            return false;
        }
    }
    
    // if there is not an invalid element found, return true
    return true;
}



// Checks the parameter element against all the other elements in the row
// returns false if there is another element of the same value found in the row
bool Solver::check_box(Iterator & it){
    if (it.datum() == -1) { return true; }
    std::pair<int, int> loc = it.location;
    
    // Move to the top left corner of the box
    int row = (loc.first / 3) * 3;
    int col = (loc.second / 3) * 3;
    
    // Loop through all the elements in the box
    // and check to find a duplicate
    for (unsigned i = 0; i < 3; ++i){
        for (unsigned j = 0; j < 3; ++j){
            if (row+i != (unsigned)loc.first || col+j != (unsigned)loc.second){
                if (puzzle[row+i][col+j].num == puzzle[loc.first][loc.second].num){
                    return false;
                }
            }
        }
    }
    return true;
}



// Checks to see if the current puzzle is valid
// Checks the element at "it" against all elements in the same
// row, column, and box
bool Solver::promising(Iterator & it){
    return (check_row(it) && check_col(it) && check_box(it));
}





// gen_perms generates the possibilites for the sudoku
// this function drives the backtracking algorithm
// returns 1 if solved and -1 if not solvable
int Solver::gen_perms(Iterator & it){
    
    // if the end of the puzzle is reached
    if (it.end()){
        // and valid...
        if (promising(it)){
            // Puzzle has been solved, work is done
            return 1;
        }
    }

    // If not promising, go back
    if (!promising(it)){
        it.set_num(-1);
        return 0;
    }

    
    // Find the first promising number
    if (it.datum() != -1){
        ++it;
    }
    while (it.orig()){
        ++it;
    }
    // Loop through all the possibilities
    for (unsigned val = 1; val <= 9; ++val){
        it.set_num(val);
        
        // if puzzle is solved, move up recursive call to exit
        if (gen_perms(it) == 1){
            return 1;
        }
        
    }
    
    // If puzzle is not solvable
    // All possibilites tried for first changeable element
    if (it.location == first){
        return -1;
    }
    
    // Decrement back to the previous non original element
    it.set_num(-1);
    do{
        --it;
    } while (it.orig());
    
    return 0;
}





// Prints the old puzzle, solves it, prints the solution
// returns -1 if not solvable
int Solver::solve_puzzle(){
    
    // Print the original puzzle
    print_puzzle();
    
    // Create an iterator (defualt starts at (0, 0))
    Iterator it(*this);
    
    // Call gen_perms
    if (gen_perms(it) == -1){
        std::cout << "Puzzle not solvable\n";
        return -1;
    }
    
    // Print out the end result
    std::cout << "\n\n";
    print_puzzle();

    return 0;
}



Solver::Iterator::Iterator(Solver & parent_in): parent(parent_in){
    dim = parent.dimension;
    location.first = 0;
    location.second = 0;
}



Solver::Iterator & Solver::Iterator::operator++(){
    // Increment the column
    ++(location.second);
    
    // Check if the iterator should move to the next row
    if (location.second > dim - 1){
        // Move to the next row
        ++(location.first);
        // Move back to the start of the column
        location.second = 0;
    }
    
    // Return current iterator
    return *this;
}



Solver::Iterator & Solver::Iterator::operator--(){
    // Decrement the column
    --(location.second);
    
    // Check if the iterator should move back a row
    if (location.second < 0){
        // Move to the previous row
        --(location.first);
        // Move to the end of the column
        location.second = dim - 1;
    }
    
    // Return current iterator
    return *this;
}



element Solver::Iterator::operator*(){
    return parent.puzzle[location.first][location.second];
}



int  Solver::Iterator::datum(){
    return (**this).num;
}



bool  Solver::Iterator::orig(){
    return (**this).orig;
}



bool  Solver::Iterator::end(){
    return location.first == dim - 1 && location.second == dim - 1;
}



void  Solver::Iterator::set_num(int num_in){
    parent.puzzle[location.first][location.second].num = num_in;
}
