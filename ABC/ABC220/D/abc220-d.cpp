/**
* @file abc220-d.cpp
* @brief ABC220 Problem D - FG operation
* @author Keitaro Naruse
* @date 2022-04-07
* @copyright MIT License
* @details https://atcoder.jp/contests/abc220/tasks/abc220_d
*/

// # Solution

#include <iostream>
#include <vector>

int main()
{
    //  Read N = [ 2, 10^5 ]
    int N;
    std::cin >> N;
    //  Read Ai = [ 0, 9 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    
    //  Main
    const int P = 998244353;
    const int K = 10;
    std::vector< std::vector< int > > dp( N, std::vector<int>( K, 0 ) );
    dp.at( 0 ).at( A.at( 0 ) ) = 1;
    for( int i = 1; i < N; i ++ ) {
        for( int k = 0; k < K; k ++ ) {
            //  F operation
            int f_index = ( k + A.at( i ) ) % K;
            dp.at( i ).at( f_index ) += dp.at( i - 1 ).at( k );
            dp.at( i ).at( f_index ) %= P;
            //  G operation
            int g_index = ( k * A.at( i ) ) % K;
            dp.at( i ).at( g_index ) += dp.at( i - 1 ).at( k );
            dp.at( i ).at( g_index ) %= P;
        }
    }
    for( int k = 0; k < K; k ++ ) {
        std::cout << dp.at( N - 1 ).at( k ) << std::endl;
    }

    //  Finalize
    return( 0 );
}
