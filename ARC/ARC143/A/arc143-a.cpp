/**
 * @file arc143-a.cpp
 * @brief ARC143 Problem A
 * @author Keitaro Naruse
 * @date 2022-06-26, 2022-06-27
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc143/tasks/arc143_a
 */

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

int main( ) {
    //  Read N = [ 0, 10^18 ]
    long long A, B, C;
    std::cin >> A >> B >> C;

    //  Main
    long long answer = -1L;
    //  a <= b <= c
    std::vector< long long > abc = { A, B, C };
    std::sort( abc.begin( ), abc.end( ) );

    if( abc.at( 0 ) + abc.at( 1 ) >= abc.at( 2 ) ) {
        answer = abc.at( 2 );
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
