/**
* @file abc248-d.cpp
* @brief ABC248 Problem D - Range Count Query
* @author Keitaro Naruse
* @date 2022-04-16
* @copyright MIT License
* @details https://atcoder.jp/contests/abc248/tasks/abc248_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
        os << k << " ";
    }
    return( os );
}

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > > & vv )
{
    for( const auto& v : vv )  {
        os << v << std::endl;
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 2*10^5 ]
    int N;
    std::cin >> N;
    //  Read Ai = [ 1, N ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    //  Read Q = [ 1, 2*10^5 ]
    int Q;
    std::cin >> Q;
    //  Read Li, Ri, Xi
    std::vector< int > L( Q ), R( Q ), X( Q );
    for( int j = 0; j < Q; j ++ ) {
        std::cin >> L.at( j ) >> R.at( j ) >> X.at( j );
    }

    //  Main
    //  Preprocess
    std::vector< std::map< int, int > > seg( N + 1 );
    for( int i = 0; i <= N / 2 ; i ++ ) {
        if( 2 * i < N ) {
            seg.at( i )[ A.at( 2 * i ) ] ++;
        }
        if( 2 * i + 1 < N ) {
            seg.at( i )[ A.at( 2 * i + 1 ) ]++;
        }
        for( const auto& p : seg.at( i ) ) {
            std::cerr << "( " << p.first << ", " << p.second << " ) ";
        }
        std::cerr << std::endl;
    }

    int depth = 0;
    int n = N;
    while( n != 0 ) {
        n /= 2;
        depth ++;
    }
    std::cerr << depth << std::endl;
    

    //  Finalize
    return( 0 );
}
