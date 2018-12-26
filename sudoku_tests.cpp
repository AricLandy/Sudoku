// Created by Aric Landy

#include <iostream>
#include "Solver.hpp"
#include <fstream>
#include <string>


using namespace std;


bool check_diff(fstream & correct, fstream & output){
    char int1, int2;
    while (correct >> int1 && output >> int2){
        if (int1 != int2){
            return false;
        }
    }
    return true;
}


bool test_1(){
    
    ifstream is;
    is.open("/Users/alandy/Documents/Sudoku1/Sudoku/Test_Files/test-1-input.txt");
    
    fstream output;
    output.open("/Users/alandy/Documents/Sudoku1/Sudoku/Test_Files/output.txt");
    
    
    Solver tester(9, is);
    tester.solve_puzzle(output);
    
    output.close();
    output.open("/Users/alandy/Documents/Sudoku1/Sudoku/output.txt");

    fstream correct;
    correct.open("/Users/alandy/Documents/Sudoku1/Sudoku/Test_Files/test-1-correct.txt");

    bool val = check_diff(correct, output);

    correct.close();
    output.close();
    is.close();

    if (val){
        std::cout << "Test 1: PASSED\n";
    }
    else{
        std::cout << "Test 1: FAILED\n";
    }
    return val;
    
}



bool test_2(){
    
    ifstream is;
    is.open("/Users/alandy/Documents/Sudoku1/Sudoku/Test_Files/test-2-input.txt");
    
    fstream output;
    output.open("/Users/alandy/Documents/Sudoku1/Sudoku/Test_Files/output.txt");
    
    
    Solver tester(9, is);
    tester.solve_puzzle(output);
    
    output.close();
    output.open("/Users/alandy/Documents/Sudoku1/Sudoku/Test_Files/output.txt");
    
    fstream correct;
    correct.open("/Users/alandy/Documents/Sudoku1/Sudoku/Test_Files/test-2-correct.txt");
    
    bool val = check_diff(correct, output);
    
    correct.close();
    output.close();
    is.close();
    
    if (val){
        std::cout << "Test 2: PASSED\n";
    }
    else{
        std::cout << "Test 2: FAILED\n";
    }
    
    return val;
    
}




int main(){

    std::ios_base::sync_with_stdio(false);
    
    if (test_1() && test_2()){
		std::cout << "All Tests passed\n";
	}
    
	return 0;
}
