/**
* @file 011-PrintPrimeNumbers.cpp
* @brief 011 - Print Prime Numbers
* @author Keitaro Naruse
* @date 2022-01-21
* @copyright MIT License
* @details https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_k
*/

#include <iostream>
#include <vector>

const bool Debug = false; 

int main()
{
    //  Read N = [ 2, 3000 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Main
    std::vector< bool > eratosthenes( N + 1, true );
    eratosthenes.at( 0 ) = false;
    eratosthenes.at( 1 ) = false;
    for( int i = 2; i * i <= N; i ++ ) {
        if( eratosthenes.at( i ) ) {
            for( int k = i + i; k <= N; k += i ) {
                eratosthenes.at( k ) = false;
            }
        }
    }
    //  Display the result
    for( int i = 2; i <=N; i ++ ) {
        if( eratosthenes.at( i ) ) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
