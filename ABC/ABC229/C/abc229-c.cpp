/**
* @file abc229-c.cpp
* @brief ABC229 Problem C - Cheese
* @author Keitaro Naruse
* @date 2022-03-21
* @copyright MIT License
* @details https://atcoder.jp/contests/abc229/tasks/abc229_c
*/

// # Solution

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

template< class T1, class T2 >
std::ostream& operator<<( std::ostream& os, const std::vector< std::pair< T1, T2 > >& v )
{
    for( auto k : v ) {
        os << "( " << k.first << ", " << k.second << " ) ";
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 3*10^5 ], W = [ 1, 3*10^8 ] 
    int N, W;
    std::cin >> N >> W;

    //  Read Ai = [ 1, 10^9 ], Bi = [ 1, 10^3 ]
    std::vector< int > A( N ), B( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i );
    }

    //  Main
    std::vector< std::pair< int, int > > AB( N );
    for( int i = 0; i < N; i ++ ) {
        AB.at( i ).first = A.at( i );
        AB.at( i ).second = B.at( i );
    }
    std::sort( AB.begin(), AB.end(), std::greater< std::pair< int, int > >() );

    long long sum_a = 0L;
    int sum_w = 0;
    for( int i = 0; i < N; i ++ ) {
        long long a = ( long long ) AB.at( i ).first;
        int w = ( long long ) AB.at( i ).second;
        if( sum_w + w <= W ) {
            sum_a += a * ( long long ) w;
            sum_w += w;
        }
        else {
            int u = W - sum_w;
            sum_a += a * ( long long ) u;
            sum_w += u;
            break;
        }
    }
    std::cout << sum_a << std::endl;

    //  Finalize
    return( 0 );
}
