/**
* @file abc239-e.cpp
* @brief ABC239 Problem E - Subtree K-th Max
* @author Keitaro Naruse
* @date 2022-02-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc239/tasks/abc239_e
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>

namespace nrs {
    class adj_graph {
        public:
            int n;
            std::vector< std::vector< int > > adj_nodes;
            std::vector< int > length;
        public:
            adj_graph() : n( 0 ) {
                adj_nodes = std::vector< std::vector< int > >();
            }
            adj_graph( int N ) : n( N ) {
                adj_nodes = std::vector< std::vector< int > >( n );
            }
            adj_graph( const adj_graph& r ) : n( r.n ) {
                adj_nodes = r.adj_nodes;
            }
            void add_u_edge( int b, int e ) {
                adj_nodes.at( b ).push_back( e );
                adj_nodes.at( e ).push_back( b );
            }
            /**
             * @brief find the next node from the stack by BFS
             * @param[in] s: working queue for BFS
             * @param[in] length: distance from a source node
             * @return v: the found next node
             */
            int next_node_bfs( std::queue< int >& s, std::vector< int >& length ) {
                int v = s.front(); 
                s.pop();
                //  Common procedure
                for( auto u : adj_nodes.at( v ) ) {
                    if( length.at( u ) == -1 ) {
                        length.at( u ) = length.at( v ) + 1;
                        s.push( u );
                    }
                }
                return( v );
            }
            int next_node_deeper( std::queue< int >& s, const std::vector< int >& length ) {
                int v = s.front(); s.pop();
                //  Common procedure
                for( auto u : adj_nodes.at( v ) ) {
                    if( length.at( u ) > length.at( v ) ) {
                        s.push( u );
                    }
                }
                return( v );
            }
    };
}

std::ostream& operator<<( std::ostream& os, const std::vector< int >& v ) 
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

const bool Debug = false;

int main()
{
    //  Read N = [ 2, 10^5 ], Q = [ 1, 10^5 ]
    int N = 0, Q = 0;
    std::cin >> N >> Q;
    if( Debug ) {
        std::cerr << N << " " << Q << std::endl;
    }

    //  Read Xi = [ 0, 10^9 ]
    std::vector< int > X( N, -1 ); 
    for( int i = 0; i < N; i ++ ) {
        std::cin >> X.at( i );
    }
    if( Debug ) {
        std::cerr << X << std::endl;
    }

    //  Read Ai, Bi = [ 1, N ]
    std::vector< int > A( N - 1, -1 ), B( N - 1, -1 ); 
    for( int i = 0; i < N - 1; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N - 1; i ++ ) {
            std::cerr << A.at( i ) << " " << B.at( i ) << std::endl;
        }
    }

    //  Read Vj = [ 1, N ], Kj = [ 1, 20 ]
    std::vector< int > V( Q, -1 ), K( Q, -1 ); 
    for( int j = 0; j < Q; j ++ ) {
        std::cin >> V.at( j ) >> K.at( j );
    }
    if( Debug ) {
        for( int j = 0; j < Q; j ++ ) {
            std::cerr << V.at( j ) << " " << K.at( j ) << std::endl;
        }
    }

    //  Main
    //  Make tree
    nrs::adj_graph tree( N );
    for( int i = 0; i < N - 1; i ++ ) {
        tree.add_u_edge( A.at( i ) - 1, B.at( i ) - 1 );
    }
    //  Find the distance from the root to each of the nodes 
    std::vector< int > length( N, -1 );
    std::queue< int > s;
    s.push( 0 ); length.at( 0 ) = 0;
    while( !s.empty() ) {
        int v = tree.next_node_bfs( s, length );
    }
    
    //  Queries
    for( int j = 0; j < Q; j ++ ) {
        std::vector< int > l;
        std::queue< int > s;
        s.push( V.at( j ) - 1 );
        while( !s.empty() ) {
            int v = tree.next_node_deeper( s, length );
            l.push_back( X.at( v ) );
        }
        std::sort( l.begin(), l.end(), std::greater< int >{} );
        if( Debug ) {
            std::cerr << l << std::endl;
        }
        std::cout << l.at( K.at( j ) - 1 ) << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
