/**
 * @file abc254-d.cpp
 * @brief ABC254 Problem D - Together Square
 * @author Keitaro Naruse
 * @date 2022-06-04
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc254/tasks/abc254_d
 */

// # Solution

#include <iostream>
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
    //  Read N = [ 1, 2 * 10^5 ]
    int N;
    std::cin >> N;

    //  Main
    //  Prime factorization
    std::vector< std::vector< int > > P( N );
    int answer = 0;
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
