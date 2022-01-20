/**
* @file 004-ProductOf3Integers.cpp
* @brief 004 - Product of 3 Integers
* @author Keitaro Naruse
* @date 2022-01-19
* @copyright MIT License
* @details https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_d
*/

#include <iostream>
#include <vector>

const bool Debug = false; 

int main()
{
    //  Constant
    const int N = 3;
    //  Read Ai = [ 1, 100 ]
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << A.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Main
    //  10^2 * 10^2 * 10^2 = 10^6
    int product = 1;
    for( int i = 0; i < N; i ++ ) {
        product *= A.at( i );
    }
    //  Display the result
    std::cout << product << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
