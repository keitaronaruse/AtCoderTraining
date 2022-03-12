/**
* @file adj_graph.cpp
* @brief The class of a graph structure by adjacent nodes
* @author Keitaro Naruse
* @date 2021-12-31, 2022-03-12
* @copyright MIT License
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

const bool Debug = true;

//  Test driver
int main()
{
    const int N = 4;
    
    //  Make a graph instance
    nrs::adj_graph g( N );
    g.add_u_edge(  0,  1 ); 
    g.add_u_edge(  1,  2 ); 
    g.add_u_edge(  2,  3 ); 
    
    //  Make graph utilities
    std::vector< int > length;
    int b = 0, e = 0;

    //  BFS
    //  BFS: Setup
    length = std::vector< int > ( N, -1 );
    std::queue< int > q;
    //  BFS: Initial node
    b = 0; e = 3; 
    length.at( b ) = 0;
    q.push( b );
    //  BFS: Main
    bool is_connected = false;
    while( !q.empty() ) {
        int v = g.next_node_bfs( q, length );
        if( v == e ) {
            is_connected = true;
        }
    }
    if( is_connected ) {
        std::cerr << b << " is connected to " << e << std::endl;
    }
    else {
        std::cerr << b << " is not connected to " << e << std::endl;
    }

    g.delete_u_edge(  2,  3 ); 
    //  BFS: Setup
    length = std::vector< int > ( N, -1 );
    q = std::queue< int >();
    //  BFS: Initial node
    b = 0; e = 3; 
    length.at( b ) = 0;
    q.push( b );
    //  BFS: Main
    is_connected = false;
    while( !q.empty() ) {
        int v = g.next_node_bfs( q, length );
        if( v == e ) {
            is_connected = true;
        }
    }
    if( is_connected ) {
        std::cerr << b << " is connected to " << e << std::endl;
    }
    else {
        std::cerr << b << " is not connected to " << e << std::endl;
    }

    return( 0 );
}
