/**
* @file abc220-a.cpp
* @brief ABC220 Problem A - Find Multiple
* @author Keitaro Naruse
* @date 2022-04-08
* @copyright MIT License
* @details https://atcoder.jp/contests/abc220/tasks/abc220_a
*/

// # Solution

#include <iostream>

int main()
{
    //  Read A, B, C = [ 1, 10^3 ]
    int A, B, C;
    std::cin >> A >> B >> C;
    
    //  Main
    int x = B / C * C;
    if( x < A || B < x ) {
        x = -1;
    }
    std::cout << x << std::endl;

    //  Finalize
    return( 0 );
}
