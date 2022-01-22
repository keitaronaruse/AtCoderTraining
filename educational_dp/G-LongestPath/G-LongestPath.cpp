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
#include <algorithm>

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
    nrs::adj_graph g( N );
    //  Make degree tables
    std::vector< int > in_degree( N, 0 ), out_degree( N , 0 );
    //  ;
    for( int j = 0; j < M; j ++ ) {
        g.add_d_edge( x.at( j ), y.at( j ) );
        out_degree.at( x.at( j ) ) ++;
        in_degree.at( y.at( j ) ) ++;
    } 
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << i << ": ";
            for( auto v : g.adj_nodes.at( i ) ) {
                std::cout << v << " ";
            }
            std::cerr  
                << "In: " << in_degree.at( i ) << ", "
                << "Out: " << out_degree.at( i ) << std::endl;
        }
    }
    //  DP principle: DP matching
    //  DP table: 
    //  - size: M * N = 3*10^3 * 3*10^3 = 9*10^6
    //  - value: min( N, M ) = 3*10^3 -> int
    
    //  Main::Initialize
    //  DP table: 
    std::vector< std::vector< int > > dp_length( M + 1, std::vector< int >( N + 1, 0 ) ); 

    //  Initial boundary condition

    //  Main::Loop

    //  Main::Finalize
    //  Display the result

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
