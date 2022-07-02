/**
 * @file abc258-d.cpp
 * @brief ABC258 Problem D - Trophy
 * @author Keitaro Naruse
 * @date 2022-07-02
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc258/tasks/abc258_d
 */

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

int main( ) {
    //  Read N = [ 1, 2*10^5 ], X = [ 1, 10^9 ]
    int N;
    long long X;
    std::cin >> N >> X;

    //  Read Ai, Bi = [ 1, 10^9 ]
    std::vector< long long > A( N ), B( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i ) >> B.at( i );
    }

    //  Main
    long long C = A.at( 0 ) + B.at( 0 );
    long long answer = C + B.at( 0 ) * ( X - 1L );
    for( int i = 1; i < N; i++ ) {
        C += A.at( i ) + B.at( i );
        if( X >= ( long long ) ( i + 1 ) ) {
            answer = std::min(
                answer, C + B.at( i ) * ( X - ( long long ) ( i + 1 ) ) );
        }
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
