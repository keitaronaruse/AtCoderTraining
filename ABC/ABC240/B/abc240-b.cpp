/**
* @file abc240-b.cpp
* @brief ABC240 Problem B
* @author Keitaro Naruse
* @date 2022-02-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc240/tasks/abc240_b
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
    //  Read N = [ 1, 1000 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N <<  std::endl;
    }
    //  Read Ai
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    if( Debug ) {
        std::cerr << A << std::endl;
    }
    //  Read S
    std::string S = "";
    std::cin >> S;
    if( Debug ) {
        std::cerr << S <<  std::endl;
    }

    //  Main

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
