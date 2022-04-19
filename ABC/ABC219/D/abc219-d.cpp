/**
* @file abc219-d.cpp
* @brief ABC219 Problem D - Strange Lunchbox
* @author Keitaro Naruse
* @date 2022-04-14, 2022-04-18
* @copyright MIT License
* @details https://atcoder.jp/contests/abc219/tasks/abc219_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <functional>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& e : v ) {
        os << e << " ";
    }
    return( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::pair< const std::pair< T, T >, std::vector< T > >& pp )
{
    os << "( " << pp.first.first << ", " << pp.first.second << " )" << "{ "<< pp.second << "}";
    return( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::map< std::pair< T, T >, std::vector< T > > & m )
{
    for( const auto& e : m ) {
        os << e << " ";
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 300 ], X, Y = [ 1, 300 ]
    int N, X, Y;
    std::cin >> N >> X >> Y;
    //  Read Ai, Bi = [ 1, 300 ]
    std::vector< int > A( N ), B( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i );
    } 

    //  Main
    std::map< std::pair< int, int >, std::vector< int > > q;
    //  Initial values
    for( int k = 0; k < N; k ++ ) {
        std::vector< int > v = { k };
        q.insert(
            std::make_pair( std::make_pair( A.at( k ), B.at( k ) ), v )
        );
    }
    //  Iterations
    int answer = -1;
    for( auto it = q.begin(); it != q.end(); ) {
        int k = it -> second.back() + 1;
        if( k < N ) {
            std::pair< int, int > p( it -> first.first + A.at( k ),  it -> first.second + B.at( k ) );
            if( p.first >= X && p.second >= Y ) {
                answer = it -> second.size() + 1;
                break;
            }
            //  Insert or update 
            auto it_p = q.find( p );
            if( it_p == q.end() ) {
                std::vector< int > v = it -> second; 
                v.push_back( k );
                q.insert( std::make_pair( p, v ) );
            }
            else {
                it_p -> second.push_back( k );
            }
        }
        it = q.erase( it );
    }
    std::cout << answer << std::endl;

    //  Finalize
    return( 0 );
}
