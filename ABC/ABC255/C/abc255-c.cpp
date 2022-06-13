/**
 * @file abc255-c.cpp
 * @brief ABC255 Problem C - ±1 Operation 1
 * @author Keitaro Naruse
 * @date 2022-06-11, 2022-06-13
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc255/tasks/abc255_c
 */

// # Solution

#include <iostream>
#include <algorithm>

int main( ) {
    //  Read X, A = [ -10^18, 10^18 ], D = [ -10^6, 10^6 ], N = [ 1, 10^12 ]
    long long X, A, D, N;
    std::cin >> X >> A >> D >> N;

    //  Main
    long long min = 0L, max = 0L;
    long long answer = 0L;
    if( D == 0L ) {
        min = A;
        max = A;
    } else if( D > 0L ) {
        min = A;
        max = A + ( N - 1L ) * D;
    } else if( D < 0L ) {
        min = A + ( N - 1L ) * D;
        max = A;
    }

    if( X <= min ) {
        answer = min - X;
    } else if( max <= X ) {
        answer = X - max;
    } else {
        long long k = ( X - A ) / D;
        long long upper, lower;
        if( D > 0L ) {
            upper = A + ( k + 1 ) * D;
            lower = A + k * D;
        } else if( D < 0L ) {
            upper = A + k * D;
            lower = A + ( k + 1L ) * D;
        }
        answer = std::min( upper - X, X - lower );
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
