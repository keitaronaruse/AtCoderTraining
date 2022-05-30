/**
 * @file abc253-a.cpp
 * @brief ABC253 Problem A - Median?
 * @author Keitaro Naruse
 * @date 2022-05-28
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc253/tasks/abc253_a
 */

// # Solution

#include <iostream>

int main( ) {
    //  Read a, b, c = [ 1, 100 ]
    int a, b, c;
    std::cin >> a >> b >> c;

    //  Main
    if( ( a <= b && b <= c ) || ( a >= b && b >= c ) ) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return ( 0 );
}
