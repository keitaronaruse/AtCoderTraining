/**
 * @file abc261-a.cpp
 * @brief ABC261 Problem B - Tournament Result
 * @author Keitaro Naruse
 * @date 2022-07-23
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc261/tasks/abc261_b
 */

// # Solution

#include <iostream>
#include <vector>

int main( ) {
    //  Read N = [ 2, 10^3 ]
    int N;
    std::cin >> N;

    //  Read Aij = [ -, W, L, D ]
    std::vector< std::vector< char > > A( N, std::vector< char >( N ) );
    for( int i = 0; i < N; i++ ) {
        for( int j = 0; j < N; j++ ) {
            std::cin >> A.at( i ).at( j );
        }
    }

    //  Main
    bool isCorrect = true;
    for( int i = 0; i < N; i++ ) {
        for( int j = i; j < N; j++ ) {
            if( i == j ) {
                if( A.at( i ).at( i ) != '-' ) {
                    isCorrect = false;
                    break;
                }
            } else {
                if( A.at( i ).at( j ) == 'W' ) {
                    if( A.at( j ).at( i ) != 'L' ) {
                        isCorrect = false;
                        break;
                    }
                } else if( A.at( i ).at( j ) == 'L' ) {
                    if( A.at( j ).at( i ) != 'W' ) {
                        isCorrect = false;
                        break;
                    }
                } else if( A.at( i ).at( j ) == 'D' ) {
                    if( A.at( j ).at( i ) != 'D' ) {
                        isCorrect = false;
                        break;
                    }
                } else {
                    isCorrect = false;
                    break;
                }
            }
        }
    }
    if( isCorrect ) {
        std::cout << "correct" << std::endl;
    } else {
        std::cout << "incorrect " << std::endl;
    }

    //  Finalize
    return ( 0 );
}
