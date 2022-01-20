/**
* @file 010-Factorial.cpp 
* @brief 010 - Factorial 
* @author Keitaro Naruse
* @date 2022-01-20
* @copyright MIT License
* @details https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_j
*/

#include <iostream>
#include <vector>

const bool Debug = false; 

int main()
{
    //  Read N = [ 1, 20 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Main
    long long factorial = 1LL;
    for( int i = 2; i <= N; i ++ ) {
        factorial *= ( long long ) i;
    }
    //  Display the result
    std::cout << factorial << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
