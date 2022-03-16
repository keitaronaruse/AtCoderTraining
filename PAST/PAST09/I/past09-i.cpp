/**
* @file past09-i.cpp
* @brief PAST 9 Problem I - 直通エレベーター
  @author Keitaro Naruse
* @date 2022-03-12, 2022-03-15
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
    //  L: label type, W: weight type
    template < class Label, class Weight >
    class set_graph {
        private:
            typedef std::pair< Weight, Label > W_L;
            //  A weight of an edge, weight[ u ][ v ] = w 
            std::map< Label, std::map< Label, Weight > > weight;
            //  A path length from a certain node, length[ u ] = l 
            std::map< Label, Weight > length;
            //  A previous node used in the dijkstra algorithm
            std::map< Label, Label > prev_node;
            //  A proproty queue for the dijkstra algorithm pq = ( w, u )
            std::deque< W_L > pq;
        public:
            set_graph() : weight( std::map< Label, std::map< Label, Weight > >() )  {}
            set_graph( const set_graph& r ) {
                weight = r.weight;
                length = r.length;
            }
            void add_edge( const Label& u, const Label& v, Weight w = Weight( 1 ) ) {
                weight[ u ][ v ] = w;
                weight[ v ][ u ] = w;
            }
            void delete_edge( const Label& u, const Label& v ) {
                weight.at( u ).erase( weight.at( u ).find( v ) );
                weight.at( v ).erase( weight.at( v ).find( u ) );
            }
            bool has_edge( const Label& u, const Label& v ) const {
                if( weight.count( u ) != 0 && weight.at( u ).count( v ) != 0 
                    && weight.count( v ) != 0 && weight.at( v ).count( u ) != 0 ) {
                    return( true );
                }
                return( false );
            }
            Weight weight_edge( const Label& u, const Label& v ) const {
                return( weight.at( u ).at( v ) ) ;
            }
            void init_length() {
                length.clear();
                for( const auto& p : weight ) {
                    length[ p.first ] = Weight( -1 );
                }
            }
            void init_prev_node() {
                prev_node.clear();
                for( const auto& p : weight ) {
                    prev_node[ p.first ] = p.first;
                }
            }
            std::ostream& print_weighted_edges( std::ostream& os ) const {
                for( const auto& p : weight ) {
                    const Label& u = p.first;
                    for( const auto& q : p.second ) {
                        const Label& v = q.first;
                        const Weight& w = q.second;
                        os << "( " << u << ", " << v << ", " << w << " ) ";
                    }
                }
                os << std::endl;
                return( os );
            }
            std::ostream& print_lengths( std::ostream& os ) const {
                for( const auto& p : length ) {
                    os << "( " << p.first << ", " << p.second << " ) ";     
                }
                os << std::endl;
                return( os );
            }
            std::ostream& print_prev_nodes( std::ostream& os ) const {
                for( const auto& p : prev_node ) {
                    os << "( " << p.first << ", " << p.second << " ) ";     
                }
                os << std::endl;
                return( os );
            }
            /**
             * @brief find the shortest path from b to e by Dijkkstra's algorithm
             * @param[in] b: a start node
             * @param[in] e: a goal node
             * @return w: the distance from b to e, returns -1 if a path is not found 
             */
            Weight find_shortest_path_dijkstra( const Label& b, const Label& e ) {
                init_length();
                init_prev_node();

                length.at( b ) = Weight( 0 );
                prev_node.at( b ) = Label();
                pq.push_back( std::make_pair( Weight( 0 ), b ) );

                while( !pq.empty() ) {
                    std::sort( pq.begin(), pq.end() );
                    const Weight& w = pq.front().first;
                    const Label& v = pq.front().second;
                    pq.pop_front();

                    //  Goal check
                    if( v == e ) {
                        return( length.at( v ) );
                    }
                    //  Add a node to priority que
                    for( const auto& q : weight.at( v ) ) {
                        const Label& u = q.first;
                        const Weight& w = q.second; 
                        if( length.at( u ) == Weight( -1 ) ) {
                            length.at( u ) = length.at( v ) + w;
                            prev_node.at( u ) = v;
                            pq.push_back( std::make_pair( length.at( u ), u ) );
                        }
                        else if( length.at( u ) > length.at( v ) + w ) {
                            length.at( u ) = length.at( v ) + w;
                            prev_node.at( u ) = v;
                            for( auto& w_l : pq ) {
                                if( w_l.second == u ) {
                                    w_l.first = length.at( u );
                                }
                            }
                        }
                    }
                }
                return( Weight( -1 ) ); 
            }
            std::deque< Label > back_trace( const Label& b, const Label& e ) const {
                std::deque< Label > path;
                Label v = e;
                while( v != b ) {
                    path.push_front( v );
                    v = prev_node.at( v );
                }
                path.push_front( b );
                return( path );
            }
    };
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::deque< T >& v )
{
    for( const auto& e : v ) {
        os << e << " ";
    }
    return( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& e : v ) {
        os << e << " ";
    }
    return( os );
}

const long long INF = 1000000000000000001L;

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
    std::vector< long long > nodes;
    nodes.reserve( 2 * M + 2 );
    nodes.push_back( 1L );
    nodes.push_back( N );
    for( int i = 0; i < M; i ++ ) {
        // g.add_edge( A.at( i ), B.at( i ), C.at( i ) );
        nodes.push_back( A.at( i ) );
        nodes.push_back( B.at( i ) );
    }
    std::sort( nodes.begin(), nodes.end() );
    nodes.erase( std::unique( nodes.begin(), nodes.end() ), nodes.end() );

    const int V = ( int ) nodes.size();
    std::vector< std::vector< std::pair< int, long long > > > graph( V );
    for( int i = 0; i < V - 1; i ++ ) {
        long long w = nodes.at( i + 1 ) - nodes.at( i );
        graph.at( i ).push_back( std::make_pair( i + 1, w ) );
        graph.at( i + 1 ).push_back( std::make_pair( i, w ) );
    }
    for( int i = 0; i < M; i ++ ) {
        const int u = std::lower_bound( nodes.begin(), nodes.end(), A.at( i ) ) - nodes.begin();
        const int v = std::lower_bound( nodes.begin(), nodes.end(), B.at( i ) ) - nodes.begin();
        graph.at( u ).push_back( std::make_pair( v, C.at( i ) ) );
        graph.at( v ).push_back( std::make_pair( u, C.at( i ) ) );
    }

    std::vector< long long > dist( V, INF );
    std::priority_queue< 
        std::pair< long long, int >, 
        std::vector< std::pair< long long, int > >, 
        std::greater< std::pair< long long, int > > 
    > heap;
    const auto push = [&]( const int u, const long long d ) {
        if( dist.at( u ) > d ) {
            dist.at( u ) = d;
            heap.push( std::make_pair( d, u ) );
        }
    };
    push( 0, 0 );
    while( !heap.empty() ) {
        const auto p = heap.top();
        const long long d = p.first;
        const int u = p.second;
        heap.pop();
        if( dist.at( u ) < d ) {
            continue;
        }
        for( const auto& q : graph.at( u )  ) {
            const int v = q.first;
            const long long c = q.second;
            push( v, d + c );
        }
    }
    std::cout << dist.at( V - 1 ) << std::endl;

    // nrs::set_graph< long long, long long > g;
    // for( int j = 0; j < ( int ) nodes.size() - 1; j ++ ) {
    //     if( nodes.at( j ) != nodes.at( j + 1 ) ) {
    //         long long w = nodes.at( j + 1 ) - nodes.at( j );
    //         if( !g.has_edge( nodes.at( j ), nodes.at( j  + 1) ) 
    //             || w < g.weight_edge( nodes.at( j ), nodes.at( j + 1) )
    //         )  {
    //             g.add_edge( nodes.at( j ), nodes.at( j + 1 ), w );
    //         }
    //     }
    // }
    // std::cout << g.find_shortest_path_dijkstra( 1, N ) << std::endl;

    return( 0 );
}
