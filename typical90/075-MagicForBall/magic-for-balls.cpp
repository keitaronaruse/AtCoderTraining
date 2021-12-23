/*
    075 - Magic For Balls（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bw
        Author: Keitaro Naruse
        Date:   2021-12-23, 2021-12-23 
        MIT License
*/

// # Solution
// - Factorize x and find the number of factors m
// - Count the number of divions by 2 

#include <iostream>
#include <vector>

int main()
{
    //  Read N
    long long N = 0LL;
    std::cin >> N;

    //  Main
    std::vector< long long > factors;

    long long m = 2;
    for( long long m = 2LL; m * m <= N; m ++ ) {
        while( N % m == 0LL ) {
            factors.push_back( m );
            N /= m;
        }
    }
    if( N != 1) {
        factors.push_back( N );
    }
    //  Debug
    // for( auto p : factors ) {
    //     std::cerr << p << " ";
    // }
    // std::cerr << std::endl;

    //  Display result
    int count = 0;
    int n = factors.size() - 1;
    while( n != 0 ) {
        n /= 2;
        count ++;
    }
    std::cout << count << std::endl;

    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
