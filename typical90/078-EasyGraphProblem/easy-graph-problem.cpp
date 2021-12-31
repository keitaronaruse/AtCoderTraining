/*
    078 - Easy Graph Problem（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_bz
        Author: Keitaro Naruse
        Date:   2021-12-02, 2021-12-31
        MIT License
*/

// # Solution
// - Store adjacent nodes of all of the given nodes as an unordered graph

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

const bool Debug = false;

int main()
{
    //  Read N and M
    int N = 0, M = 0;
    std::cin >> N >> M;
    if( Debug ) {
        std::cerr << N << " " << M << std::endl;
    }

    //  Read ai and bi
    nrs::adj_graph g( N );
    for( int i = 0; i < M; i ++ ) {
        int a = 0, b = 0;
        std::cin >> a >> b;
        if( Debug ) {
            std::cerr << a << " " << b << std::endl;
        }
        a --;
        b --;
        //  Since a bidirectional edge is given, add an adjacent node to the both nodes
        g.add_edge( a, b );
        g.add_edge( b, a );
    }
    
    //  Main
    int num_satisfied_nodes = 0;
    for( int i = 0; i < N; i ++ ) {
        int num_smaller_nodes = 0;
        std::set< int >::iterator b = g.adj_nodes.at( i ).begin();
        std::set< int >::iterator e = g.adj_nodes.at( i ).lower_bound( i );
        while( b != e ) {
            b ++;
            num_smaller_nodes ++;
        }
        if( num_smaller_nodes == 1 ) {
            num_satisfied_nodes ++;
        } 
    }

    //  Display result
    std::cout << num_satisfied_nodes << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
