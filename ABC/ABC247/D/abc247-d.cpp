/**
* @file abc247-d.cpp
* @brief ABC247 Problem D - Cylinder
* @author Keitaro Naruse
* @date 2022-04-10
* @copyright MIT License
* @details https://atcoder.jp/contests/abc247/tasks/abc247_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
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
    //  Read Q = [ 1, 2 * 10^5 ]
    int Q;
    std::cin >> Q;

    //  Read qi = [ 1, 2 ], xi = [ 0, 10^9 ], ci = [ 1, 10^9 ]
    std::vector< int > q( Q ), x( Q ), c( Q );
    for( int i = 0; i < Q; i ++ ) {
        std::cin >> q.at( i );
        if( q.at( i ) == 1 ) {
            std::cin >> x.at( i ) >> c.at( i );
        }
        else if( q.at( i ) == 2 ) {
            std::cin >> c.at( i );
        }
    }

    //  Main
    //  ( x, c )
    std::deque< std::pair< int, int > > dec;
    for( int i = 0; i < Q; i ++ ) {
        if( q.at( i ) == 1 ) {
            dec.push_back( std::make_pair( x.at( i ), c.at( i ) ) );
        }
        else if( q.at( i ) == 2 ) {
            int num_balls = c.at( i );
            long long sum = 0L;
            do {
                auto p = dec.front();
                if( p.second > num_balls ) {
                    //  ( x, c ) is larger than c.at( i )  
                    //  Push it back
                    sum += ( long long ) p.first * ( long long ) num_balls;
                    dec.pop_front();
                    dec.push_front( std::make_pair( p.first, p.second - num_balls ) );
                    num_balls -= p.second;
                }
                else {
                    //  ( x, c ) is smaller than or equal to c.at( i )
                    //  Pop it again
                    sum += ( long long ) p.first * ( long long ) p.second;
                    num_balls -= p.second; 
                    dec.pop_front();
                }
            } while( 0 < num_balls );
            std::cout << sum << std::endl;
        }
    }

    //  Finalize
    return( 0 );
}
