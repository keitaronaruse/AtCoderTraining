/**
* @file abc219-b.cpp
* @brief ABC219 Problem B - Maritozzo
* @author Keitaro Naruse
* @date 2022-04-19
* @copyright MIT License
* @details https://atcoder.jp/contests/abc219/tasks/abc219_b
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>

int main()
{
    //  Read Si | Si | = [ 1, 10 ]
    //  Read T, | T | = [ 1, 1000 ]
    std::vector< std::string > S( 3 );
    std::string T;
    std::cin >> S.at( 0 ) >> S.at( 1 ) >> S.at( 2 ) >> T;

    for( int i = 0; i < T.size(); i ++ ) {
        std::cout << S.at( T.at( i ) - '1' );
    }
    std::cout << std::endl;
    
    //  Finalize
    return( 0 );
}
