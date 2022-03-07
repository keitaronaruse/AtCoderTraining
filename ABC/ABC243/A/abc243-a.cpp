/**
* @file abc243-a.cpp
* @brief ABC243 Problem A
* @author Keitaro Naruse
* @date 2022-03-12
* @copyright MIT License
* @details https://atcoder.jp/contests/abc243/tasks/abc243_a
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const bool Debug = false;

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
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
        std::cerr << N << std::endl;
    }
    //  Read Ai
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    if( Debug ) {
        std::cerr << A << std::endl;
    }
    //  Read | S | = [ 1, 10^5 ]
    std::string S = "";
    std::cin >> S;
    if( Debug ) {
        std::cerr << S << std::endl;
    }

    //  Main

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
