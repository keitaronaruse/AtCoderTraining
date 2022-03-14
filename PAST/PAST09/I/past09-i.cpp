/**
* @file past09-i.cpp
* @brief PAST 9 Problem I - 直通エレベーター
  @author Keitaro Naruse
* @date 2022-03-12, 2022-03-14
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_i
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>

namespace nrs {
    template < class T >
    class undirected_graph {
        public:
        typedef std::pair< T, T > length_node_type;
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
            undirected_graph() : N( 0 ) {};
            //  Constructor with the number of nodes
            undirected_graph( int n ) : N( n ) {
                adj_nodes = std::vector< std::map< int, int > >( N );
                init_lenght();
            };
            //  Copy constructor
            undirected_graph( const undirected_graph& r ) : N( r.N ) {
                adj_nodes = r.adj_nodes; 
                length = r.length;
            };
            //  Default w = 1
            void add_weighted_edge( int u, int v, int w = 1 ) {
                adj_nodes[ u ][ v ] = w;
                adj_nodes[ v ][ u ] = w;
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
            friend std::ostream& operator<<( std::ostream& os, const undirected_graph& g ) {
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



int main()
{
    //  N = [ 2, 10^18 ]
    long long N;
    //  M = [ 1, 10^5 ]
    int M;
    std::cin >> N >> M;

    //  A, B = [ 1, N ], C = [ 1, 10^18 ]
    std::vector< long long > A( M ), B( M ), C( M ); 
    for( int i = 0; i < M; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i ) >> C.at( i );
    }

    //  Main
    int n = S.size(), m = T.size();
    std::vector< std::vector< int > > dp( n + 1, std::vector< int >( m + 1, 0 ) );
    for( int i = 1; i <= n; i ++ ) {
        for( int j = 1; j <= m; j ++ ) {
            dp.at( i ).at( j ) = std::max( 
                dp.at( i - 1 ).at( j - 1 ) + ( ( S.at( i - 1 ) == T.at( j - 1 ) ) ? 0 : 1), 
                std::max( dp.at( i ).at( j - 1 ), dp.at( i - 1 ).at( j ) )
            );
        }
    }
    std::cout << dp.at( n ).at( m ) << std::endl;

    return( 0 );
}
