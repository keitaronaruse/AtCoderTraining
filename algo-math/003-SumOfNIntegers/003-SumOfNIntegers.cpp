/**
* @file 005-Modulo100.cpp 
* @brief 005 - Modulo 100 
* @author Keitaro Naruse
* @date 2022-01-19
* @copyright MIT License
* @details https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_c
*/

#include <iostream>
#include <vector>

const bool Debug = false; 

int main()
{
    //  Read N = [ 1, 100 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
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
    int sum = 0;
    for( int i = 0; i < N; i ++ ) {
        sum += A.at( i );
    }
    //  Display the result
    std::cout << sum << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
