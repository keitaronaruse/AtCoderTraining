/**
* @file abc226-a.cpp
* @brief ABC226 Problem A - Round decimals
* @author Keitaro Naruse
* @date 2022-04-04
* @copyright MIT License
* @details https://atcoder.jp/contests/abc226/tasks/abc226_a
*/

// # Solution

#include <iostream>
#include <cmath>

int main()
{
    //  Read X = [ 0, 100 ]
    double X;
    std::cin >> X;

    //  Main
    double x = X + 0.5;
    x = std::floor( x );
    std::cout << x << std::endl;

    //  Finalize
    return( 0 );
}
