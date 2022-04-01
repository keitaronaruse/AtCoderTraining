/**
* @file abc228-d.cpp
* @brief ABC228 Problem D - Linear Probing
* @author Keitaro Naruse
* @date 2022-03-30, 2022-04-01
* @copyright MIT License
* @details https://atcoder.jp/contests/abc228/tasks/abc228_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

template < class K, class V >
std::ostream& operator<<(std::ostream& os, const std::map< K, V >& m )
{
    for( const auto& p : m) {
        os << "( " << p.first << ", " << p.second << ") ";
    }
    return( os );
} 

int main()
{
    //  Constant
    const int N = 1048576;
    const long long NL = 1048576L;

    //  Read Q = [ 2, 2*10^5 ]
    int Q;
    std::cin >> Q;
    
    //  Read t = [ 0, 1 ], x = [ 0, 10^18 ]
    std::vector< int > t( Q, 0 );
    std::vector< long long > x( Q, 0L );
    for( int i = 0; i < Q; i ++ ) {
        std::cin >> t.at( i ) >> x.at( i );
    }

    //  Main
    std::vector< long long > A( N, -1L );
    std::map< int, int > interval;
    interval[ N ] = 0;

    for( int i = 0; i < Q; i ++ ) {
        int h = ( int )( x.at( i ) % NL );
        if( t.at( i ) == 1 ) {
            auto itr = interval.upper_bound( h );
            //  Boundary check
            if( itr == interval.end() ) {
                h = 0;
                itr = interval.begin();
            }
            //  Main
            if( itr -> second <= h ) {
                A.at( h ) = x.at( i );
                int l1 = itr -> second, r1 = h, l2 = h + 1, r2 = itr -> first;
                interval.erase(itr);
                if( l1 != r1 ) {
                    interval[ r1 ] = l1;
                }
                if( l2 != r2 ) {
                    interval[ r2 ] = l2;
                }
            }
            else {
                A.at( itr->second ) = x.at( i );
                itr -> second ++;
                if( itr -> first == itr -> second ) {
                    interval.erase( itr );
                }
            }
        }
        else if( t.at( i ) == 2 ) {
            std::cout << A.at( h ) << std::endl;;
        }
    }

    //  Finalize
    return( 0 );
}
