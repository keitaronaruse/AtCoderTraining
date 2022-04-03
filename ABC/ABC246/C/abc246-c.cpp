/**
* @file abc246-c.cpp
* @brief ABC246 Problem C - Coupon / 
* @author Keitaro Naruse
* @date 2022-04-02
* @copyright MIT License
* @details https://atcoder.jp/contests/abc246/tasks/abc246_c
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

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
    //  Read N = [ 2, 10^5 ], K, X = [ 1, 10^9 ]
    long long N, K, X;
    std::cin >> N >> K >> X;

    //  Read Ai = [ 1, 10^9 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    std::vector< int > Q( N ), R( N );
    long long A_sum = 0L;
    long long Q_sum = 0L;
    long long pay = 0L;
    for( int i = 0; i < N; i ++ ) {
        A_sum += ( long long ) A.at( i );
        Q.at( i ) = A.at( i ) / ( int ) X;
        Q_sum += ( long long ) Q.at( i );
        R.at( i ) = A.at( i ) % ( int ) X;
    }
    std::sort( R.begin(), R.end(), std::greater< int >() );

    if( Q_sum + N <= K ) {
        pay = 0L;
    }
    else if ( K <= Q_sum ) {
        pay  = A_sum - K * X;
    }
    else {
        pay = A_sum - Q_sum * X;
        for( int k = 0; k < ( K - Q_sum ); k ++ ) {
            pay -= ( long long )R.at( k );
        }
    }
    std::cout << pay << std::endl;

    //  Finalize
    return( 0 );
}
