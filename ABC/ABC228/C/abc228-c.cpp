/**
* @file abc228-c.cpp
* @brief ABC228 Problem C - Final Day
* @author Keitaro Naruse
* @date 2022-03-30
* @copyright MIT License
* @details https://atcoder.jp/contests/abc228/tasks/abc228_c
*/


// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

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
    for( const auto& v : vv)  {
        os << v << std::endl;
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 10^5 ], K = [ 1, N ]
    int N , K;
    std::cin >> N >> K;

    //  Read Pij = [ 0, 300 ]
    const int D = 3;
    std::vector< std::vector< int > > P( N, std::vector< int >( D, 0 ) );
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < D; j ++ ) {
            std::cin >> P.at( i ).at( j );
        }
    }

    //  Main
    std::vector< int > sum( N, 0 ), sum_order( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < D; j ++ ) {
            sum.at( i ) += P.at( i ).at( j );
        }
        sum_order.at( i ) = sum.at( i );
    }

    std::sort( sum_order.begin(), sum_order.end() );
    std::reverse( sum_order.begin(), sum_order.end() );
    for( int i = 0; i < N; i ++ ) {
        if( sum_order.at( K - 1 ) - sum.at( i ) <= 300 ) {
            std::cout << "Yes" << std::endl;
        }
        else {
            std::cout << "No" << std::endl;
        }
    }

    //  Finalize
    return( 0 );
}
