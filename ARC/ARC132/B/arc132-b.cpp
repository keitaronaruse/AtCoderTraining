/**
* @file arc132-b.cpp
* @brief ARC132 Problem B - Shift and Reverse
* @author Keitaro Naruse
* @date 2022-03-28
* @copyright MIT License
* @details https://atcoder.jp/contests/arc132/tasks/arc132_b
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

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
    //  Read n = [ 2, 10^5 ]
    int n;
    std::cin >> n;
    //  Read pi = [ 1, n ]
    std::vector< int > p( n, 0 );
    for( int i = 0; i < n; i ++ ) {
        std::cin >> p.at( i );
    }

    //  Main
    //  Judge if we should reverse it
    bool is_ascending = true;
    if( p.at( n - 1 ) == 1 ) {
        if( p.at( 0 ) == 2 ) {
            is_ascending = true;
        }
        else {
            is_ascending = false;
        }
    }
    else {
        for( int i = 0; i < n - 1; i ++ ) {
            if( p.at( i ) == 1 ) {
                if( p.at( i ) == 2 ) {
                    is_ascending = true;
                }
                else {
                    is_ascending = false;
                }
                break;
            }
        }
    }

    //  Finalize
    return( 0 );
}
