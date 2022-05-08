/**
 * @file abc250-b.cpp
 * @brief ABC250 Problem B - Enlarged Checker Board
 * @author Keitaro Naruse
 * @date 2022-05-08
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc250/tasks/abc250_b
 */

// # Solution

#include <iostream>
#include <string>

int main( ) {
    //  Read N, A, B = [ 1, 10 ]
    int N, A, B;
    std::cin >> N >> A >> B;

    //  Main
    //  Preprocess
    std::string white( B, '.' ), black( B, '#' ), first, second;
    for( int h = 0; h < N; h++ ) {
        if( h % 2 == 0 ) {
            first = white;
            second = black;
        } else {
            first = black;
            second = white;
        }
        for( int k = 0; k < A; k++ ) {
            for( int w = 0; w < N; w++ ) {
                if( w % 2 == 0 ) {
                    std::cout << first;
                } else {
                    std::cout << second;
                }
            }
            std::cout << std::endl;
        }
    }

    //  Finalize
    return ( 0 );
}
