/**
 * @file abc255-a.cpp
 * @brief ABC255 Problem A - You should output ARC, though this is ABC.
 * @author Keitaro Naruse
 * @date 2022-06-11
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc255/tasks/abc255_a
 */

// # Solution

#include <iostream>
#include <vector>
int main( ) {
    //  Read N = [ 1, 2 ]
    int R, C;
    std::cin >> R >> C;
    //  Raed Ai,j = [ 0, 100 ]
    std::vector< std::vector< int > > A( 2, std::vector< int >( 2, 0 ) );
    for( int i = 0; i < 2; i++ ) {
        for( int j = 0; j < 2; j++ ) {
            std::cin >> A.at( i ).at( j );
        }
    }

    //  Main
    std::cout << A.at( R - 1 ).at( C - 1 ) << std::endl;

    //  Finalize
    return ( 0 );
}
