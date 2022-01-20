/**
* @file 006-Print2NPlus3.cpp
* @brief 006 - Print 2N+3
* @author Keitaro Naruse
* @date 2022-01-20
* @copyright MIT License
* @details https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_f
*/

#include <iostream>

const bool Debug = false; 

int main()
{
    //  Read N = [ 1, 100 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Main
    //  Display the result
    std::cout << 2 * N + 3 << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
