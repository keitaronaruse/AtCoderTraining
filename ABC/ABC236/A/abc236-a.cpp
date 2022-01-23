/**
* @file abc236-a.cpp
* @brief ABC236 Problem A
* @author Keitaro Naruse
* @date 2022-01-23
* @copyright MIT License
* @details https://atcoder.jp/contests/abc236/tasks/abc236_a
*/

// # Solution

#include <iostream>
#include <string>

const bool Debug = false;

int main()
{
    //  Read S
    std::string S = "";
    std::cin >> S;
    if( Debug ) {
        std::cerr << S << std::endl;
    }
    //  Read a and b 
    int a = 0, b = 0;
    std::cin >> a >> b;
    if( Debug ) {
        std::cerr << a << " " << b << std::endl;
    }
    a --;
    b --;
    //  Main
    std::swap( S.at( a ), S.at( b ) );
    std::cout << S << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
