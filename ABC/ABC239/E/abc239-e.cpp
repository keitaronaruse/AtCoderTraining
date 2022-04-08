/**
* @file abc239-e.cpp
* @brief ABC239 Problem E - Subtree K-th Max
* @author Keitaro Naruse
* @date 2022-02-20, 2022-04-08
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
#include <functional>

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
            void add_d_edge( int b, int e ) {
                adj_nodes.at( b ).push_back( e );
            }
            void delete_d_edge( int b, int e ) {
                adj_nodes.at( b ).erase( 
                    std::find( adj_nodes.at( b ).begin(), adj_nodes.at( b ).end(), e ) 
                );
            }
            void add_u_edge( int b, int e ) {
                adj_nodes.at( b ).push_back( e );
                adj_nodes.at( e ).push_back( b );
            }
            void delete_u_edge( int b, int e ) {
                adj_nodes.at( b ).erase( 
                    std::find( adj_nodes.at( b ).begin(), adj_nodes.at( b ).end(), e ) 
                );
                adj_nodes.at( e ).erase( 
                    std::find( adj_nodes.at( e ).begin(), adj_nodes.at( e ).end(), b ) 
                );
            }
            bool has_d_edge( int b, int e ) {
                return( 
                    std::find( adj_nodes.at( b ).begin(), adj_nodes.at( b ).end(), e ) 
                    != adj_nodes.at( b ).end()
                );
            }
            bool has_u_edge( int b, int e ) {
                return( 
                    ( std::find( adj_nodes.at( b ).begin(), adj_nodes.at( b ).end(), e ) 
                    != adj_nodes.at( b ).end() ) &&
                    ( std::find( adj_nodes.at( e ).begin(), adj_nodes.at( e ).end(), b ) 
                    != adj_nodes.at( e ).end() )
                );
            }
            /**
             * @brief find the next node from the given stack by DFS
             * @param[in] s: working stack for DFS
             * @param[in] length: distance from a source node
             * @return v: the found next node
             */
            int next_node_dfs( std::stack< int >& s, std::vector< int >& length ) {
                int v = s.top(); 
                s.pop();
                //  Common procedure
                for( auto u : adj_nodes.at( v ) ) {
                    if( length.at( u ) == -1 ) {
                        length.at( u ) = length.at( v ) + 1;
                        s.push( u );
                    }
                    else if( length.at( u ) > length.at( v ) + 1 ) {
                        length.at( u ) = length.at( v ) + 1;
                        s.push( u );
                    }
                }
                return( v );
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
            /**
             * @brief find the next node from the given priority que by Dijkkstra's algorithm
             * @param[in] pq: working priority que stack for Dijkstra's algorithm
             * @param[in] length: distance from a source node
             * @return v: the found next node
             */
            template < class T, class Container, class Compare >
            int next_node_dijkstra( std::priority_queue< T, Container, Compare >& pq, std::vector< int >& length ) {
                int v = pq.top(); 
                pq.pop();
                //  Common procedure
                for( auto u : adj_nodes.at( v ) ) {
                    if( length.at( u ) == -1 ) {
                        length.at( u ) = length.at( v ) + 1;
                        pq.push( u );
                    }
                    else if( length.at( u ) > length.at( v ) + 1 ) {
                        length.at( u ) = length.at( v ) + 1;
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

int main()
{
    //  Read N = [ 2, 10^5 ], Q = [ 1, 10^5 ]
    int N, Q;
    std::cin >> N >> Q;

    //  Read Xi = [ 0, 10^9 ]
    std::vector< int > X( N ); 
    for( int i = 0; i < N; i ++ ) {
        std::cin >> X.at( i );
    }

    //  Read Ai, Bi = [ 1, N ]
    std::vector< int > A( N - 1 ), B( N - 1 ); 
    for( int i = 0; i < N - 1; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i );
    }

    //  Read Vj = [ 1, N ], Kj = [ 1, 20 ]
    std::vector< int > V( Q ), K( Q ); 
    for( int j = 0; j < Q; j ++ ) {
        std::cin >> V.at( j ) >> K.at( j );
    }

    //  Main
    //  Make tree
    nrs::adj_graph tree( N );
    for( int i = 0; i < N - 1; i ++ ) {
        tree.add_d_edge( A.at( i ) - 1, B.at( i ) - 1 );
    }

    //  Preprocess
    const int M = 20;
    std::vector< std::vector< int > > P( N, std::vector< int > ( M, 0 ) );
    
    std::function< int ( int ) > reccursive_trace = [ & ] ( int v ) {
        if( tree.adj_nodes.at( v ).empty() ) {
            return( X.at( v ) );
        }
        else {
            for( int u : tree.adj_nodes.at( v ) ) {
                reccursive_trace( u );
            }
        }
    };

    //  DFS
    reccursive_trace( 0 ); 

    //  Finalize
    return( 0 );
}
