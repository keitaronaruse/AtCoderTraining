/**
 * @file abc251-d.cpp
 * @brief ABC251 Problem D - At Most 3 (Contestant ver.)
 * @author Keitaro Naruse
 * @date 2022-05-14
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc251/tasks/abc251_d
 */

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) {
    for( const auto& k : v ) {
        os << k << " ";
    }
    return ( os );
}

int main( ) {
    //  Read W = [ 1, 10^6 ]
    int W;
    std::cin >> W;

    //  Main
    //  N = [ 1, 300 ]
    int N = 2;
    //  A
    std::vector< int > A;
    A.push_back( 1 );
    A.push_back( 2 );

    for( int N = 2; A.at( N - 1 ) + A.at( N - 2 ) + 1 < W; N++ ) {
        A.push_back( A.at( N - 1 ) + A.at( N - 2 ) + 1 );
    }

    std::cout << N << std::endl;
    std::cout << A << std::endl;

    //  Finalize
    return ( 0 );
}
