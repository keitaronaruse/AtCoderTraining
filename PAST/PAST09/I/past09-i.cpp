/**
* @file past09-i.cpp
* @brief PAST 9 Problem I - 直通エレベーター
  @author Keitaro Naruse
* @date 2022-03-12, 2022-03-16
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_i
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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
        private:
            int n;
            Weight inf;
            //  { v, w } = weight.at( u ).at( k )
            std::vector< std::vector< Node_Weight > > weight;
            //  A path length from a certain node, l = length.at( u )
            std::vector< Weight > length;
            //  A previous node used in the dijkstra algorithm, v = prev_node.at( u )
            std::vector< Node > prev_node;
            //  A proproty queue for the dijkstra algorithm p_que = ( w, u )
            std::priority_queue< 
                Weight_Node, 
                std::vector< Weight_Node >,
                std::greater< Weight_Node >
            > p_que;
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
            Weight find_shortest_path_dijkstra( Node b, Node e ) {
                init_lengths();
                init_prev_nodes();

                length.at( b ) = Weight( 0 );
                prev_node.at( b ) = Node( -1 );
                p_que.push( std::make_pair( length.at( b ), b ) );

                while( !p_que.empty() ) {
                    auto p = p_que.top(); 
                    Weight d = p.first;
                    Node u = p.second;
                    p_que.pop();

                    //  When an edge with a larger weight is expanded, skip it
                    if( length.at( u ) < d ) {
                        continue;
                    }
                    //  Add a node to priority que
                    for( auto q : weight.at( u ) ) {
                        Node v = q.first;
                        Weight c = q.second;
                        if( length.at( v ) > d + c ) {
                            length.at( v ) = d + c;
                            prev_node.at( v ) = u;
                            p_que.push( std::make_pair( length.at( v ), v ) );
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

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& e : v ) {
        os << e << " ";
    }
    return( os );
}

int main()
{
    //  Constant
    const long long INF = 1000000000000000001L;

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
    //  Preprocess of nodes
    std::vector< long long > nodes;
    nodes.reserve( 2 * M + 2 );
    nodes.push_back( 1L );
    nodes.push_back( N );
    for( int i = 0; i < M; i ++ ) {
        nodes.push_back( A.at( i ) );
        nodes.push_back( B.at( i ) );
    }
    std::sort( nodes.begin(), nodes.end() );
    nodes.erase( std::unique( nodes.begin(), nodes.end() ), nodes.end() );

    //  Make a graph instance
    const int V = ( int ) nodes.size();
    nrs::int_graph< long long > g( V, INF );
    for( int i = 0; i < V - 1; i ++ ) {
        long long w = nodes.at( i + 1 ) - nodes.at( i );
        g.add_edge( i, i + 1, w );
    }
    for( int i = 0; i < M; i ++ ) {
        int u = std::lower_bound( nodes.begin(), nodes.end(), A.at( i ) ) - nodes.begin();
        int v = std::lower_bound( nodes.begin(), nodes.end(), B.at( i ) ) - nodes.begin();
        g.add_edge( u, v, C.at( i ) );
    }
    std::cout << g.find_shortest_path_dijkstra( 0, V - 1 ) << std::endl;
    for( auto k : g.back_trace( 0, V - 1 ) ) {
        std::cout << nodes.at( k ) << " ";
    }
    std::cout << std::endl;

    return( 0 );
}
