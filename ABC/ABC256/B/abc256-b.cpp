/**
 * @file abc256-b.cpp
 * @brief ABC256 Problem B - Batters
 * @author Keitaro Naruse
 * @date 2022-06-18
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc256/tasks/abc256_b
 */

// # Solution

#include <iostream>
#include <vector>

int main( ) {
    //  Read N = [ 1, 10^2 ]
    int N;
    std::cin >> N;

    //  Read Ai = [ 1, 4 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    const int K = 4;
    std::vector< bool > B( K , false );
    int P = 0;
    for( int i = 0; i < N; i ++ ) {
        B.at( 0 ) = true;
        for( int k = K - 1; k >= 0; k -- ) {
            if( B.at( k ) ) {
                if( k + A.at( i ) >= K ) {
                    P ++;
                }
                else {
                    B.at( k + A.at( i ) ) = true;
                }
                B.at( k ) = false;
            }
        }
    }
    std::cout << P << std::endl;

    //  Finalize
    return ( 0 );
}
