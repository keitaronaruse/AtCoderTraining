/**
 * @file abc259-a.cpp
 * @brief ABC259 Problem A - Growth Record
 * @author Keitaro Naruse
 * @date 2022-07-09
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc259/tasks/abc259_a
 */

// # Solution

#include <iostream>

int main( ) {
    //  Read N = [ 1, 100 ]
    int N, M, X, T, D;
    std::cin >> N >> M >> X >> T >> D;

    //  Main
    int a = T - D * X;
    int answer = 0;
    if( M < X ) {
        answer = a + M * D;
    } else if( X <= M ) {
        answer = T;
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
