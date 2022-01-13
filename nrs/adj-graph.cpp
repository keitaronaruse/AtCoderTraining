/*
    nrs::adj_graph
        The class of a graph structure by adjacent nodes 
        Author: Keitaro Naruse
        Date:   2021-12-31, 2022-01-12
        MIT License
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
            void add_u_edge( int b, int e ) {
                adj_nodes.at( b ).push_back( e );
                adj_nodes.at( e ).push_back( b );
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
    };
}

const bool Debug = true;

//  Test driver
int main()
{
    //  An example of a graph
    //   0  #  2  3  #  5
    //   6  7  8  9 10 11
    //  12  # 14 15  # 17
    const int N = 18;
    
    //  Make a graph instance
    nrs::adj_graph g( N );
    g.add_u_edge(  0,  6 ); 
    g.add_u_edge(  2,  3 ); 
    g.add_u_edge(  2,  8 ); 
    g.add_u_edge(  3,  9 ); 
    g.add_u_edge(  5, 11 ); 
    g.add_u_edge(  6,  7 ); 
    g.add_u_edge(  6, 12 ); 
    g.add_u_edge(  7,  8 ); 
    g.add_u_edge(  8,  9 ); 
    g.add_u_edge(  8, 14 ); 
    g.add_u_edge(  9, 10 ); 
    g.add_u_edge(  9, 15 ); 
    g.add_u_edge( 10, 11 ); 
    g.add_u_edge( 11, 17 ); 
    
    //  Test edges
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << i << ": ";
            for( int v : g.adj_nodes.at( i ) ) {
                std::cerr << v << " ";
            }
            std::cerr << std::endl;
        }
    }
    //  Make graph utilities
    std::vector< int > length;
    int b = 0, e = 0;

    //  BFS
    //  BFS: Setup
    length = std::vector< int > ( N, -1 );
    std::queue< int > q;
    //  BFS: Initial node
    b = 0; e = 15; 
    length.at( b ) = 0;
    q.push( b );
    //  BFS: Main
    std::cerr << "BFS: ";
    while( !q.empty() ) {
        int v = g.next_node_bfs( q, length );
        if( Debug ) {
            std::cerr << v << " ";
        }
    }
    if( Debug ) {
        std::cerr << std::endl;
    }
    if( Debug ) {
        for( auto d : length ) {
            std::cerr << d << " ";
        }
        std::cerr << std::endl;
    }
    // BFS: 0 6 7 12 8 2 9 14 3 10 15 11 5 17
    //   0  #  2  3  #  5
    //   6  7  8  9 10 11
    //  12  # 14 15  # 17

    //  Length
    //  0 -1  4  5 -1  7 
    //  1  2  3  4  5  6 
    //  2 -1  4  5 -1  7 
    
    //  DFS
    //  DFS: Setup
    length = std::vector< int > ( N, -1 );
    std::stack< int > s;
    //  DFS: Initial node
    b = 0; 
    length.at( b ) = 0;
    s.push( b );
    //  DFS: Main
    std::cerr << "DFS: ";
    while( !s.empty() ) {
        int v = g.next_node_dfs( s, length );
        if( Debug ) {
            std::cerr << v << " ";
        }
    }
    if( Debug ) {
        std::cerr << std::endl;
    }
    if( Debug ) {
        for( auto d : length ) {
            std::cerr << d << " ";
        }
        std::cerr << std::endl;
    }
    // DFS: 0 6 12 7 8 14 9 15 10 11 17 5 3 2 
    //   0  #  2  3  #  5
    //   6  7  8  9 10 11
    //  12  # 14 15  # 17

    //  Length
    // 0 -1  4  5 -1 7 
    // 1  2  3  4  5 6 
    // 2 -1  4  5 -1 7 
    
    //  Dijkstra
    //  Dijkstra: Setup
    length = std::vector< int > ( N, -1 );
    auto comp = [ & length ]( int a, int b ) { 
        return( length.at( a ) > length.at( b ) ); 
    }; 
    std::priority_queue< 
        int, 
        std::vector< int >, 
        decltype( comp ) 
    > pq( comp );

    //  Dijkstra: Initial node
    b = 0; 
    length.at( b ) = 0;
    pq.push( b );
    for( int v : g.adj_nodes.at( b ) ) {
        length.at( v ) = length.at( b ) + 1 ;
        pq.push( v );
    }

    while( !pq.empty() ) {
        int v = pq.top();
        g.adj_nodes.at( v );
        std::cerr << "( " << v << ", " << length.at( v ) << " )" << " ";
        pq.pop();
    }
    std::cerr << std::endl;

    return( 0 );
}
