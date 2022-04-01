/**
* @file abc226-c.cpp
* @brief ABC226 Problem C - Martial artist
* @author Keitaro Naruse
* @date 2022-04-01
* @copyright MIT License
* @details https://atcoder.jp/contests/abc226/tasks/abc226_c
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

long long minutes( int k, 
    const std::vector< int >& T,  
    const std::vector< int >& K,  
    const std::vector< std::vector< int > >& A
    )
{
    if( K.at( k ) == 0 ) {
        return( ( long long ) T.at( k ) );
    }
    else {
        long long sum = ( long long ) T.at( k );
        for( int i = 0; i < K.at( k ); i ++ ) {
            sum += minutes( A.at( k ).at( i ) - 1, T, K, A );
        }
        return( sum );
    }
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) 
{
    for( const auto& k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 2*10^5 ]
    int N;
    std::cin >> N;
    //  Read Ti = [ 1, 10^9 ], Ki = [ 1, N ], Aij = [ 1, i ]
    std::vector< int > T( N ), K( N );
    std::vector< std::vector< int > > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> T.at( i ) >> K.at( i );
        A.at( i ) = std::vector< int >( K.at( i ) );
        for( int j = 0; j < K.at( i ); j ++ ) {
            std::cin >> A.at( i ).at( j );
        }
    } 

    //  Main
    std::cout << minutes( N - 1, T, K, A ) << std::endl;

    //  Finalize
    return( 0 );
}
