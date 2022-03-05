/**
* @file abc242-b.cpp
* @brief ABC242 Problem B - Minimize Ordering
* @author Keitaro Naruse
* @date 2022-03-05
* @copyright MIT License
* @details https://atcoder.jp/contests/abc242/tasks/abc242_b
*/

// # Solution

#include <iostream>
#include <string>
#include <algorithm>

const bool Debug = false;

int main()
{
    //  Read | S | = [ 1, 2*10^5 ]
    std::string S = "";
    std::cin >> S;
    if( Debug ) {
        std::cerr << S <<  std::endl;
    }

    //  Main
    std::string s = S;
    std::sort( s.begin(), s.end() );
    std::cout << s << std::endl; 

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
