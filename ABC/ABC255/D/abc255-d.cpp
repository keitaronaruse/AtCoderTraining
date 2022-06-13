/**
 * @file abc255-d.cpp
 * @brief ABC255 Problem D
 * @author Keitaro Naruse
 * @date 2022-06-11, 2022-06-13
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc255/tasks/abc255_d
 */

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

int main( ) {
    //  Read N, Q = [ 1, 2*10^5 ]
    int N, Q;
    std::cin >> N >> Q;

    //  Read Ai = [ 0, 10^9 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i );
    }

    //  Read Xj = [ 0, 10^9 ]
    std::vector< long long > X( Q );
    for( int j = 0; j < Q; j++ ) {
        std::cin >> X.at( j );
    }

    //  Main
    //  Preprocess
    //  B is a sorted A
    std::vector< int > B = A;
    std::sort( B.begin( ), B.end( ) );
    //  C is a cumulative sum of B
    std::vector< long long > C( N );
    C.at( 0 ) = B.at( 0 );
    for( int i = 1; i < N; i++ ) {
        C.at( i ) = C.at( i - 1 ) + B.at( i );
    }
    //  For each query
    for( int j = 0; j < Q; j++ ) {
        long long answer = 0L;
        long long b =
            std::lower_bound( B.begin( ), B.end( ), X.at( j ) ) - B.begin( );
        long long e =
            std::upper_bound( B.begin( ), B.end( ), X.at( j ) ) - B.begin( );
        if( b != 0L ) {
            answer =
                ( b * X.at( j ) - C.at( b - 1 ) ) +
                ( ( C.at( N - 1 ) - C.at( e - 1 ) - ( N - e ) * X.at( j ) ) );
        } else {
            answer = C.at( N - 1 ) - ( long long ) N * X.at( j );
        }
        std::cout << answer << std::endl;
    }

    //  Finalize
    return ( 0 );
}
