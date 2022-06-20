/**
 * @file arc142-a.cpp
 * @brief ARC142 Problem A
 * @author Keitaro Naruse
 * @date 2022-06-19
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc142/tasks/arc142_a
 */

// # Solution

#include <iostream>
#include <string>
#include <algorithm>

long long f( long long x ) {
    std::string x_str = std::to_string( x );
    std::reverse( x_str.begin( ), x_str.end( ) );
    return ( std::stol( x_str ) );
}

int main( ) {
    //  Read N, K = [ 1, 10^12 ]
    long long N, K;
    std::cin >> N >> K;

    //  Main
    long long answer = 0L;
    //  No operation case
    if( K % 10L != 0 ) {
        long long k = 0L, start = 0L;
        //  K, itself
        if( K <= N ) {
            answer = 1L;
            start = K;
        }
        //  One operation
        long long x1 = f( K );
        if( x1 <= N ) {
            if( x1 != start ) {
                answer++;
            }
        }
        k = x1 * 10L;
        while( k <= N ) {
            if( k != start ) {
                answer++;
            }
            k *= 10L;
        }
        //  Two operations
        long long x2 = f( x1 );
        if( x1 != x2 ) {
            if( x2 <= N ) {
                if( x2 != start ) {
                    answer++;
                }
            }
            k = x2 * 10L;
            while( k <= N ) {
                if( k != start ) {
                    answer++;
                }
                k *= 10L;
            }
        }
    } else {
        if( K <= N ) {
            answer = 1L;
        }
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
