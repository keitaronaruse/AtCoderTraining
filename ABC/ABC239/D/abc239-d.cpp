/**
* @file abc239-d.cpp
* @brief ABC239 Problem D
* @author Keitaro Naruse
* @date 2022-02-12
* @copyright MIT License
* @details https://atcoder.jp/contests/abc239/tasks/abc239_d
*/

// # Solution

#include <iostream>
#include <vector>

const bool Debug = false;

int main()
{
    //  Read T = [ 1, 10^5 ]
    int T = 0;
    std::cin >> T;
    if( Debug ) {
        std::cerr << T << std::endl;
    }
    //  Read si, ai = [ 0, 2^60 ]
    std::vector< unsigned long long > a( T, 0uLL ), s( T, 0uLL );
    for( int i = 0; i < T; i ++ ) {
        std::cin >> a.at( i ) >> s.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < T; i ++ ) {
            std::cerr << a.at( i ) << " " << s.at( i ) << std::endl;
        }
    }

    //  Main
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
