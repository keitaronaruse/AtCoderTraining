/**
 * @file arc142-a.cpp
 * @brief ARC142 Problem A
 * @author Keitaro Naruse
 * @date 2022-06-19, 2022-06-21
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc142/tasks/arc142_a
 */

// # Solution

#include <iostream>
#include <string>
#include <algorithm>

long long reverse( long long x ) {
    std::string x_str = std::to_string( x );
    std::reverse( x_str.begin( ), x_str.end( ) );
    return ( std::stol( x_str ) );
}

long long f( long long x0 ) {
}

int main( ) {
    //  Read N, K = [ 1, 10^12 ]
    long long N, K;
    std::cin >> N >> K;

    //  Main
    long long answer = 0L;
    long long x0 = K, x1 = reverse( x0 ), x2 = reverse( x1 );
    long long f = std::min( std::min( x0, x1 ), x2 ), k;

    //  No operation case
    if( K == f ) {
        if( K <= N ) {
            answer ++;
        }
        //  One operation
        if( x1 <= N ) {
            if( x1 != K ) {
                answer++;
            }
        }
        k = x1 * 10L;
        while( k <= N ) {
            if( k != K ) {
                answer++;
            }
            k *= 10L;
        }
        //  Two operations
        if( x1 != x2 ) {
            if( x2 <= N ) {
                if( x2 != K ) {
                    answer++;
                }
            }
            k = x2 * 10L;
            while( k <= N ) {
                if( k != K ) {
                    answer++;
                }
                k *= 10L;
            }
        }
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
