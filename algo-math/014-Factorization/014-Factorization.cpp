/**
* @file 014-Factorization.cpp
* @brief 014 - Factorization
* @author Keitaro Naruse
* @date 2022-01-21
* @copyright MIT License
* @details https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_n
*/

#include <iostream>
#include <vector>

const bool Debug = false; 

int main()
{
    //  Read N = [ 2, 10^12 ]
    long long N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Main
    std::vector< long long > factors;
    for( long long i = 2LL; i * i <= N; i ++ ) {
        while( N % i == 0LL ) {
            factors.push_back( i );
            N /= i;
        }
    }
    if( N != 1LL ) {
        factors.push_back( N );
    }

    //  Display the result
    for( auto p : factors ) {
        std::cout << p << " ";
    }
    std::cout << std::endl;
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
