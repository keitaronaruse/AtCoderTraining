/**
* @file abc224-a.cpp
* @brief ABC224 Problem A - Tires
* @author Keitaro Naruse
* @date 2022-04-07
* @copyright MIT License
* @details https://atcoder.jp/contests/abc224/tasks/abc224_a
*/

// # Solution

#include <iostream>
#include <string>

int main()
{
    //  Read S, | S | = [ 2, 20 ]
    std::string S;
    std::cin >> S;
    
    //  Main
    // int n = S.size();
    // if( S.at( n - 2 ) == 'e' && S.at( n - 1 ) == 'r' ) {
    //     std::cout << "er" << std::endl;
    // }
    // else if( S.at( n - 3 ) == 'i' && S.at( n - 2 ) == 's' && S.at( n - 1 ) == 't' ) {
    //     std::cout << "ist" << std::endl;
    // }
    if( S.back() == 'r' ) {
        std::cout << "er" << std::endl;
    }
    else {
        std::cout << "ist" << std::endl;
    }

    //  Finalize
    return( 0 );
}
