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

template< class T >
std::ostream& operator<<( std::ostream& os, const std::priority_queue< T, std::vector< T >, std::greater< T > > & q )
{
    std::priority_queue< T, std::vector< T >, std::greater< T > > r = q;
    while( !r.empty() ) {
        os << r.top() << " ";
        r.pop();
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
    //  1-index
    std::vector< std::vector< int > > in_nodes( N + 1 ), out_nodes( N + 1 );
    for( int k = 0; k < M; k ++ ) {
        out_nodes.at( A.at( k ) ).push_back( B.at( k ) );
        in_nodes.at( B.at( k ) ).push_back( A.at( k ) );
    }

    //  Main: Topolocical search
    //  Sorted sequence
    std::vector< int > L( N );
    //  A set of woking nodes
    std::priority_queue< int, std::vector< int >,  std::greater< int > > S;
    //  Initial S
    for( int i = 1; i <= N; i ++ ) {
        if( in_nodes.at( i ).size() == 0 ) {
            S.push( i );
        }
    }    
    //  Loop
    int k = 0;
    while( !S.empty() ) {
        int v = S.top(); S.pop();
        L.at( k ) = v; k ++;

        //  Edge update
        for( auto it = out_nodes.at( v ).begin(); it != out_nodes.at( v ).end(); ) {
            in_nodes.at( *it ).erase( std::find( in_nodes.at( *it ).begin(), in_nodes.at( *it ).end(), v ) );
            if( in_nodes.at( *it ).size() == 0 ) {
                S.push( *it );
            }
            it = out_nodes.at( v ).erase( it );
        }       
    }

    //  Find the solution
    bool is_DAG = true;
    for( int i = 1; i <= N; i ++ ) {
        if( out_nodes.at( i ).size() != 0 ) {
            is_DAG = false;
            break;
        }
    }
    if( is_DAG ) {
        std::cout << L << std::endl;
    }
    else {
        std::cout << "-1" << std::endl;
    }

    //  Finalize
    return( 0 );
}
