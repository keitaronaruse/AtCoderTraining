/**
* @file abc240-a.cpp
* @brief ABC240 Problem A
* @author Keitaro Naruse
* @date 2022-02-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc240/tasks/abc240_a
*/

// # Solution

#include <iostream>
#include <string>

const bool Debug = false;

int main()
{
    //  Read a, b = [ 1, 10 ]
    int a = 0, b = 0;
    std::cin >> a >> b;
    if( Debug ) {
        std::cerr << a << " " << b << std::endl;
    }

    //  Main
    bool isYes = false;
    if( b - a == 1 ) {
        isYes = true;
    }
    else if( b == 10 && a == 1) {
        isYes = true;
    }

    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
