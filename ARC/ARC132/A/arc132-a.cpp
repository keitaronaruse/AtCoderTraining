/**
* @file arc132-a.cpp
* @brief ARC132 Problem A - Permutation Grid
* @author Keitaro Naruse
* @date 2022-03-27
* @copyright MIT License
* @details https://atcoder.jp/contests/arc132/tasks/arc132_a
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
    //  Read n = [ 1, 10^5 ]
    int n;
    std::cin >> n;
    //  Read Ri = [ 1, n ]
    std::vector< int > R( n, 0 );
    for( int i = 0; i < n; i ++ ) {
        std::cin >> R.at( i );
    }
    //  Read Ci = [ 1, n ]
    std::vector< int > C( n, 0 );
    for( int i = 0; i < n; i ++ ) {
        std::cin >> C.at( i );
    }

    //  Read q = [ 1, 10^5 ]
    int q;
    std::cin >> q;
    //  Read r, c  = [ 1, 10^5 ]
    std::vector< int > r( q ), c( q );
    for( int j = 0; j < q; j ++ ) {
        std::cin >> r.at( j ) >> c.at( j );
    }

    //  Main
    std::cerr << R << std::endl;
    std::cerr << C << std::endl;
    std::cerr << r << std::endl;
    std::cerr << c << std::endl;

    //  Finalize
    return( 0 );
}
