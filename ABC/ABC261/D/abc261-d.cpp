/**
 * @file abc261-d.cpp
 * @brief ABC261 Problem D - Flipping and Bonus
 * @author Keitaro Naruse
 * @date 2022-07-23
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc261/tasks/abc261_d
 */

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) {
    for( const auto& k : v ) {
        os << k << " ";
    }
    return ( os );
}

int main( ) {
    //  Read N, M = [ 1, 5*10^3 ]
    int N, M;
    std::cin >> N >> M;
    //  Read Xi = [ 1, 10^9 ]
    std::vector< int > X( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> X.at( i );
    }
    //  Read Ci = [ 1, N ], Yi = [ 1, 10^9 ]
    std::vector< int > C( M ), Y( M );
    for( int j = 0; j < M; j++ ) {
        std::cin >> C.at( j ) >> Y.at( j );
    }

    //  Main
    //  Preprocess
    std::vector< long long > D( N, 0L );
    for( int j = 0; j < M; j++ ) {
        D.at( C.at( j ) - 1 ) = Y.at( j );
    }

    std::vector< std::vector< long long > > E(
        N, std::vector< long long >( N, 0L ) );
    long long max_E = 0L;

    E.at( 0 ).at( 0 ) = X.at( 0 ) + D.at( 0 );
    for( int i = 1; i < N; i++ ) {
        E.at( 0 ).at( i ) = E.at( 0 ).at( i - 1 ) + X.at( i ) + D.at( i );
    }
    std::cout << E.at( 0 ) << std::endl;
    max_E = std::max( max_E, E.at( 0 ).at( N - 1 ) );

    for( int k = 1; k < N; k++ ) {
        E.at( k ).at( 0 ) = X.at( 0 ) + D.at( 0 );
        int c = 1;
        for( int i = 1; i < N; i++ ) {
            if( i == k ) {
                E.at( k ).at( i ) = E.at( k ).at( i - 1 );
                c = 0;
            } else {
                E.at( k ).at( i ) =
                    E.at( k ).at( i - 1 ) + X.at( i ) + D.at( c );
                c++;
            }
        }
        std::cout << E.at( k ) << std::endl;
        max_E = std::max( max_E, E.at( k ).at( N - 1 ) );
    }
    std::cout << max_E << std::endl;

    //  Finalize
    return ( 0 );
}
