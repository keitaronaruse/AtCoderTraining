/**
 * @file abc251-b.cpp
 * @brief ABC251 Problem B - At Most 3 (Judge ver.)
 * @author Keitaro Naruse
 * @date 2022-05-14
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc251/tasks/abc251_b
 */

// # Solution

#include <iostream>
#include <vector>

int main( ) {
    //  Read N = [ 1, 300 ], W = [ 1, 10^6 ]
    int N, W;
    std::cin >> N >> W;

    //  Read Ai = [ 1, 10^6 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    std::vector< bool > good( W + 1, false );
    int answer = 0;
    //  A single item
    for( int i = 0; i < N; i++ ) {
        int w = A.at( i );
        if( w <= W ) {
            if( !good.at( w ) ) {
                answer++;
                good.at( w ) = true;
            }
        }
    }
    //  Two items
    for( int i = 0; i < N; i++ ) {
        for( int j = i + 1; j < N; j++ ) {
            int w = A.at( i ) + A.at( j );
            if( w <= W ) {
                if( !good.at( w ) ) {
                    answer++;
                    good.at( w ) = true;
                }
            }
        }
    }
    //  Three items
    for( int i = 0; i < N; i++ ) {
        for( int j = i + 1; j < N; j++ ) {
            for( int k = j + 1; k < N; k++ ) {
                int w = A.at( i ) + A.at( j ) + A.at( k );
                if( w <= W ) {
                    if( !good.at( w ) ) {
                        answer++;
                        good.at( w ) = true;
                    }
                }
            }
        }
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
