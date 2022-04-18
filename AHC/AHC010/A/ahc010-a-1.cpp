/**
* @file ahc009-a-1.cpp
* @brief AHC009 Problem A - Robust Memory of Commuting Routes
* @author Keitaro Naruse
* @date 2022-03-26
* @copyright MIT License
* @details https://atcoder.jp/contests/ahc009/tasks/ahc009_a
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > >& vv )
{
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return( os );
}

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Constant
    int N = 20;
    //  Read si, sj, = [ 0, 4 ], ti, tj = [ 15, 19 ]
    int si, sj, ti, tj;
    std::cin >> si >> sj >> ti >> tj;
    //  Read p = [ 0.1, 0.5 ]
    double p;
    std::cin >> p;

    //  Read hij = [ 0, 1 ]
    std::vector< std::vector< int > > h( N, std::vector< int >( N - 1, 0 ) ); 
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N - 1; j ++ ) {
            char c;
            std::cin >> c;
            h.at( i ).at( j ) = c - '0';
        }
    }
    //  Read vij = [ 0, 1 ]
    std::vector< std::vector< int > > v( N - 1, std::vector< int >( N, 0 ) ); 
    for( int i = 0; i < N - 1; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            char c;
            std::cin >> c;
            v.at( i ).at( j ) = c - '0';
        }
    }

    //  Main
    // std::cerr << si << " " << sj << " " << ti << " " << tj << " " << p << std::endl;
    // std::cerr << h << std::endl;
    // std::cerr << v << std::endl;
    int r_num = ( int )( ( 1.0 + 2.0 + p ) * ( double )( tj - sj + 1 ) );
    int d_num = ( int )( ( 1.0 + 2.0 + p ) * ( double )( ti - si + 1 ) );
    // std::cerr << r_num << " " << d_num << std::endl;

    int k = 0, K = 200;
    std::string actions( K, '.' );
    int r = 0, d = 0;
    for( k = 0; k < r_num + d_num; ) {
        if( r < r_num ) {
            actions.at( k ) = 'R';
            k ++;
            r ++;
        }
        if( d < d_num ) {
            actions.at( k ) = 'D';
            k ++;
            d ++;
        }
    }
    for( ; k < K; k ++ ) {
        switch( k % 4 ) {
            case 0: actions.at( k ) = 'R'; break;
            case 1: actions.at( k ) = 'D'; break;
            case 2: actions.at( k ) = 'L'; break;
            case 3: actions.at( k ) = 'U'; break;
            default: break;
        }
    }
    std::cout << actions << std::endl;
    //  Finalize
    return( 0 );
}
