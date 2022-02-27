/**
* @file abc241-a.cpp
* @brief ABC241 Problem A - Digit Machine 
* @author Keitaro Naruse
* @date 2022-02-26, 2022-02-27
* @copyright MIT License
* @details https://atcoder.jp/contests/abc241/tasks/abc241_a
*/

// # Solution

#include <iostream>
#include <vector>

const bool Debug = false;

std::ostream& operator<<( std::ostream& os, const std::vector< int >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read N = 10
    int N = 10;
    //  Read ai
    std::vector< int > a( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> a.at( i );
    }
    if( Debug ) {
        std::cerr << a << std::endl;
    }
    
    //  Main
    int k = 0;
    for( int i = 0; i < 3; i ++ ) {
        k = a.at( k );
        if( Debug ) {
            std::cerr << k << std::endl;
        }
    }
    std::cout << k << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
