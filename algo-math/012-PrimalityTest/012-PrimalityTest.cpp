/**
* @file 012-PrimalityTest.cpp
* @brief 012 - Primality Test
* @author Keitaro Naruse
* @date 2022-01-21
* @copyright MIT License
* @details https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_l
*/

#include <iostream>
#include <vector>

const bool Debug = false; 

int main()
{
    //  Read N = [ 2, 10^13 ]
    long long N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Main
    bool isPrime = true;
    for( long long i = 2LL; i * i <= N; i ++ ) {
        if( N % i == 0LL ) {
            isPrime = false;
            break;
        }
    }
    //  Display the result
    if( isPrime ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
