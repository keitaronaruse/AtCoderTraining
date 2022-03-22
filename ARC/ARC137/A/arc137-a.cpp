/**
* @file arc137-a.cpp
* @brief ABC137 Problem A - Coprime Pair
* @author Keitaro Naruse
* @date 2022-03-19
* @copyright MIT License
* @details https://atcoder.jp/contests/arc137/tasks/arc137_a
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

namespace nrs {
    template < class T >
    T gcd( T a, T b )
    {
        T dividend = ( a > b )? a : b;
        T divisor  = ( a > b )? b : a;
        T residue = dividend % divisor;

        while( residue != 0 ) {
            dividend = divisor;
            divisor = residue;
            residue = dividend % divisor;
        }

        return( divisor );
    }

    template < class T >
    T lcm( T a, T b )
    {
        long long g = nrs::gcd( a, b );
        return( std::max( a, b ) / g * std::min( a, b ) );  
    }
}

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
    //  Read L, R = [ 1, 10^18 ]
    long long L, R;
    std::cin >> L >> R;

    //  Main
    std::queue< std::pair< long long, long long > > q;
    long long x = L, y = R;
    q.push( std::make_pair( x, y ) );
    while( !q.empty() ) {
        auto p = q.front(); q.pop(); 
        x = p.first;
        y = p.second;
        if( nrs::gcd( x, y ) == 1L ) {
            std::cout << y - x << std::endl;
            return( 0 );
        }
        else {
            if( x + 1L < y ) {
                q.push( std::make_pair( x + 1L, y ) );
            }
            if( x < y - 1L) {
                q.push( std::make_pair( x, y - 1L ) );
            }
        }
    }
    std::cout << "1" << std::endl;

    //  Finalize
    return( 0 );
}
