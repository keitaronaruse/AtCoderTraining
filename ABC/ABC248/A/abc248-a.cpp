/**
* @file abc248-a.cpp
* @brief ABC248 Problem A - Lacked Number
* @author Keitaro Naruse
* @date 2022-04-16
* @copyright MIT License
* @details https://atcoder.jp/contests/abc248/tasks/abc248_a
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>

int main()
{
    //  Read | S | = [ 9 ]
    std::string S;
    std::cin >> S;

    //  Main
    const int N = 10;
    std::vector< bool > counter( N, false );
    for( int i = 0; i < N - 1; i ++ ) {
        counter.at( S.at( i ) - '0' ) = true;
    }
    for( int i = 0; i < N; i ++ ) {
        if( !counter.at( i ) ) {
            std::cout << i << std::endl;;
            break;
        }
    }

    //  Finalize
    return( 0 );
}
