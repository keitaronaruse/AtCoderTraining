/**
* @file abc218-c.cpp
* @brief ABC218 Problem C - Shapes
* @author Keitaro Naruse
* @date 2022-04-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc218/tasks/abc218_c
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& e : v ) {
        os << e << " ";
    }
    return( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector < T > >& vv )
{
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 200 ]
    int N;
    std::cin >> N;
    //  Read S, T
    std::vector< std::string > S( N ), T( N );
    for( int i = 0; i < N; i ++  ) {
        std::cin >> S.at( i );
    }
    for( int i = 0; i < N; i ++  ) {
        std::cin >> T.at( i );
    }

    //  Main
    //  Preprocess
    std::vector< int > S_row( N, 0 ), S_col( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            if( S.at( i ).at( j ) == '#' ) {
                S_row.at( i ) ++;
                S_col.at( j ) ++;
            }
        }
    }
    int L, R, U, D;
    for( int j = 0; j < N; j ++ ) {
        if( S_col.at( j ) != 0 ) {
            L = j; break;
        }
    } 
    for( int j = N - 1; j >= 0; j -- ) {
        if( S_col.at( j ) != 0 ) {
            R = j; break;
        }
    } 
    for( int i = 0; i < N; i ++ ) {
        if( S_row.at( i ) != 0 ) {
            U = i; break;
        }
    } 
    for( int i = N - 1; i >= 0; i -- ) {
        if( S_row.at( i ) != 0 ) {
            D = i; break;
        }
    } 
    std::vector< std::string > P( D - U + 1, std::string( '.', R - L + 1 ) );
    for( int i = 0; i <= D - U; i ++ ) {
        for( int j = 0; j <= R - L; j ++ ) {
            P.at( i ).at( j ) = S.at( i + U ).at( j + L );
        }
    }
    std::cerr << P << std::endl;

    //  Find the solution    
    int answer = 0;
    std::cout << answer << std::endl;

    //  Finalize
    return( 0 );
}
