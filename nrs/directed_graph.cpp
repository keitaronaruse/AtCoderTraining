/**
* @file directed_graph.cpp
* @brief Class of directed graphs
* @author Keitaro Naruse
* @date 2022-01-23
* @copyright MIT License
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <utility>

namespace nrs {
    class directed_graph {
        public:
        typedef std::pair< int, int > length_node_type;
            //  The number of nodes
            int N;
            //  The adjacent nodes for each of the nodes { node, weight }
            std::vector< std::map< int, int > > adj_nodes;
            //  The length from a node and/or visited table
            std::vector< int > length;
            //  The working queue for BFS, the breadth first search
            std::queue< int > visiting_queue;
            //  The working stack for DFS, the depth first search
            std::stack< int > visiting_stack;
            //  The working priority queue for Dijkstra { length, node }
            std::priority_queue< length_node_type, 
                std::vector< length_node_type >, 
                std::greater< length_node_type > 
            > visiting_priority_queue;
        public:
            //  Default constructor
            directed_graph() : N( 0 ) {};
            //  Constructor with the number of nodes
            directed_graph( int n ) : N( n ) {
                adj_nodes = std::vector< std::map< int, int > >( N );
                init_lenght();
            };
            //  Copy constructor
            directed_graph( const directed_graph& r ) : N( r.N ) {
                adj_nodes = r.adj_nodes; 
                length = r.length;
            };
            //  Default w = 1
            void add_weighted_edge( int u, int v, int w = 1 ) {
                adj_nodes[ u ][ v ] = w;
            }
            void init_lenght() {
                length = std::vector< int >( N, -1 );
            }
            void init_visiting_queue() {
                visiting_queue = std::queue< int >( );
            }
            void init_visiting_stack() {
                visiting_stack = std::stack< int >( );
            }
            void init_visiting_priority_queue() {
                visiting_priority_queue = std::priority_queue< 
                    length_node_type, 
                    std::vector< length_node_type >, 
                    std::greater< length_node_type > 
                > ( );
            }
            //  Output operator
            friend std::ostream& operator<<( std::ostream& os, const directed_graph& g ) {
                os << g.N << std::endl;
                for( int u = 0; u < g.N; u ++ ) {
                    for( auto v_w : g.adj_nodes[ u ] ) {
                        //  u, { v, w }
                        os  << u << " " << v_w.first << " " << v_w.second << std::endl; 
                    }
                }
                return( os );
            }
            //  BFS
            int next_node_bfs( ) {
                int u = visiting_queue.front(); 
                visiting_queue.pop();
                //  Common procedure
                for( auto v_w : adj_nodes.at( u ) ) {
                    int v = v_w.first, w = v_w.second;
                    //  A new node is found
                    if( length.at( v ) == -1 ) {
                        length.at( v ) = length.at( u ) + w;
                        visiting_queue.push( v );
                    }
                    //  A smaller lenght is found in old nodes
                    else if( length.at( v ) > length.at( u ) + w ) {
                        length.at( v ) = length.at( u ) + w;
                        visiting_queue.push( v );
                    }
                }
                return( u );
            }
            //  DFS
            int next_node_dfs( ) {
                int u = visiting_stack.top(); 
                visiting_queue.pop();
                //  Common procedure
                for( auto v_w : adj_nodes.at( u ) ) {
                    int v = v_w.first, w = v_w.second;
                    //  A new node is found
                    if( length.at( v ) == -1 ) {
                        length.at( v ) = length.at( u ) + w;
                        visiting_stack.push( v );
                    }
                    //  A smaller lenght is found in old nodes
                    else if( length.at( v ) > length.at( u ) + w ) {
                        length.at( v ) = length.at( u ) + w;
                        visiting_stack.push( v );
                    }
                }
                return( u );
            }
            //  Dijkstra's algorithm
            int next_node_dijkstra( ) {
                length_node_type l_u = visiting_priority_queue.top(); 
                int l = l_u.first;
                int u = l_u.second;
                visiting_priority_queue.pop();
                //  Common procedure
                for( auto v_w : adj_nodes.at( u ) ) {
                    int v = v_w.first, w = v_w.second;
                    //  A new node is found
                    if( length.at( v ) == -1 ) {
                        length.at( v ) = length.at( u ) + w;
                        visiting_priority_queue.push( std::make_pair( length.at( v ), v ) );
                    }
                    //  A smaller lenght is found in old nodes
                    else if( length.at( v ) > length.at( u ) + w ) {
                        length.at( v ) = length.at( u ) + w;
                        //  Add the node with a new length
                        visiting_priority_queue.push( std::make_pair( length.at( v ), v ) );
                    }
                }
                return( u );
            }
    };
}

const bool Debug = true;

int main()
{
    const int N = 4;
    nrs::directed_graph g( N );
    // g.add_weighted_edge( u, v, w );
    g.add_weighted_edge( 0, 1 );
    g.add_weighted_edge( 0, 2 );
    g.add_weighted_edge( 1, 3 );
    g.add_weighted_edge( 2, 1 );
    g.add_weighted_edge( 2, 3 );
    std::cout << g;

    int b = 0, e = 3, l = 0;
    //  Find the shortest path by BFS
    g.length.at( b ) = l;
    g.visiting_queue.push( b );
    while( !g.visiting_queue.empty() ) {
        int v = g.next_node_bfs( );
        if( v == e ) {
            std::cout << g.length.at( e ) << std::endl; 
            break;
        }
    }
    for( int v = 0; v < g.N; v ++ ) {
        std::cout << g.length.at( v ) << " ";
    }
    std::cout << std::endl;

    //  Find the shortest path by Dijlstra's algorithm
    g.init_lenght();
    g.length.at( b ) = l;
    g.visiting_priority_queue.push( std::make_pair( l, b ) );
    while( !g.visiting_priority_queue.empty() ) {
        int v = g.next_node_dijkstra( );
        if( v == e ) {
            std::cout << g.length.at( e ) << std::endl; 
            break;
        }
    }
    for( int v = 0; v < g.N; v ++ ) {
        std::cout << g.length.at( v ) << " ";
    }
    std::cout << std::endl;

    return( 0 );
}
