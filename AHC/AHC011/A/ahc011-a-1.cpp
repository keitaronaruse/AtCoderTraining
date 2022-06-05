/**
* @file ahc011-a-1.cpp
* @brief AHC011 Problem A - Sliding Tree Puzzle
* @author Keitaro Naruse
* @date 2022-06-05
* @copyright MIT License
* @details https://atcoder.jp/contests/ahc011/tasks/ahc011_a
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
        os << k << " ";
    }
    return( os );
}

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > >& vv )
{
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return( os );
}

int main()
{
    //  Read N = [ 6, 10 ], T = 2 * N^3
    int N, T;
    std::cin >> N >> T;

    //  Read tij
    int pi, pj;
    std::vector< std::vector< char > > t( N, std::vector< char >( N, ' ') );
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            std::cin >> t.at( i ).at( j );
            if( t.at( i ).at( j ) == '0' ) {
                pi = i;
                pj = j;
            }
        }
    }
    
    //  Main
    //  Find the solution
    while( !( pi == N - 1 && pj == N - 1 ) ) {
        if( pi < N - 1 ) {
            std::cout << "D";
            pi ++;
        }
        else if( pj < N - 1 ) {
            std::cout << "R";
            pj ++;
        }
    }
    std::cout << std::endl;

    //  Finalize
    return( 0 );
}
