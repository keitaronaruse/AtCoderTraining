/**
 * @file abc252-b.cpp
 * @brief ABC252 Problem B - Takahashi's Failure
 * @author Keitaro Naruse
 * @date 2022-05-21
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc252/tasks/abc252_b
 */

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

int main( ) {
    //  Read N = [ 1, 100 ], K = [ 1, N ]
    int N, K;
    std::cin >> N >> K;

    //  Read Ai = [ 1, 100 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i );
    }

    //  Read Bj = [ 1, N ]
    std::vector< int > B( K );
    for( int j = 0; j < K; j++ ) {
        std::cin >> B.at( j );
    }

    //  Main
    int max_A = 0;
    for( int i = 0; i < N; i++ ) {
        max_A = std::max( max_A, A.at( i ) );
    }

    bool isYes = false;
    std::vector< int > C = B;
    std::sort( C.begin(), C.end() );
    for( int i = 0; i < N; i++ ) {
        if( A.at( i ) == max_A ) {
            if( std::binary_search( C.begin(), C.end(), i + 1 ) ) {
                isYes = true;
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
