/**
* @file abc222-d.cpp
* @brief ABC222 Problem D - Between Two Arrays
* @author Keitaro Naruse
* @date 2022-04-13, 2022-04-14
* @copyright MIT License
* @details https://atcoder.jp/contests/abc222/tasks/abc222_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>

template < class K, class V >
std::ostream& operator<<( std::ostream& os, const std::pair< K, V >& p )
{
    os << "( " <<p.first << ", " << p.second << " )";
    return( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& e : v ) {
        os << e << " ";
    }
    return( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > >& vv )
{
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return( os );
}

int main()
{
    //  const 
    const int P = 998244353;
    const int M = 3000;

    //  Read N = [ 1, 3*10^3 ]
    int N;
    std::cin >> N;
    //  Read Ai = [ 0, Bi ], Bi = [ Ai, 3*10^3 ]
    std::vector< int > A( N + 1 ), B( N + 1 );
    for( int i = 1; i <= N; i ++ ) {
        std::cin >> A.at( i );
    } 
    for( int i = 1; i <= N; i ++ ) {
        std::cin >> B.at( i );
    } 
    
    //  Main
    //  dp.at( i ).at( k )
    //  the accumurated number of combinations of the value of Ci = k at the i-th iteration
    std::vector< std::vector< int > > dp( N + 1, std::vector< int >( M + 1, 0 ) );
    //  Initial boundary condition
    for( int k = 0; k <= M; k ++ ) {
        dp.at( 0 ).at( k ) = 1;
    }
    for( int i = 1; i <= N; i ++ ) {
        for( int k = A.at( i ); k <= B.at( i ); k ++ ) {
            dp.at( i ).at( k ) = dp.at( i - 1 ).at( k );
            if( k >= 1 ) {
                dp.at( i ).at( k ) += dp.at( i ).at( k - 1 );
            }
            dp.at( i ).at( k ) %= P;
        }
        for( int k = B.at( i ) + 1; k <= M; k ++ ) {
            dp.at( i ).at( k ) = dp.at( i ).at( k - 1 );
        }
    }
    std::cout << dp.at( N ).at( M ) << std::endl;

    //  Finalize
    return( 0 );
}
