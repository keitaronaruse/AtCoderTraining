/**
 * @file abc258-c.cpp
 * @brief ABC258 Problem C - Rotation
 * @author Keitaro Naruse
 * @date 2022-07-02
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc258/tasks/abc258_c
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

template < class T >
std::ostream& operator<<( std::ostream& os,
                          const std::vector< std::vector< T > >& vv ) {
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return ( os );
}

int main( ) {
    //  Read N = [ 2, 5*10^5 ], Q = [ 1, 5*10^5 ]
    int N, Q;
    std::cin >> N >> Q;

    //  Read | S | = N
    std::string S;
    std::cin >> S;

    //  Read t = [ 1, 2 ] x = [ 1, N ]
    std::vector< int > t( Q ), x( Q );
    for( int i = 0; i < Q; i++ ) {
        std::cin >> t.at( i ) >> x.at( i );
    }

    //  Main
    int head = 0;
    for( int i = 0; i < Q; i++ ) {
        if( t.at( i ) == 1 ) {
            head = ( head - x.at( i ) + N ) % N;
        } else if( t.at( i ) == 2 ) {
            std::cout << S.at( ( head + x.at( i ) - 1 + N ) % N ) << std::endl;
        }
    }

    //  Finalize
    return ( 0 );
}
