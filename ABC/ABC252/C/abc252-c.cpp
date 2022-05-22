/**
 * @file abc252-c.cpp
 * @brief ABC252 Problem C - Slot Strategy
 * @author Keitaro Naruse
 * @date 2022-05-21
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc252/tasks/abc252_c
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
    //  Read N = [ 2, 100 ]
    int N;
    std::cin >> N;

    //  Read | Si | = [ 10 ]
    std::vector< std::string > S( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> S.at( i );
    }

    //  Main
    //  Preprocess
    const int K = 10;
    std::vector< std::vector< int > > pos( K, std::vector< int >( K, 0 ) );
    for( int i = 0; i < N; i++ ) {
        for( int k = 0; k < K; k++ ) {
            int digit = S.at( i ).at( k ) - '0';
            pos.at( digit ).at( k )++;
        }
    }

    //  Solution
    std::vector< int > sec( K, 0 );
    for( int digit = 0; digit < K; digit++ ) {
        int max_pos = 0, max_k = 0;
        for( int k = 0; k < K; k++ ) {
            if( pos.at( digit ).at( k ) >= 1 ) {
                if( max_pos <= pos.at( digit ).at( k ) ) {
                    max_pos = pos.at( digit ).at( k );
                    max_k = k;
                }
            }
        }
        sec.at( digit ) = ( pos.at( digit ).at( max_k ) - 1 ) * K + max_k;
    }

    int min_sec = N * K + 1;
    for( int k = 0; k < K; k++ ) {
        min_sec = std::min( min_sec, sec.at( k ) );
    }
    std::cout << min_sec << std::endl;
    //  Finalize
    return ( 0 );
}
