/**
 * @file abc254-a.cpp
 * @brief ABC254 Problem abc254-e.cpp
 * @author Keitaro Naruse
 * @date 2022-06-04
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc254/tasks/abc254_a
 */

// # Solution

#include <iostream>
#include <iomanip>

int main( ) {
    //  Read N = [ 100, 999 ]
    int N;
    std::cin >> N;

    //  Main
    std::cout << std::setw( 2 ) << std::setfill( '0' ) << N % 100 << std::endl;

    //  Finalize
    return ( 0 );
}
