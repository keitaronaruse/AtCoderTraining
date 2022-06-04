/**
 * @file abc254-c.cpp
 * @brief ABC254 Problem C - K Swap
 * @author Keitaro Naruse
 * @date 2022-06-04
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc254/tasks/abc254_c
 */

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

int main( ) {
    //  Read N = [ 2, 2 * 10^5 ], K = [ 1, N - 1 ] 
    int N, K;
    std::cin >> N >> K;

    //  Read Ai = [ 1, 10^9 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    std::vector< int > B = A;
    std::sort( B.begin(), B.end() );

    bool isYes = true;
    std::vector< bool > is_alligned( N, false );
    for( int i = 0; i < N; i ++ ) {
        if( !is_alligned.at( i ) ) {
            if( A.at( i ) == B.at( i ) ) {
                is_alligned.at( i ) = true;
            }
            else {
                for( int j = i + K; j < N; j += K ) {
                    if( A.at( i ) == B.at( j ) && !is_alligned.at( j ) ) {
                        is_alligned.at( i ) = true;
                        is_alligned.at( j ) = true;
                        break;
                    }
                }
            }
            if( !is_alligned.at( i ) ) {
                isYes = false;
                break;
            }
        }
    }
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return ( 0 );
}
