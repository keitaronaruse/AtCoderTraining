/**
* @file 002-SumOf3Integers.cpp
* @brief 002 - Sum of 3 Integers
* @author Keitaro Naruse
* @date 2022-01-19
* @copyright MIT License
* @details https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_b
*/

#include <iostream>

const bool Debug = false; 

int main()
{
    //  Read A1, A2, A3 = [ 1, 100 ]
    int A1 = 0, A2 = 0, A3 = 0; 
    std::cin >> A1 >> A2 >> A3;
    if( Debug ) {
        std::cerr << A1 << " " << A2 << " " << A3 << std::endl;
    }

    //  Display the result
    std::cout << A1 + A2 + A3 << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
