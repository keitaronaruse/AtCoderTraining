/**
 * @file abc257-b.cpp
 * @brief ABC257 Problem B - 1D Pawn
 * @author Keitaro Naruse
 * @date 2022-06-25
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc257/tasks/abc257_b
 */

// # Solution

#include <iostream>
#include <vector>
int main( ) {
    //  Read N, K = [ 1, 200 ], Q = [ 1, 10^3 ]
    int N, K, Q;
    std::cin >> N >> K >> Q;
    //  Read Ai = [ 1, N ]
    std::vector< int > A( K + 1 );
    for( int i = 1; i <= K; i++ ) {
        std::cin >> A.at( i );
    }
    //  Read Li = [ 1, K ]
    std::vector< int > L( Q );
    for( int j = 0; j < Q; j++ ) {
        std::cin >> L.at( j );
    }

    //  Main
    //  Preprocess
    std::vector< int > B( N + 1, 0 );
    for( int i = 1; i <= K; i++ ) {
        B.at( A.at( i ) ) = i;
    }

    std::vector< int > P( K + 1, 0 );
    int k = 1;
    for( int i = 1; i <= N; i++ ) {
        if( B.at( i ) != 0 ) {
            P.at( k ) = i;
            k++;
        }
    }
    //  Solution
    for( int j = 0; j < Q; j ++ ) {
        int p = P.at( L.at( j ) );
        if( p < N && B.at( p + 1 ) == 0 ) {
            B.at( p + 1 ) = B.at( p );
            B.at( p ) = 0;
            P.at( L.at( j ) ) = p + 1;
        }
    }

    for( int i = 1; i <= K; i++ ) {
        std::cout << P.at( i ) << " ";
    }
    std::cout << std::endl;

    //  Finalize
    return ( 0 );
}
