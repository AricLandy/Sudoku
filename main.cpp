//  main.cpp
//  Sudoku
//
//  Created by Aric Landy on 12/21/18.
//  Copyright © 2018 Aric Landy. All rights reserved.



#include <string>
#include <iostream>
#include <fstream>
#include "Solver.hpp"


// main.cpp just runs test 1 as an example
int main() {
    
    std::ifstream is;
    is.open("/Users/alandy/Documents/Sudoku1/Sudoku/test-1-input.txt");
    
    Solver tester(9, is);
    tester.solve_puzzle(std::cout);
    
    is.close();

    return 0;
}


