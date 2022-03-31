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

template< class T, class S >
std::ostream& operator<<( std::ostream& os, const std::map< T, S > & m )
{
    for( const auto& p : m )  {
        os << "( " << p.first << ", " << p.second << " ) ";
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
            auto curr_it = next_available.lower_bound( h );
            auto prev_it = curr_it;
            if( curr_it != next_available.begin() ) {
                prev_it --;
            }

            if( curr_it == next_available.begin() && curr_it == next_available.end() ) {
                //  No element
                A.at( h ) = x.at( i );
                next_available[ h ] = h + 1;
            }
            else if( curr_it == prev_it ) {
                //  Single element
                if( curr_it -> first <= h && h <= curr_it -> second ) {
                    A.at( curr_it -> second ) = x.at( i );
                    curr_it -> second ++;
                }
                else if( curr_it -> first - 1 == h ) {
                    A.at( h ) = x.at( i );
                    next_available[ h ] = curr_it -> second;
                    next_available.erase( curr_it );
                }
                else {
                    A.at( h ) = x.at( i );
                    next_available[ h ] = h + 1;
                }
            }
            else {
                //  Multiple element
                if( prev_it -> first <= h && h <= prev_it -> second ) {
                    A.at( prev_it -> second ) = x.at( i );;
                    prev_it -> second ++ ;
                    if( prev_it -> second == curr_it -> first ) {
                        prev_it -> second = curr_it -> second;
                        next_available.erase( curr_it );
                    }
                }
                else if( prev_it -> first - 1 == h ) {
                    A.at( h ) = x.at( i );                    ;
                    next_available[ h ] = prev_it -> second;
                    next_available.erase( prev_it );
                }
                else if( curr_it -> first <= h && h <= curr_it -> second ){
                    A.at( curr_it -> second ) = x.at( i );
                    curr_it -> second ++ ;
                }
                else if( curr_it -> first - 1 == h ) {
                    A.at( h ) = x.at( i );
                    next_available[ h ] = curr_it -> second;
                    next_available.erase( curr_it );
                }
                else {
                    next_available[ h ] = h + 1;
                    A.at( h ) = x.at( i );
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
