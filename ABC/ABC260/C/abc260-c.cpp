/**
 * @file abc260-c.cpp
 * @brief ABC260 Problem C - Changing Jewels
 * @author Keitaro Naruse
 * @date 2022-07-17
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc260/tasks/abc260_c
 */

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

int main( ) {
    //  Read N = [ 1, 10 ], X, Y = [ 1, 5 ]
    int N, X, Y;
    std::cin >> N >> X >> Y;

    //  Main
    //  Preprocess
    std::vector< long long > Red( N, 0L ), Blue( N, 0L );
    int n = N - 1;
    Red.at( n ) = 1L;
    while( n >= 1 ) {
        Blue.at( n ) += Red.at( n ) * X;
        Red.at( n - 1 ) += Red.at( n );
        Red.at( n - 1 ) += Blue.at( n );
        Blue.at( n - 1 ) += Blue.at( n ) * Y; 
        n--;
    }
    std::cout << Blue.at( 0 ) << std::endl;

    //  Finalize
    return ( 0 );
}
