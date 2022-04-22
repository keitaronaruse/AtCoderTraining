/**
* @file abc218-c.cpp
* @brief ABC218 Problem C - Shapes
* @author Keitaro Naruse
* @date 2022-04-20, 2022-04-22
* @copyright MIT License
* @details https://atcoder.jp/contests/abc218/tasks/abc218_c
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
bool new_solution( int N, const std::vector< std::string >& S, const std::vector< std::string >& T )
{
    bool isYes = false;

    //  Preprocess
    std::vector< std::pair< int, int > > s, t;
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            if( S.at( i ).at( j ) == '#' ) {
                s.push_back( std::make_pair( i, j ) );
            }
            if( T.at( i ).at( j ) == '#' ) {
                t.push_back( std::make_pair( i, j ) );
            }
        }
    }
    if( s.size() != t.size() ) {
        isYes = false;
        return( isYes );
    }
    std::sort( s.begin(), s.end() );
    std::sort( t.begin(), t.end() );

    std::vector< std::pair< int, int > > u = t;
    const int K = 4;
    for( int k = 0; k < K; k ++ ) {
        int delta_i = u.at( 0 ).first - s.at(0).first;
        int delta_j = u.at( 0 ).second - s.at(0).second;
        for( auto& e : u ) {
            e.first -= delta_i;
            e.second -= delta_j;
        }
        if( s == u ) {
            isYes = true;
            return( isYes );
        }
        for( auto& e : u ) {
            std::swap( e.first, e.second );
            e.second *= -1;
        }
        std::sort( u.begin(), u.end() );
    }

    return( isYes );
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

    //  Find the solution
    if( new_solution( N, S, T ) ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return( 0 );
}
