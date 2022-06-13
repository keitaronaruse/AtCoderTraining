/**
 * @file abc255-c.cpp
 * @brief ABC255 Problem C - ±1 Operation 1
 * @author Keitaro Naruse
 * @date 2022-06-11
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
    if( D > 0L ) {
        min = A;
        max = A + ( N - 1L ) * D;
        if( X <= min ) {
            answer = min - X;
        } else if( max <= X ) {
            answer = X - max;
        } else {
            long long r = ( X - A ) % D;
            answer = std::min( r, D - r );
        }
    } else if( D < 0L ) {
        max = A;
        min = A + ( N - 1L ) * D;
        if( X <= min ) {
            answer = min - X;
        } else if( max <= X ) {
            answer = X - max;
        } else {
            long long r = ( X - A ) % D;
            if( X - A < 0L ) {
                r = -( X - A ) % ( -D );
            } else if( X - A > 0L ) {
                r = -( X - A ) % ( -D );
            }
            answer = std::min( r, D - r );
        }
    } else if( D == 0L ) {
        if( X >= A ) {
            answer = X - A;
        } else {
            answer = A - X;
        }
    }
    std::cout << answer << std::endl;

    std::cout << "4 % 3 = " << ( ( 4 ) % ( 3 ) ) << std::endl;
    std::cout << "-4 % 3 = " << ( ( -4 ) % ( 3 ) ) << std::endl;
    std::cout << "4 % -3 = " << ( ( 4 ) % ( -3 ) ) << std::endl;
    std::cout << "-4 % -3 = " << ( ( -4 ) % ( -3 ) ) << std::endl;
    //  Finalize
    return ( 0 );
}
