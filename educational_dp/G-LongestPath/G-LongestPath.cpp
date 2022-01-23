/**
* @file G-LongestPath.cpp
* @brief G - Longest Path
* @author Keitaro Naruse
* @date 2022-01-23
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_g
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>

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
            void add_edge( int u, int v ) {
                adj_nodes[ u ][ v ] = 1;
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
std::ostream& operator<<( std::ostream& os, const std::queue< int >& r ) {
    std::queue< int > q = r;
    while( !q.empty() ) {
        os << q.front() << " ";
        q.pop();
    }
    return( os );
}
std::ostream& operator<<( std::ostream& os, const std::vector< int >& r ) {
    for( auto v : r ) {
        os << v << " ";
    }
    return( os );
}

const bool Debug = false; 

int main()
{
    //  Read N = [ 2, 10^5 ] and M = [ 1, 10^5 ]
    int N = 0, M = 0;
    std::cin >> N >> M;
    if( Debug ) {
        std::cerr << N << " " << M << std::endl;
    }
    //  Read x = [ 1, N ] and y = [ 1, N ]
    std::vector< int > x( M ), y( M );
    for( int j = 0; j < M ; j ++ ) {
        std::cin >> x.at( j ) >> y.at( j );
        x.at( j ) --;
        y.at( j ) --;
    }
    if( Debug ) {
        for( int j = 0; j < M ; j ++ ) {
            std::cout << x.at( j ) + 1 << " " << y.at( j ) + 1 << std::endl;
        }
    }

    //  Main
    //  Make a graph instance
    nrs::directed_graph g( N );
    //  Make degree tables
    std::vector< int > in_degree( N, 0 ), out_degree( N , 0 );
    //  Update the graph instance and the degree tables
    for( int j = 0; j < M; j ++ ) {
        g.add_edge( x.at( j ), y.at( j ) );
        out_degree.at( x.at( j ) ) ++;
        in_degree.at( y.at( j ) ) ++;
    } 

    //  Add starting nodes to a visiting queue and set their path lengths
    for( int i = 0; i < N; i ++ ) {
        if( in_degree.at( i ) == 0 ) {
            g.visiting_queue.push( i );
            g.length.at( i ) = 0;
        }
    }
    if( Debug ) {
        std::cerr << g.visiting_queue << std::endl;
    }

    while( !g.visiting_queue.empty() ) {
        int v = g.visiting_queue.front();
        for( auto p : g.adj_nodes.at( v ) ) {
            int u = p.first;
            if( g.length.at( u ) == -1 ) {
                g.length.at( u ) = g.length.at( v ) + 1;
                g.visiting_queue.push( u );                ;
            }
        }
        g.visiting_queue.pop();
        if( Debug ) {
            std::cerr << g.visiting_queue << std::endl;
        }
    }
    if( Debug ) {
        std::cerr << g.length << std::endl;
    }
    //  Find the solution
    int longest_length = 0;
    for( int i = 0; i < N; i ++ ) {
        longest_length = std::max( longest_length, g.length.at( i ) );
    }
    std::cout << longest_length << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
