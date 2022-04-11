/**
* @file abc247-e.cpp
* @brief ABC247 Problem E - Max Min
* @author Keitaro Naruse
* @date 2022-04-10
* @copyright MIT License
* @details https://atcoder.jp/contests/abc247/tasks/abc247_e
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
        os << k << " ";
    }
    return( os );
}

template< class K, class V >
std::ostream& operator<<( std::ostream& os, const std::pair< K, V >& p )
{
    os << "( " << p.first << ", " << p.second << " ) ";
    return( os );
}

int main()
{
    //  Read N = [ 1, 2 * 10^5 ], X = [ Y, 2 * 10^5 ], Y = [ 1, X ]
    int N, X, Y;
    std::cin >> N >> X >> Y;

    //  Read Ai = [ 1, 2 : 10^5 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    std::vector< int > X_pos, Y_pos;
    for( int i = 0; i < N; i ++ ) {
        if( A.at( i ) == X ) {
            X_pos.push_back( i );
        }
        if( A.at( i ) == Y ) {
            Y_pos.push_back( i );
        }
    }
    

    //  Finalize
    return( 0 );
}
