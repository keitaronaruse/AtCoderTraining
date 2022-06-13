/**
 * @file abc255-b.cpp
 * @brief ABC255 Problem B - Light It Up
 * @author Keitaro Naruse
 * @date 2022-06-11
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc255/tasks/abc255_b
 */

// # Solution

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

int main( ) {
    //  Read N = [ K, 10^3 ], K = [ 1, N ]
    int N, K;
    std::cin >> N >> K;
    //  Read Ai = [ 1, N ]
    std::vector< int > A( K );
    for( int i = 0; i < K; i++ ) {
        std::cin >> A.at( i );
    }
    //  Read Xi, Yi = [ -10^5, 10^5 ]
    std::vector< int > X( N ), Y( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> X.at( i ) >> Y.at( i );
    }

    //  Main
    //  Preprocess
    std::vector< double > D( N, 1E9 );
    //  Calclate the distance between people
    for( int k = 0; k < K; k++ ) {
        for( int i = 0; i < N; i++ ) {
            double dist = std::sqrt(
                std::pow( ( double ) ( X.at( A.at( k ) - 1 ) - X.at( i ) ),
                          2.0 ) +
                std::pow( ( double ) ( Y.at( A.at( k ) - 1 ) - Y.at( i ) ),
                          2.0 ) );
            if( dist < D.at( i ) ) {
                D.at( i ) = dist;
            }
        }
    }
    //  Find the max distance
    double max_dist = 0.0;
    for( int i = 0; i < N; i++ ) {
        if( max_dist < D.at( i ) ) {
            max_dist = D.at( i );
        }
    }
    std::cout << std::fixed << std::setprecision( 18 ) << max_dist << std::endl;

    //  Finalize
    return ( 0 );
}
