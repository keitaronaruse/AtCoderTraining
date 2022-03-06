/**
* @file abc242-c.cpp
* @brief ABC242 Problem C - 1111gal password
* @author Keitaro Naruse
* @date 2022-03-05
* @copyright MIT License
* @details https://atcoder.jp/contests/abc242/tasks/abc242_c
*/

// # Solution
// - k = [ 1    ], C_{i+1}^k = C_i^k + C_i^{k+1}
// - k = [ 2, 8 ], C_{i+1}^k = C_i^{k-1} + C_i^k + C_i^{k+1}
// - k = [ 9    ], C_{i+1}^k = C_i^{k-1} + C_i^k

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = false;

int main()
{
    //  Constant
    const long long P = 998244353LL;

    //  Read N = [ 2, 10^6 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N <<  std::endl;
    }

    //  Main
    const int K = 9;
    std::vector< std::vector< long long > > comb( N, std::vector< long long >( K, 0LL ) ); 
    for( int k = 0; k < K; k ++ ) {
        comb.at( 0 ).at( k ) = 1LL;
    }
    for( int i = 1; i < N; i ++ ) {
        for( int k = 0; k < K; k ++ ) {
            if( k == 0 ) {
                comb.at( i ).at( k ) = comb.at( i - 1 ).at( k ) 
                    + comb.at( i - 1 ).at( k + 1 );
            }
            else if( k == 8 ) {
                comb.at( i ).at( k ) = comb.at( i - 1 ).at( k - 1 ) 
                    + comb.at( i - 1 ).at( k );
            }
            else {
                comb.at( i ).at( k ) = comb.at( i - 1 ).at( k - 1 ) 
                    + comb.at( i - 1 ).at( k ) 
                    + comb.at( i - 1 ).at( k + 1 ) ;
            }
            if( comb.at( i ).at( k ) > P ) {
                 comb.at( i ).at( k ) %= P;
            }
        }
    }
    long long num = 0LL;
    for( int k = 0; k < K; k ++ ) {
        num += comb.at( N - 1 ).at( k );
        if( num > P ) {
            num %= P;
        }
    }
    std::cout << num << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
