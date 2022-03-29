/**
* @file abc228-a.cpp
* @brief ABC228 Problem A - On and Off
* @author Keitaro Naruse
* @date 2022-03-30
* @copyright MIT License
* @details https://atcoder.jp/contests/abc228/tasks/abc228_a
*/

// # Solution

#include <iostream>

int main()
{
    //  Read S, T, X = [ 0, 23 ]
    int S, T, X;
    std::cin >> S >> T >> X;

    //  Main
    if( ( S < T && S <= X && X < T ) 
        || ( S > T && 0 <= X && X < T )
        || ( S > T && S <= X )
    ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return( 0 );
}
