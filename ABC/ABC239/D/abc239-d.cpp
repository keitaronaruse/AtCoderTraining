/**
* @file abc239-d.cpp
* @brief ABC239 Problem D
* @author Keitaro Naruse
* @date 2022-02-19
* @copyright MIT License
* @details https://atcoder.jp/contests/abc239/tasks/abc239_d
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
    //  Read N = [ 1, 359 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N <<  std::endl;
    }
    //  Read Aij
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    if( Debug ) {
        std::cerr << A << std::endl;
    }
    //  Main
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
