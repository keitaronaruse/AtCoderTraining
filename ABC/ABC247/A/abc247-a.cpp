/**
* @file abc247-a.cpp
* @brief ABC247 Problem A - Move Right
* @author Keitaro Naruse
* @date 2022-04-10
* @copyright MIT License
* @details https://atcoder.jp/contests/abc247/tasks/abc247_a
*/

// # Solution

#include <iostream>
#include <string>

int main()
{
    //  Read | S | = [ 1, 10^6 ]
    std::string S;
    std::cin >> S;

    //  Main
    const int N = 4;
    std::string T( N, ' ' );
    T.at( 0 ) = '0';
    T.at( 1 ) = S.at( 0 );
    T.at( 2 ) = S.at( 1 );
    T.at( 3 ) = S.at( 2 );
    std::cout << T << std::endl;
    
    //  Finalize
    return( 0 );
}
