/**
 * @file abc256-d.cpp
 * @brief ABC256 Problem D - Union of Interval
 * @author Keitaro Naruse
 * @date 2022-06-18, 2022-06-19
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc256/tasks/abc256_d
 */

// # Solution

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

template < class K, class V >
std::ostream& operator<<( std::ostream& os, const std::pair< K, V >& p ) {
    os << p.first << " " << p.second;
    return ( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) {
    for( const auto& k : v ) {
        os << k << std::endl;
    }
    return ( os );
}

int main( ) {
    //  Read N = [ 1, 2*10^5 ]
    int N;
    std::cin >> N;

    //  Read Li, Ri = [ 1, 2*10^5 ]
    std::vector< int > L( N ), R( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> L.at( i ) >> R.at( i );
    }

    //  Main
    //  Preprocess
    std::vector< std::pair< int, int > > LR( N );
    for( int i = 0; i < N; i++ ) {
        LR.at( i ).first = L.at( i );
        LR.at( i ).second = R.at( i );
    }
    std::sort( LR.begin( ), LR.end( ) );
    //  Solution
    std::vector< std::pair< int, int > > S;
    S.push_back( LR.at( 0 ) );
    for( int i = 1; i < N; i++ ) {
        int l = LR.at( i ).first, r = LR.at( i ).second;
        auto it = std::lower_bound( S.begin( ), S.end( ), LR.at( i ),
                                    []( const std::pair< int, int >& a,
                                        const std::pair< int, int >& b ) {
                                        if( a.first == b.first ) {
                                            return ( a.second < b.second );
                                        } else {
                                            return ( a.first < b.first );
                                        }
                                    } );
        if( it == S.end( ) ) {
            it--;
            if( it->second < l ) {
                S.push_back( LR.at( i ) );
            } else {
                it->second = std::max( it->second, r );
            }
        } else {
            if( l <= it->second ) {
                it->second = std::max( it->second, r );
            }
        }
    }
    std::cout << S;

    //  Finalize
    return ( 0 );
}
