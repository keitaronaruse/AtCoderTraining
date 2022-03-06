/**
* @file abc242-d.cpp
* @brief ABC242 Problem D - ABC Transform
* @author Keitaro Naruse
* @date 2022-03-05, 2022-03-06
* @copyright MIT License
* @details https://atcoder.jp/contests/abc242/tasks/abc242_d
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const bool Debug = true;

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

char find_letter( const std::string& s, long long t0, long long k0 )
{
    char c = ' ';
    int offset = 0;

    long long k = k0;
    for( long long t = 0; t < t0; t ++ ) {
        offset += ( k % 2LL == 0 ) ? 1 : 2;
        k /= 2LL;
    }

    offset += s.at( k ) - 'A'; 
    offset %= 3;
    c = offset + 'A';
    return( c );
}

int main()
{
    //  Read | S | = [ 1, 10^5 ]
    std::string S = "";
    std::cin >> S;
    if( Debug ) {
        std::cerr << S << std::endl;
    }

    //  Read Q = [ 1, 10^5 ]
    int Q = 0;
    std::cin >> Q;
    if( Debug ) {
        std::cerr << Q << std::endl;
    }
    //  Read Ti = [ 0, 10^18 ], Ki = [ 1, 10^18 ]
    std::vector< long long > t( Q, 0LL ), k( Q, 0LL );
    for( int i = 0; i < Q; i ++ ) {
        //  k is a 1-index
        std::cin >> t.at( i ) >> k.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < Q; i ++ ) {
            std::cerr << t.at( i ) << " " << k.at( i ) << std::endl;
        }
    }

    //  Main
    for( int i = 0; i < Q; i ++ ) {
        //  Give a 0-index ( k - 1 )
        if( Debug ) {
            std::cerr << t.at( i ) << " " << k.at( i ) << " ";
        }
        std::cout << find_letter( S, t.at( i ), k.at( i ) - 1 ) << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
