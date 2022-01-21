/**
* @file 013-DivisorEnumeration.cpp
* @brief 013 - Divisor Enumeration
* @author Keitaro Naruse
* @date 2022-01-21
* @copyright MIT License
* @details https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_m
*/

#include <iostream>
#include <set>

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
    std::set< long long > divisors;
    for( long long i = 1LL; i * i <= N; i ++ ) {
        if( N % i == 0LL ) {
            divisors.insert( i );
            divisors.insert( N / i );
        }
    }
    //  Display the result
    for( auto d : divisors ) {
        std::cout << d << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
