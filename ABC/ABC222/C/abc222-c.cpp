/**
* @file abc222-c.cpp
* @brief ABC222 Problem C - Swiss-System Tournament
* @author Keitaro Naruse
* @date 2022-04-12
* @copyright MIT License
* @details https://atcoder.jp/contests/abc222/tasks/abc222_c
*/

// # Solution

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>

template < class K, class V >
std::ostream& operator<<( std::ostream& os, const std::pair< K, V >& p )
{
    os << "( " <<p.first << ", " << p.second << " )";
    return( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& e : v ) {
        os << e << " ";
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 50 ], M = [ 1, 100 ]
    int N, M;
    std::cin >> N >> M;
    //  Read Aij = [ 0, 100 ]
    std::vector< std::string > A( 2 * N );
    for( auto& a : A ) {
        std::cin >> a;
    } 
    
    //  Main
    //  Preprocess
    //  ( num_wins, id )
    std::vector< std::pair< int, int > > wins_id( 2 * N );
    auto comp = []( std::pair< int, int > a, std::pair< int, int > b ) {
        return( ( a.first == b.first ) ? ( a.second < b.second) : ( a.first > b.first ) );
    };
    for( int k = 0; k < 2 * N; k ++ ) {
        wins_id.at( k ).first = 0;
        wins_id.at( k ).second = k;
    }
    std::sort( wins_id.begin(), wins_id.end(), comp );

    for( int i = 0; i < M; i ++ ) {
        //  Match
        for( int k = 0; k < N; k ++ ) {
            int id0 = wins_id.at( 2 * k ).second; 
            int id1 = wins_id.at( 2 * k + 1 ).second;
            if( 
                ( A.at( id0 ).at( i ) == 'G' && A.at( id1 ).at( i ) == 'C' ) || 
                ( A.at( id0 ).at( i ) == 'C' && A.at( id1 ).at( i ) == 'P' ) || 
                ( A.at( id0 ).at( i ) == 'P' && A.at( id1 ).at( i ) == 'G' ) 
            ) {
                wins_id.at( 2 * k ).first ++;
            }
            else if(
                ( A.at( id0 ).at( i ) == 'C' && A.at( id1 ).at( i ) == 'G' ) || 
                ( A.at( id0 ).at( i ) == 'P' && A.at( id1 ).at( i ) == 'C' ) || 
                ( A.at( id0 ).at( i ) == 'G' && A.at( id1 ).at( i ) == 'P' )             
            ) {
                wins_id.at( 2 * k + 1).first ++;
            }
        }
        //  Update
        std::sort( wins_id.begin(), wins_id.end(), comp );
    }
    for( int k = 0; k < 2 * N; k ++ ) {
        std::cout << wins_id.at( k ).second + 1 << std::endl;
    }

    //  Finalize
    return( 0 );
}
