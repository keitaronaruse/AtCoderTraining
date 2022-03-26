/**
* @file ahc009-a-2.cpp
* @brief AHC009 Problem A - Robust Memory of Commuting Routes
* @author Keitaro Naruse
* @date 2022-03-26
* @copyright MIT License
* @details https://atcoder.jp/contests/ahc009/tasks/ahc009_a
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <random>
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
            int_graph( int N, Weight INF ) : n( N ), inf( INF ) {
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
            void add_edge( Node u, Node v, Weight w = Weight( 1 ) ) {
                weight.at( u ).push_back( std::make_pair( v, w ) );
                weight.at( v ).push_back( std::make_pair( u, w ) );
            }
            bool has_edge( Node u, Node v ) {
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
            void delete_edge( Node u, Node v ) {
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

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > >& vv )
{
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return( os );
}

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Constant
    const int N = 20;
    //  Read si, sj, = [ 0, 4 ], ti, tj = [ 15, 19 ]
    int si, sj, ti, tj;
    std::cin >> si >> sj >> ti >> tj;
    //  Read p = [ 0.1, 0.5 ]
    double p;
    std::cin >> p;

    //  Read hij = [ 0, 1 ]
    std::vector< std::vector< int > > h( N, std::vector< int >( N - 1, 0 ) ); 
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N - 1; j ++ ) {
            char c;
            std::cin >> c;
            h.at( i ).at( j ) = c - '0';
        }
    }
    //  Read vij = [ 0, 1 ]
    std::vector< std::vector< int > > v( N - 1, std::vector< int >( N, 0 ) ); 
    for( int i = 0; i < N - 1; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            char c;
            std::cin >> c;
            v.at( i ).at( j ) = c - '0';
        }
    }

    //  Make a graph instance
    nrs::int_graph< int > g( N * N, 1000000007 );

    //  h walls
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N - 1; j ++ ) {
            if( h.at( i ).at( j ) == 0 ) {
                g.add_edge( i * N + j, i * N + j + 1 );
            }
        }
    }
    //  v walls
    for( int i = 0; i < N - 1; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            if( v.at( i ).at( j ) == 0 ) {
                g.add_edge( i * N + j, ( i + 1 ) * N + j );
            }
        }
    }

    //  Main
    //  Find the shortest path
    g.find_path_bfs( si * N + sj, ti * N + tj );
    std::vector< int > path = g.back_trace( si * N + sj, ti * N + tj );

    int k = 0, K = 200;
    std::string actions( K, 'R' );
    for( ; k < ( int ) path.size() - 1; k ++ ) {
        switch( path.at( k + 1 ) - path.at( k ) ) {
            case -1: actions.at( k ) = 'L'; break;
            case  1: actions.at( k ) = 'R'; break;
            case -N: actions.at( k ) = 'U'; break;
            case  N: actions.at( k ) = 'D'; break;
        }
    }
    for( ; k < K; k ++ ) {
         switch( k % 4 ) {
            case 0: actions.at( k ) = 'R'; break;
            case 1: actions.at( k ) = 'D'; break;
            case 2: actions.at( k ) = 'L'; break;
            case 3: actions.at( k ) = 'U'; break;
            default: break;
        }
    }

    std::cout << actions << std::endl;

    //  Finalize
    return( 0 );
}
