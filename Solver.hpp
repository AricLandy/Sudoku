//  Solver.hpp
//  Sudoku
//
//  Created by Aric Landy on 12/21/18.
//  Copyright © 2018 Aric Landy. All rights reserved.


#ifndef Solver_hpp
#define Solver_hpp


//#include <stdio.h>
#include <vector>
#include <iostream>




// element struct
// each item in the sudoku is represented by an element
struct element{
public:
    // element defualt ctor
    element();
    
    // element custom ctor
    element(int num_in);
    
    // Holds the number of item in the puzzle
    int num;
    
    // if the element is in the original puzzle,
    //orig is true and therefore cannor be changed by the puzzle
    bool orig;
};




// Solver class
// this actually solves the puzzle
class Solver{
    
public:
    
    // Solver class ctor, initializes to the parameter vector
    Solver(std::vector<std::vector<int> > puzzle_in, int dim);
    
    // Prints the puzzle to the output
    void print_puzzle();
    
    // Prints the old puzzle, solves it, prints the solution
    int solve_puzzle();
    
    

    
    // Iterator class
    // this is used for moving thoughout the puzzle
    class Iterator{
    
    public:
        
        // Iterator ctor
        Iterator(Solver & parent_in);

        // Iterator increment operator
        Iterator & operator++();
        
        // Iterator decrement operator
        Iterator & operator--();
        
        // Return the element from the parent 2D vector
        element operator*();
        
        // Returns the num from the current element
        int datum();
        
        // Returns if the current element is an original element
        bool orig();
        
        // Returns true of the iterator is at the end of the puzzle
        bool end();
        
        // Sets the number of the current location in the puzzle to the given argument
        void set_num(int num_in);
        
    
        // Holds the parent (Solver class object)
        Solver& parent;
        
        // The current locaiton of the iterator in the puzzle
        std::pair<int, int> location;
        
        // The dimension of the puzzle
        int dim;
    
    };
    
    
    
private:
    
    // vector of vectors of elements that represents the puzzle
    std::vector<std::vector<element> > puzzle;
    
    // Keeps track of the first changeable element
    std::pair<int, int> first;
    
    // Holds the dimension of the puzzle
    int dimension;
    

    
    // recursive function that generates possible permutations for the puzzle
    int gen_perms(Iterator & it);
    
    
    // Promising check to make sure the puzzle is valid by
    // calling the next three functions
    bool promising(Iterator & it);
    
    // These three functions check various aspects of the puzzle
    bool check_row(Iterator & it);
    bool check_col(Iterator & it);
    bool check_box(Iterator & it);
    


};



#endif /* Solver_hpp */
