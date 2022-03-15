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
    class label_graph {
        private:
            std::map< Label, std::map< Label, Weight > > weight;
            std::map< Label, Weight > length;
        public:
            label_graph() : weight( std::map< Label, std::map< Label, Weight > >() )  {}
            label_graph( const label_graph& r ) {
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
                    length[ p.first ] = Weight( 0 );
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
    nrs::label_graph< long long, long long > g;
    std::vector< long long > nodes;
    nodes.push_back( 1L );
    nodes.push_back( N );
    for( int i = 0; i < M; i ++ ) {
        g.add_edge( A.at( i ), B.at( i ), C.at( i ) );
        nodes.push_back( A.at( i ) );
        nodes.push_back( B.at( i ) );
    }
    g.print_weighted_edges( std::cerr );

    std::sort( nodes.begin(), nodes.end() );
    for( int j = 0; j < ( int ) nodes.size() - 1; j ++ ) {
        if( nodes.at( j ) != nodes.at( j + 1 ) ) {
            long long w = nodes.at( j + 1 ) - nodes.at( j );
            if( !g.has_edge( nodes.at( j ), nodes.at( j  + 1) ) 
                || w < g.weight_edge( nodes.at( j ), nodes.at( j + 1) )
            )  {
                g.add_edge( nodes.at( j ), nodes.at( j + 1 ), w );
            }
        }
    }
    g.print_weighted_edges( std::cerr );

    return( 0 );
}
