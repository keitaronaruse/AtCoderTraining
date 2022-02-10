/*
* @file 085-Multiplication085.cpp
* @brief 085 - Multiplication 085（★4）
* @author Keitaro Naruse
* @date 2022-02-08
* @copyright MIT License
* @details https://atcoder.jp/contests/typical90/tasks/typical90_cg
*/

// # Solution

#include <iostream>
#include <vector>

const bool Debug = true;

int main()
{
    //  Read K = [ 1,10^12 ]
    long long K = 0LL;
    std::cin >> K;
    if( Debug ) {
        std::cerr << K << std::endl;
    }

    //  Main
    std::vector< long long > primes;
    long k = K;
    for( long long i = 2LL; i * i <= k; i ++ ) {
        while( k % i == 0 ) {
            primes.push_back( i );
            k /= i; 
        }
    }
    //  Prime
    if( k == K ) {
        primes.push_back( k );
        ;}
    if( Debug ) {
        for( auto p : primes ) {
            std::cerr << p << " ";
        }
        std::cerr << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
