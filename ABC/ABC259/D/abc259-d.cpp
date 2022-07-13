/**
 * @file abc259-d.cpp
 * @brief ABC259 Problem D - Circumferences
 * @author Keitaro Naruse
 * @date 2022-07-09
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc259/tasks/abc259_d
 */

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
    adj_graph( ) : n( 0 ) { adj_nodes = std::vector< std::vector< int > >( ); }
    adj_graph( int N ) : n( N ) {
        adj_nodes = std::vector< std::vector< int > >( n );
    }
    adj_graph( const adj_graph& r ) : n( r.n ) { adj_nodes = r.adj_nodes; }
    void add_d_edge( int b, int e ) { adj_nodes.at( b ).push_back( e ); }
    void delete_d_edge( int b, int e ) {
        adj_nodes.at( b ).erase( std::find( adj_nodes.at( b ).begin( ),
                                            adj_nodes.at( b ).end( ), e ) );
    }
    void add_u_edge( int b, int e ) {
        adj_nodes.at( b ).push_back( e );
        adj_nodes.at( e ).push_back( b );
    }
    void delete_u_edge( int b, int e ) {
        adj_nodes.at( b ).erase( std::find( adj_nodes.at( b ).begin( ),
                                            adj_nodes.at( b ).end( ), e ) );
        adj_nodes.at( e ).erase( std::find( adj_nodes.at( e ).begin( ),
                                            adj_nodes.at( e ).end( ), b ) );
    }
    bool has_d_edge( int b, int e ) {
        return ( std::find( adj_nodes.at( b ).begin( ),
                            adj_nodes.at( b ).end( ),
                            e ) != adj_nodes.at( b ).end( ) );
    }
    bool has_u_edge( int b, int e ) {
        return (
            ( std::find( adj_nodes.at( b ).begin( ), adj_nodes.at( b ).end( ),
                         e ) != adj_nodes.at( b ).end( ) ) &&
            ( std::find( adj_nodes.at( e ).begin( ), adj_nodes.at( e ).end( ),
                         b ) != adj_nodes.at( e ).end( ) ) );
    }
    /**
     * @brief find the next node from the given stack by DFS
     * @param[in] s: working stack for DFS
     * @param[in] length: distance from a source node
     * @return v: the found next node
     */
    int next_node_dfs( std::stack< int >& s, std::vector< int >& length ) {
        int v = s.top( );
        s.pop( );
        //  Common procedure
        for( auto u : adj_nodes.at( v ) ) {
            if( length.at( u ) == -1 ) {
                length.at( u ) = length.at( v ) + 1;
                s.push( u );
            } else if( length.at( u ) > length.at( v ) + 1 ) {
                length.at( u ) = length.at( v ) + 1;
                s.push( u );
            }
        }
        return ( v );
    }
    /**
     * @brief find the next node from the stack by BFS
     * @param[in] s: working queue for BFS
     * @param[in] length: distance from a source node
     * @return v: the found next node
     */
    int next_node_bfs( std::queue< int >& s, std::vector< int >& length ) {
        int v = s.front( );
        s.pop( );
        //  Common procedure
        for( auto u : adj_nodes.at( v ) ) {
            if( length.at( u ) == -1 ) {
                length.at( u ) = length.at( v ) + 1;
                s.push( u );
            }
        }
        return ( v );
    }
    /**
     * @brief find the next node from the given priority que by Dijkkstra's
     * algorithm
     * @param[in] pq: working priority que stack for Dijkstra's algorithm
     * @param[in] length: distance from a source node
     * @return v: the found next node
     */
    template < class T, class Container, class Compare >
    int next_node_dijkstra( std::priority_queue< T, Container, Compare >& pq,
                            std::vector< int >& length ) {
        int v = pq.top( );
        pq.pop( );
        //  Common procedure
        for( auto u : adj_nodes.at( v ) ) {
            if( length.at( u ) == -1 ) {
                length.at( u ) = length.at( v ) + 1;
                pq.push( u );
            } else if( length.at( u ) > length.at( v ) + 1 ) {
                length.at( u ) = length.at( v ) + 1;
            }
        }
        return ( v );
    }
};
}  // namespace nrs

int main( ) {
    //  Read N = [ 1, 3*10^3 ]
    int N;
    std::cin >> N;
    //  Read sx, sy, tx. ty = [-10^9, 10^9]
    double sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;
    //  Read xi, yi, ri = [ 0, 10^9 ]
    std::vector< double > x( N ), y( N ), r( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> x.at( i ) >> y.at( i ) >> r.at( i );
    }

    //  Main
    //  Make a graph instance
    nrs::adj_graph g( N );
    for( int i = 0; i < N; i++ ) {
        for( int j = i + 1; j < N; j++ ) {
            double d2 = std::pow( x.at( i ) - x.at( j ), 2.0 ) +
                        std::pow( y.at( i ) - y.at( j ), 2.0 );
            if( std::pow( r.at( i ) - r.at( j ), 2.0 ) <= d2 &&
                d2 <= std::pow( r.at( i ) + r.at( j ), 2.0 ) ) {
                g.add_u_edge( i, j );
            }
        }
    }
    //  source and sink
    std::vector< int > idx_s_circles, idx_t_circles;
    for( int i = 0; i < N; i++ ) {
        if( std::pow( sx - x.at( i ), 2.0 ) + std::pow( sy - y.at( i ), 2.0 ) ==
            std::pow( r.at( i ), 2.0 ) ) {
            idx_s_circles.push_back( i );
        }
        if( std::pow( tx - x.at( i ), 2.0 ) + std::pow( ty - y.at( i ), 2.0 ) ==
            std::pow( r.at( i ), 2.0 ) ) {
            idx_t_circles.push_back( i );
        }
    }

    bool isYes = false;
    for( auto b : idx_s_circles ) {
        for( auto e : idx_t_circles ) {
            //  Make graph utilities
            std::vector< int > length;
            //  BFS
            //  BFS: Setup
            length = std::vector< int > ( N, -1 );
            std::queue< int > q;
            //  BFS: Initial node
            length.at( b ) = 0;
            q.push( b );
            //  BFS: Main
            bool is_connected = false;
            while( !q.empty() ) {
                // int v = g.next_node_bfs( q, length );
                int v = g.next_node_dijkstra( q, length );

                if( v == e ) {
                    is_connected = true;
                }
            }
            if( is_connected ) {
                isYes = true;
                break;
            }
        }
    }
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return ( 0 );
}
