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
    
    std::ifstream p1_stream;
    p1_stream.open("/Users/alandy/Documents/Sudoku1/Sudoku/Test_Files/test-1-input.txt");
    
    Solver tester(9, p1_stream);
    tester.solve_puzzle(std::cout);
    
    p1_stream.close();

    return 0;
}


