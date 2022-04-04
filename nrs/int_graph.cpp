/**
* @file int_graph.cpp
* @brief class nrs::int_graph
  @author Keitaro Naruse
* @date 2022-03-18, 2022-04-04
* @copyright MIT License
* @details 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>

namespace nrs {
    template < class Weight >
    class int_graph {
        public:
            typedef int Node;
            typedef std::pair< Weight, int > Weight_Node;
            typedef std::pair< int, Weight > Node_Weight;
        public:
            int n;
            Weight inf;
            //  { v, w } = weight.at( u ).at( k )
            std::vector< std::vector< Node_Weight > > weight;
            //  A path length from a certain node, l = length.at( u )
            std::vector< Weight > length;
            //  A previous node used in the dijkstra algorithm, v = prev_node.at( u )
            std::vector< Node > prev_node;
            //  A queue for the breadth first search
            std::queue< Node > bfs_queue;
            //  A stack for the depth first search
            std::stack< Node > dfs_stack;
            //  A proproty queue for the dijkstra algorithm ( w, u )
            std::priority_queue< 
                Weight_Node, 
                std::vector< Weight_Node >,
                std::greater< Weight_Node >
            > dijkstra_queue;
        public:
            int_graph() : n( 0 ) {}
            int_graph( int N, Weight INF = 1000000007 ) : n( N ), inf( INF ) {
                init_weights();
                init_lengths();
                init_prev_nodes();
            }
            int_graph( const int_graph< Weight >& r ) {
                weight = r.weight;
                length = r.length;
                prev_node = r.prev_node;
            }
            void init_weights() {
                weight = std::vector< std::vector< Node_Weight > >( n );
            }
            void init_lengths() {
                length = std::vector< Weight > ( n, inf );
            }
            void init_prev_nodes() {
                prev_node = std::vector< Node > ( n, -1 );
            }
            void init_bfs_queue() {
                bfs_queue = std::queue< Node > ( );
            }
            void init_dfs_stack() {
                dfs_stack = std::stack< Node > ( );
            }
            void init_dijkstra_priority_queue()
            {
                dijkstra_queue = std::priority_queue< Weight_Node, std::vector< Weight_Node >, std::greater< Weight_Node > > ();
            }
            void add_u_edge( Node u, Node v, Weight w = Weight( 1 ) ) {
                weight.at( u ).push_back( std::make_pair( v, w ) );
                weight.at( v ).push_back( std::make_pair( u, w ) );
            }
            bool has_u_edge( Node u, Node v ) {
                for( const auto& p : weight.at( u ) ) {
                    if( p.first == v ) {
                        for( const auto& q : weight.at( v ) ) {
                            if( q.first == u ) {
                                return( true );
                            }
                        }
                    }
                }
                return( false );
            }
            void delete_u_edge( Node u, Node v ) {
                for( auto it = weight.at( u ).begin(); it < weight.at( u ).end(); it ++  ) {
                    if( *it.first == v ) {
                        weight.at( u ).erase( it );
                    }
                }
                for( auto it = weight.at( v ).begin(); it < weight.at( v ).end(); it ++  ) {
                    if( *it.first == u ) {
                        weight.at( v ).erase( it );
                    }
                }
            }
            void add_d_edge( Node u, Node v, Weight w = Weight( 1 ) ) {
                weight.at( u ).push_back( std::make_pair( v, w ) );
            }
            bool has_d_edge( Node u, Node v ) {
                for( const auto& p : weight.at( u ) ) {
                    if( p.first == v ) {
                        return( true );
                    }
                }
                return( false );
            }
            void delete_d_edge( Node u, Node v ) {
                for( auto it = weight.at( u ).begin(); it < weight.at( u ).end(); it ++  ) {
                    if( *it.first == v ) {
                        weight.at( u ).erase( it );
                    }
                }
            }
            std::ostream& print_edges( std::ostream& os ) const {
                for( int u = 0; u < weight.size(); u ++ ) {
                    for( auto q : weight.at( u ) ) {
                        int v = q.first;
                        Weight w = q.second;
                        os << "( " << u << ", " << v << ", " << w << " ) ";
                    }
                }
                os << std::endl;
                return( os );
            }
            Weight find_path_bfs( Node b, Node e ) {
                init_lengths();
                init_prev_nodes();
                init_bfs_queue();

                length.at( b ) = Weight( 0 );
                prev_node.at( b ) = Node( -1 );
                bfs_queue.push( b );

                while( !bfs_queue.empty() ) {
                    auto u = bfs_queue.front(); 
                    bfs_queue.pop();

                    //  Add a node to queue
                    for( auto q : weight.at( u ) ) {
                        Node v = q.first;
                        Weight w = q.second;
                        if( length.at( v ) == inf ) {
                            length.at( v ) = length.at( u ) + w;
                            prev_node.at( v ) = u;
                            bfs_queue.push( v );
                        }
                    }
                }
                return( length.at( e ) ); 
            }
            void init_next_bfs( Node b ) {
                init_lengths();
                init_prev_nodes();
                init_bfs_queue();
                length.at( b ) = Weight( 0 );
                prev_node.at( b ) = Node( -1 );
                bfs_queue.push( b );
            }
            Node find_next_bfs() {
                if( !bfs_queue.empty() ) {
                    auto u = bfs_queue.front(); 
                    bfs_queue.pop();

                    //  Add a node to queue
                    for( auto q : weight.at( u ) ) {
                        Node v = q.first;
                        Weight w = q.second;
                        if( length.at( v ) == inf ) {
                            length.at( v ) = length.at( u ) + w;
                            prev_node.at( v ) = u;
                            bfs_queue.push( v );
                        }
                    }
                    return( u );
                }
                return( Node( -1 ) ); 
            }
            Weight find_path_dfs( Node b, Node e ) {
                init_lengths();
                init_prev_nodes();
                init_dfs_stack();

                length.at( b ) = Weight( 0 );
                prev_node.at( b ) = Node( -1 );
                dfs_stack.push( b );

                while( !dfs_stack.empty() ) {
                    auto u = dfs_stack.top(); 
                    dfs_stack.pop();

                    //  Add a node to queue
                    for( auto q : weight.at( u ) ) {
                        Node v = q.first;
                        Weight w = q.second;
                        if( length.at( v ) == inf ) {
                            length.at( v ) = length.at( u ) + w;
                            prev_node.at( v ) = u;
                            dfs_stack.push( v );
                        }
                    }
                }
                return( length.at( e ) ); 
            }
            void init_next_dfs( Node b ) {
                init_lengths();
                init_prev_nodes();
                init_dfs_stack();

                length.at( b ) = Weight( 0 );
                prev_node.at( b ) = Node( -1 );
                dfs_stack.push( b );
            }
            Node find_next_dfs() {
                if( !dfs_stack.empty() ) {
                    auto u = dfs_stack.top(); 
                    dfs_stack.pop();

                    //  Add a node to queue
                    for( auto q : weight.at( u ) ) {
                        Node v = q.first;
                        Weight w = q.second;
                        if( length.at( v ) == inf ) {
                            length.at( v ) = length.at( u ) + w;
                            prev_node.at( v ) = u;
                            dfs_stack.push( v );
                        }
                    }
                    return( u );
                }
                return( Node( -1 ) ); 
            }
            Weight find_path_dijkstra( Node b, Node e ) {
                init_lengths();
                init_prev_nodes();
                init_dijkstra_priority_queue();

                length.at( b ) = Weight( 0 );
                prev_node.at( b ) = Node( -1 );
                dijkstra_queue.push( std::make_pair( length.at( b ), b ) );

                while( !dijkstra_queue.empty() ) {
                    auto p = dijkstra_queue.top(); 
                    Weight d = p.first;
                    Node u = p.second;
                    dijkstra_queue.pop();

                    //  When a node ( d, u ) in the priority que should be expanded
                    if( length.at( u ) >= d ) {
                        //  Add a node to priority que
                        for( auto q : weight.at( u ) ) {
                            Node v = q.first;
                            Weight c = q.second;
                            if( length.at( v ) > d + c ) {
                                length.at( v ) = d + c;
                                prev_node.at( v ) = u;
                                dijkstra_queue.push( std::make_pair( length.at( v ), v ) );
                            }
                        }
                    }
                }
                return( length.at( e ) ); 
            }
            void init_next_dijkstra( Node b ) {
                init_lengths();
                init_prev_nodes();
                init_dijkstra_priority_queue();

                length.at( b ) = Weight( 0 );
                prev_node.at( b ) = Node( -1 );
                dijkstra_queue.push( std::make_pair( length.at( b ), b ) );
            }
            Node find_next_dijkstra() {
                if( !dijkstra_queue.empty() ) {
                    auto p = dijkstra_queue.top(); 
                    Weight d = p.first;
                    Node u = p.second;
                    dijkstra_queue.pop();

                    //  When a node ( d, u ) in the priority que should be expanded
                    if( length.at( u ) >= d ) {
                        //  Add a node to priority que
                        for( auto q : weight.at( u ) ) {
                            Node v = q.first;
                            Weight c = q.second;
                            if( length.at( v ) > d + c ) {
                                length.at( v ) = d + c;
                                prev_node.at( v ) = u;
                                dijkstra_queue.push( std::make_pair( length.at( v ), v ) );
                            }
                        }
                    }
                    return( u );
                }
                return( Node( -1 ) ); 
            }
            std::vector< Node > back_trace( Node b, Node e ) {
                std::vector< Node > path;
                Node v = e;
                while( v != b ) {
                    path.push_back( v );
                    v = prev_node.at( v );
                }
                path.push_back( b );
                std::reverse( path.begin(), path.end() );
                return( path );
            }
    };
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) 
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Const
    const int inf = 1000000007;
    //  N = [ 2, 2 * 10^5 ]
    int N = 3;

    //  Main
    //  Preprocess
    nrs::int_graph< int > g( N, inf );
    g.add_u_edge( 0, 1, 1 );
    g.add_u_edge( 1, 2, 1 );
    g.add_u_edge( 2, 0, 1 );
    std::cout << g.find_path_bfs( 0, 2 ) << std::endl;
    std::cout << g.back_trace( 0, 2 ) << std::endl;

    return( 0 );
}
