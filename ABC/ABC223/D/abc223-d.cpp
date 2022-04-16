/**
* @file abc223-d.cpp
* @brief ABC223 Problem D - Restricted Permutation
* @author Keitaro Naruse
* @date 2022-04-14, 2022-04-16
* @copyright MIT License
* @details https://atcoder.jp/contests/abc223/tasks/abc223_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
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

int main()
{
    //  Read N [ 2, 2*10^5 ], M = [ 1, 2*10^5 ]
    int N, M;
    std::cin >> N >> M;
    //  Read Ai, Bi = [ 1, N ]
    std::vector< int > A( M ), B( M );
    for( int k = 0; k < M; k ++ ) {
        std::cin >> A.at( k ) >> B.at( k );
    }

    //  Main
    //  Preprocess: Make a graph
    std::vector< std::vector< int > > in_nodes( N ), out_nodes( N );
    for( int k = 0; k < M; k ++ ) {
        out_nodes.at( A.at( k ) - 1 ).push_back( B.at( k ) - 1 );
        in_nodes.at( B.at( k ) - 1 ).push_back( A.at( k ) - 1 );
    }

    //  Main: Topolocical search
    std::vector< int > L( N );
    std::priority_queue< int, std::vector< int >,  std::greater< int > > S;
    for( int i = 0; i < N; i ++ ) {
        if( out_nodes.at( A.at( i ) ) ) {
            ;
        }
    }    

    
    //  Finalize
    return( 0 );
}
