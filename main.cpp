//  main.cpp
//  Sudoku
//
//  Created by Aric Landy on 12/21/18.
//  Copyright © 2018 Aric Landy. All rights reserved.



#include <string>
#include <iostream>
#include "Solver.hpp"



int main() {
    
    
    std::ios_base::sync_with_stdio(false);
    
//    // Input redirection
//    #ifdef __APPLE__
//    if(!freopen("/Users/alandy/Documents/Sudoku1/Sudoku/test-1.txt"
//                , "r", stdin)){
//        std::cerr << "freopen() failed, file not found" << std::endl;
//        exit(1);
//    }
//    #endif
    
    
    std::vector<std::vector<int> > puzzle;
    
    for (unsigned i = 0; i < 9; ++i){
        std::vector<int> temp;
        temp.reserve(9);
        for (unsigned j = 0; j < 9; ++j){
            //std::string temp_string;
            //std::cin >> temp_string;
            int temp_int;
            //temp_int = stoi(temp_string);
            std::cin >> temp_int;
            temp.push_back(temp_int);
        }
        puzzle.push_back(temp);
    }
    
    
    Solver solve(puzzle, 9);
    solve.solve_puzzle();
    
    return 0;
}


