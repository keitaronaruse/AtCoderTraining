/**
* @file abc245-d.cpp
* @brief ABC245 Problem D - Polynomial division
* @author Keitaro Naruse
* @date 2022-03-26, 2022-03-27
* @copyright MIT License
* @details https://atcoder.jp/contests/abc245/tasks/abc245_d
*/

// # Solution

#include <iostream>
#include <vector>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read N. M = [ 1, 10^2 ]
    int N, M;
    std::cin >> N >> M;

    //  Read Ai = [ -10^2, 10^2 ]
    std::vector< int > A( N + 1, 0 );
    for( int i = 0; i <= N; i ++ ) {
        std::cin >> A.at( i );
    }
    //  Read Ci = [ -10^6, 10^6 ]
    std::vector< int > C( N + M + 1, 0 );
    for( int j = 0; j <= N + M; j ++ ) {
        std::cin >> C.at( j );
    }

    //  Main
    std::vector< int > B( M + 1, 0 );
    for( int k = M; k >= 0; k -- ) {
        int AB_sum = 0;
        for( int i = 1; i <= M - k; i ++ ) {
            if( 0 <= N - i && k + i <= M ) {
                AB_sum += A.at( N - i ) * B.at( k + i );
            }
        }
        B.at( k ) = ( C.at( N + k ) - AB_sum ) / A.at( N );
    }
    std::cout << B << std::endl;
    
    //  Finalize
    return( 0 );
}
