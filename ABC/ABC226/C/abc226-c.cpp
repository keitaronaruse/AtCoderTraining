/**
* @file abc226-c.cpp
* @brief ABC226 Problem C - Martial artist
* @author Keitaro Naruse
* @date 2022-04-01, 2022-04-03
* @copyright MIT License
* @details https://atcoder.jp/contests/abc226/tasks/abc226_c
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
template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) 
{
    for( const auto& k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 2*10^5 ]
    int N;
    std::cin >> N;
    //  Read Ti = [ 1, 10^9 ], Ki = [ 1, N ], Aij = [ 1, i ]
    std::vector< int > T( N ), K( N );
    std::vector< std::vector< int > > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> T.at( i ) >> K.at( i );
        A.at( i ) = std::vector< int >( K.at( i ) );
        for( int j = 0; j < K.at( i ); j ++ ) {
            std::cin >> A.at( i ).at( j );
        }
    } 

    //  Main
    nrs::adj_graph g( N );
    for( int i = N - 1; i >= 0; i -- ) {
        for( int j = 0; j < K.at( i ); j ++ ) {
            g.add_d_edge( i, A.at( i ).at( j ) - 1 );
        }
    }

    long long sum = 0L;
    std::vector< int >length = std::vector< int > ( N, -1 );
    std::queue< int > q;
    //  BFS: Initial node
    length.at( N - 1 ) = 0;
    q.push( N - 1 );
    //  BFS: Main
    while( !q.empty() ) {
        int v = g.next_node_bfs( q, length );
        sum += T.at( v );
    }
    std::cout << sum << std::endl;

    //  Finalize
    return( 0 );
}
