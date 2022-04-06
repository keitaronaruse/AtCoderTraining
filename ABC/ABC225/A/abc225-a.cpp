/**
* @file abc225-a.cpp
* @brief ABC225 Problem A - Distinct Strings
* @author Keitaro Naruse
* @date 2022-04-06
* @copyright MIT License
* @details https://atcoder.jp/contests/abc225/tasks/abc225_a
*/

// # Solution

#include <iostream>
#include <string>

int main()
{
    //  Read S
    std::string S;
    std::cin >> S;
    
    //  Main
    int answer = 0;
    if( S.at( 0 ) == S.at( 1 ) && S.at( 1 ) == S.at( 2 ) && S.at( 2 ) == S.at( 0 ) ) {
        answer = 1;
    }
    else if( S.at( 0 ) != S.at( 1 ) && S.at( 1 ) != S.at( 2 ) && S.at( 2 ) != S.at( 0 ) ) {
        answer = 6;
    }
    else {
        answer = 3;
    }
    std::cout << answer << std::endl;

    //  Finalize
    return( 0 );
}
