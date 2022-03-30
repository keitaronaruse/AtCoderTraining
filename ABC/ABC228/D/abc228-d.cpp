/**
* @file abc228-d.cpp
* @brief ABC228 Problem D - Linear Probing
* @author Keitaro Naruse
* @date 2022-03-30
* @copyright MIT License
* @details https://atcoder.jp/contests/abc228/tasks/abc228_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
        os << k << " ";
    }
    return( os );
}

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > > & vv )
{
    for( const auto& v : vv )  {
        os << v << std::endl;
    }
    return( os );
}

int main()
{
    //  Constant
    const long long N = 1048576L;

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
    std::map< int, int > next_available;
    for( int i = 0; i < Q; i ++ ) {
        int h = ( int )( x.at( i ) % N );
        if( t.at( i ) == 1 ) {
            auto curr = next_available.lower_bound( h );
            if( curr != next_available.end() ) {
                int k = curr -> second;
                A.at( k ) = x.at( i );
                curr -> second ++;
                // next_available[ h ] = k + 1;
                // it ++;
                auto next = curr;
                next ++;
                if( next != next_available.end() ) {
                    if( next -> first == k + 1 ) {
                        curr -> second = next -> second;
                        next_available.erase( next );
                    }
                }
            }
            else {
                A.at( h ) = x.at( i );
                next_available[ h ] = h + 1;
            }
        }
        else if( t.at( i ) == 2 ) {
            std::cout << A.at( h ) << std::endl;;
        }
    }


    //  Finalize
    return( 0 );
}
