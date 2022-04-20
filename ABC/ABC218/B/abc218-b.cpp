/**
* @file abc218-b.cpp
* @brief ABC218 Problem B - qwerty
* @author Keitaro Naruse
* @date 2022-04-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc218/tasks/abc218_b
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>

int main()
{
    //  constant N
    const int N = 26;
    //  Read Pi
    std::vector< int > P( N );
    for( auto& p : P ) {
        std::cin >> p;
    }

    //  Main
    std::string S( N, ' ' );
    for( int i = 0; i < N; i ++ ) {
        S.at( i ) = ( char )( P.at( i ) - 1 + 'a' );
    }
    std::cout << S << std::endl;

    //  Finalize
    return( 0 );
}
