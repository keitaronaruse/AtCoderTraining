/**
 * @file abc256-a.cpp
 * @brief ABC256 Problem A - 2^N
 * @author Keitaro Naruse
 * @date 2022-06-18
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc256/tasks/abc256_a
 */

// # Solution

#include <iostream>

int main( ) {
    //  Read N = [ 0, 30 ]
    int N;
    std::cin >> N;

    //  Main
    int answer = 1;
    for( int i = 0; i < N; i ++ ) {
        answer *= 2;
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
