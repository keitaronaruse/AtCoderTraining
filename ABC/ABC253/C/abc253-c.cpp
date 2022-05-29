/**
 * @file abc253-c.cpp
 * @brief ABC253 Problem C - Max - Min Query
 * @author Keitaro Naruse
 * @date 2022-05-28
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc253/tasks/abc253_c
 */

// # Solution

#include <iostream>
#include <vector>
#include <set>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::multiset< T >& v ) {
    for( const auto& k : v ) {
        os << k << " ";
    }
    return ( os );
}

int main( ) {
    //  Read N = [ 1, 2*10^5 ]
    int Q;
    std::cin >> Q;

    //  Read qi, xi, ci
    std::vector< int > q( Q ), x( Q ), c( Q );
    for( int i = 0; i < Q; i++ ) {
        std::cin >> q.at( i );
        if( q.at( i ) == 1 ) {
            std::cin >> x.at( i );
        } else if( q.at( i ) == 2 ) {
            std::cin >> x.at( i ) >> c.at( i );
        }
    }

    //  Main
    std::multiset< int > s;
    for( int i = 0; i < Q; i++ ) {
        if( q.at( i ) == 1 ) {
            s.insert( x.at( i ) );
        } else if( q.at( i ) == 2 ) {
            for( int j = 0; j < c.at( i ); j++ ) {
                auto it = s.find( x.at( i ) );
                if( it != s.end( ) ) {
                    s.erase( it );
                } else {
                    break;
                }
            }
        } else {
            auto max = s.end( );
            max--;
            auto min = s.begin( );
            std::cout << ( *max - *min ) << std::endl;
        }
    }

    //  Finalize
    return ( 0 );
}
