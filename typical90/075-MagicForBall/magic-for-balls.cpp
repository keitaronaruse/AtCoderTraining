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
    std::cerr << M << std::endl;

    //  Main
    std::vector< int > factors;
    while ( M > 1  ) {
        if( N % M == 0 ) {
            std::cerr << "(" << N << "," << M << ")";
            factors.push_back( M );
            N /= M;
        }
        else {
            M --;
        }
    }
    std::cerr << std::endl;
    // while() {
    //     ;
    // }

    //  Display result
    // std::cout << std::endl;

    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
