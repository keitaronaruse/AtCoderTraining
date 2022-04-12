/**
* @file abc223-a.cpp
* @brief ABC223 Problem A - Exact Price
* @author Keitaro Naruse
* @date 2022-04-12
* @copyright MIT License
* @details https://atcoder.jp/contests/abc223/tasks/abc223_a
*/

// # Solution

#include <iostream>

int main()
{
    //  Read X = [ 0, 1000 ]
    int X;
    std::cin >> X;

    //  Main
    if( X % 100 == 0 && X != 0  ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return( 0 );
}
