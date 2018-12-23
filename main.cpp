//  main.cpp
//  Sudoku
//
//  Created by Aric Landy on 12/21/18.
//  Copyright © 2018 Aric Landy. All rights reserved.

#include <iostream>
#include <vector>
#include "Solver.hpp"



int main() {
    
    std::vector<std::vector<int> > s;
    
    std::vector<int> r1 = {-1, 6, -1, 1, -1, 4, -1, 5, -1};
    std::vector<int> r2 = {-1, -1, 8, 3, -1, 5, 6, -1, -1};
    std::vector<int> r3 = {2, -1, -1, -1, -1, -1, -1, -1, 1};
    std::vector<int> r4 = {8, -1, -1, 4, -1, 7, -1, -1, 6};
    std::vector<int> r5 = {-1, -1, 6, -1, -1, -1, 3, -1, -1};
    std::vector<int> r6 = {7, -1, -1, 9, -1, 1, -1, -1, 4};
    std::vector<int> r7 = {5, -1, -1, -1, -1, -1, -1, -1, 2};
    std::vector<int> r8 = {-1, -1, 7, 2, -1, 6, 9, -1, -1};
    std::vector<int> r9 = {-1, 4, -1, 5, -1, 8, -1, 7, -1};
    s.push_back(r1);
    s.push_back(r2);
    s.push_back(r3);
    s.push_back(r4);
    s.push_back(r5);
    s.push_back(r6);
    s.push_back(r7);
    s.push_back(r8);
    s.push_back(r9);
    
    
    Solver solve(s, 9);
    solve.solve_puzzle();
    
    return 0;
}


