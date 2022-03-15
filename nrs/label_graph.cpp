/**
* @file label_graph.cpp
* @brief The class of a graph structure by adjacent nodes
* @author Keitaro Naruse
* @date 2022-03-15
* @copyright MIT License
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

/*
    test driver
*/
int main()
{
    typedef long long Label;
    typedef long long Weight;

    nrs::label_graph< Label, Weight > g;

    g.add_edge(  2L,  5L,  1L );
    g.add_edge(  4L, 10L,  3L );
    g.add_edge(  1L,  2L,  1L );
    g.add_edge(  1L,  2L,  1L );
    g.add_edge(  2L,  4L,  2L );
    g.add_edge(  5L, 10L,  5L );
    g.add_edge(  4L,  5L,  2L );
    g.add_edge(  5L, 10L,  5L );
    g.add_edge(  5L, 10L,  5L );

    g.add_edge(  1L, 10L,  10L );
    std::cerr << g.has_edge( 1L, 10L ) << std::endl;

    g.delete_edge(  1L, 10L );
    std::cerr << g.has_edge( 1L, 10L ) << std::endl;

    g.init_length();
    
    g.print_weighted_edges( std::cerr );
    g.print_lengths( std::cerr );

    std::cerr << "Normally terminated." << std::endl;
    return( 0 ); 
}