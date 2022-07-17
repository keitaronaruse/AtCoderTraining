/**
 * @file arc144-a.cpp
 * @brief ARC144 Problem A - Digit Sum of 2x
 * @author Keitaro Naruse
 * @date 2022-07-16
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc144/tasks/arc144_a
 */

// # Solution

#include <iostream>
#include <string>

int main( ) {
    //  Read N = [ 1, 10^5 ]
    int N;
    std::cin >> N;

    //  Main
    int num_digits = ( N - 1 ) / 4 + 1;
    std::string x( num_digits, '4' );
    x.at( 0 ) = '0' + ( N - 1 ) % 4 + 1;

    int M = 2 * N;
    std::cout << M << std::endl;
    std::cout << x << std::endl;

    //  Finalize
    return ( 0 );
}
