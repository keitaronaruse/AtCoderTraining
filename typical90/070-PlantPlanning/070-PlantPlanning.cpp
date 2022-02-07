/*
* @file 070-PlantPlanning.cpp
* @brief 070 - Plant Planning（★4）
* @author Keitaro Naruse
* @date 2022-01-29, 2022-02-07
* @copyright MIT License
* @details https://atcoder.jp/contests/typical90/tasks/typical90_br
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = false;

namespace nrs {
    template < class T >
    T abs( T a )
    {
        return( ( a > 0 )? a : -a );
    }

    template < class T >
    T median( const std::vector< T >& v )
    {
        size_t n = v.size();
        if( n % 2 == 1 ) {
            return( v.at( n / 2 ) );
        }
        else {
            return( ( v.at( n / 2 - 1 ) + v.at( n / 2 ) ) / 2 );
        }
    }
}

int main()
{
    //  Read N = [ 1, 10^5 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read Xi and Yi = [ -10^9, 10^9 ]
    std::vector< int > X( N, 0 ), Y( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> X.at( i ) >> Y.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << X.at( i ) << " " << Y.at( i ) << std::endl;
        }
    }

    //  Main
    std::vector< int > x = X;
    std::sort( x.begin(), x.end() );
    int px = nrs::median( x );

    std::vector< int > y = Y;
    std::sort( y.begin(), y.end() );
    int py = nrs::median( y );

    long long inconv = 0LL;
    for( int i = 0; i < N; i ++ ) {
        inconv += ( long long ) nrs::abs( x.at( i ) - px );
        inconv += ( long long ) nrs::abs( y.at( i ) - py );
    }
    std::cout << inconv << std::endl;
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
