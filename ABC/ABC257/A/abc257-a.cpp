/**
 * @file abc257-a.cpp
 * @brief ABC257 Problem A - A to Z String 2
 * @author Keitaro Naruse
 * @date 2022-06-25
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc257/tasks/abc257_a
 */

// # Solution
#include <iostream>

int main( ) {
    //  Read N = [ 1, 10^2 ], X = [ 1,  N * 26 ]
    int N, X;
    std::cin >> N >> X;

    //  Main
    char answer = ( char ) ( ( X - 1 ) / N ) + 'A';
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
