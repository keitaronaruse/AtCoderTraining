/**
* @file abc219-a.cpp
* @brief ABC219 Problem A - AtCoder Quiz 2
* @author Keitaro Naruse
* @date 2022-04-19
* @copyright MIT License
* @details https://atcoder.jp/contests/abc219/tasks/abc219_a
*/

// # Solution

#include <iostream>

int main()
{
    //  Read X = [ 0, 100 ]
    int X;
    std::cin >> X;

    //  Main
    if( 0 <= X && X < 40 ) {
        std::cout << 40 - X << std::endl;
    }
    else if( 40 <= X && X < 70 ) {
        std::cout << 70 - X << std::endl;
    }
    else if( 70 <= X && X < 90 ) {
        std::cout << 90 - X << std::endl;
    }
    else {
        std::cout << "expert" << std::endl;
    }

    //  Finalize
    return( 0 );
}
