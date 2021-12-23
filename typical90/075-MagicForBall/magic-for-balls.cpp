/*
    075 - Magic For Balls（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bw
        Author: Keitaro Naruse
        Date:   2021-12-23, 2021-12-23 
        MIT License
*/

// # Solution

#include <iostream>
#include <cmath>
#include <vector>

// # Solution
// - Factorize x

int main()
{
    //  Read N
    long long N = 0LL;
    std::cin >> N;
    double n = ( double ) N;
    double m = std::sqrt( n );
    int M = ( int ) m;
    // std::cerr << M << std::endl;

    //  Main
    bool isPrime = true;
    std::vector< int > factors;
    while ( M > 1 ) {
        if( N % M == 0 ) {
            // std::cerr << "(" << N << "," << M << ")";
            factors.push_back( M );
            N /= M;
            isPrime = false;
        }
        else {
            M --;
        }
    }
    if( N != 1 ) {
        factors.push_back( N );
    }

    //  
    if( isPrime ) {
        std::cerr << N << " is prime" << std::endl;
    }
    else {
        for( auto p : factors ) {
            std::cerr << p << std::endl;
        }
    }

    //  Display result
    // std::cout << std::endl;

    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
