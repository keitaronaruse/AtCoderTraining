/*
    nrs::adj_graph
        The class of a graph structure by adjacent nodes 
        returns the absolute value of the arugument, implmented by template
        Author: Keitaro Naruse
        Date:   2021-12-31
        MIT License
*/

#include <iostream>
#include <vector>
#include <set>

namespace nrs {
    class adj_graph {
        public:
            adj_graph() : n( 0 ) {
                adj_nodes = std::vector< std::set< int > >();
            };
            adj_graph( int N ) : n( N ) {
                adj_nodes = std::vector< std::set< int > >( N );
            };
            adj_graph( const adj_graph& r ) : n( r.n ) {
                adj_nodes = r.adj_nodes;
            }
            void add_edge( int b, int e ) {
                adj_nodes.at( b ).insert( e );
            }
            bool has_edge( int b, int e ) {
                return( ( bool ) adj_nodes.at( b ).count( e ) );
            }
        public:
            int n;
            std::vector< std::set< int > > adj_nodes;
    };
}

//  Test driver
int main()
{
    nrs::adj_graph g( 3 );

    std::cerr << "Add the edge( 0, 1 )" << std::endl;
    g.add_edge( 0, 1 );
    
    std::cerr << "Add the edge( 1, 2 )" << std::endl;
    g.add_edge( 1, 2 );

    std::cerr << "Has the edge( 0, 1 )? " 
    << g.has_edge( 0, 1 ) << std::endl;

    std::cerr << "Has the edge( 1, 2 )? " 
    << g.has_edge( 1, 2 ) << std::endl;

    std::cerr << "Has the edge( 2, 0 )? " 
    << g.has_edge( 2, 0 ) << std::endl;

    return( 0 );
}
