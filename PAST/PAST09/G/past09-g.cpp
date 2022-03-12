/**
* @file past09-g.cpp
* @brief PAST 9 Problem G - 連結 
  @author Keitaro Naruse
* @date 2022-03-12
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_g
*/

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

const bool Debug = true;

int main()
{
    //  N = [ 2, 100 ], Q = [ 1, 10^4 ]
    int N, Q;
    std::cin >> N >> Q;
    //  c, u, v
    std::vector< int > c( Q ), u( Q ), v( Q );
    std::vector< int > U( Q ), V( Q );
    for( int i = 0; i < Q; i ++ ) {
        std::cin >> c.at( i ) >> u.at( i ) >> v.at( i );
        U.at( i ) = u.at( i ) - 1;
        V.at( i ) = v.at( i ) - 1;
    } 

    //  Main
    nrs::adj_graph g( N );
    std::vector< int > length;;
    std::queue< int > q;
    for( int i = 0; i < Q; i ++ ) {
        if( c.at( i ) == 1 ) {
            if( g.has_u_edge( U.at( i ), V.at( i ) ) ) {
                g.delete_u_edge( U.at( i ), V.at( i ) );
            }
            else {
                g.add_u_edge( U.at( i ), V.at( i ) );
            }
        }
        else {
            length = std::vector< int >( N, -1 );
            q = std::queue< int >();
            q.push( U.at( i ) );
            bool is_connected = false;
            while( !q.empty() ) {
                int k = g.next_node_bfs( q, length );
                if( k == V.at( i ) ) {
                    is_connected = true;
                    break;
                }
            }
            if( is_connected ) {
                std::cout << "Yes" << std::endl;
            }
            else {
                std::cout << "No" << std::endl;
            }
        }
    }

    return( 0 );
}
