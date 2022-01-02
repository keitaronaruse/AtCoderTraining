/*
    nrs::adj_graph
        The class of a graph structure by adjacent nodes 
        Author: Keitaro Naruse
        Date:   2021-12-31
        MIT License
*/

#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>

namespace nrs {
    class adj_graph {
        public:
            adj_graph() : n( 0 ) {
                adj_nodes = std::vector< std::set< int > >();
            }
            adj_graph( int N ) : n( N ) {
                adj_nodes = std::vector< std::set< int > >( N );
            }
            adj_graph( const adj_graph& r ) : n( r.n ) {
                adj_nodes = r.adj_nodes;
            }
            void add_edge( int b, int e ) {
                adj_nodes.at( b ).insert( e );
            }
            bool has_edge( int b, int e ) {
                return( ( bool ) adj_nodes.at( b ).count( e ) );
            }
            int length_dfs( int b, int e ) {
                std::stack< int > s;
                std::vector< int > length( n, -1 );
                
                length.at( b ) = 0;
                s.push( b );
                while( !s.empty() ) {
                    int v = s.top();
                    s.pop();
                    if( v == e ) {
                        break;
                    }
                    else {
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
                    }
                }
                return( length.at( e ) );
            }
            int length_bfs( int b, int e ) {
                std::queue< int > s;
                std::vector< int > length( n, -1 );
                
                length.at( b ) = 0;
                s.push( b );
                while( !s.empty() ) {
                    int v = s.front();
                    s.pop();
                    if( v == e ) {
                        break;
                    }
                    else {
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
                    }
                }
                return( length.at( e ) );
            }
            int find_longest_path_from_bfs( int b, int& e ) {
                std::queue< int > s;
                std::vector< int > length( n, -1 );
                int max_length = -1;

                max_length = length.at( b ) = 0;
                e = b;
                s.push( b );
                while( !s.empty() ) {
                    int v = s.front();
                    s.pop();
                    if( max_length < length.at( v ) ) {
                        max_length = length.at( v );
                        e = v;
                    }

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
                }
                return( length.at( e ) );
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

    std::cerr << "Add the edge ( 0, 1 )" << std::endl;
    g.add_edge( 0, 1 ); g.add_edge( 1, 0 );
    std::cerr << "Add the edge ( 1, 2 )" << std::endl;
    g.add_edge( 1, 2 ); g.add_edge( 2, 1 );

    std::cerr << "Length of ( 0, 0 ) by DFS: " << g.length_dfs( 0, 0 ) << std::endl;
    std::cerr << "Length of ( 0, 0 ) by BFS: " << g.length_bfs( 0, 0 ) << std::endl;
    std::cerr << "Length of ( 0, 1 ) by DFS: " << g.length_dfs( 0, 1 ) << std::endl;
    std::cerr << "Length of ( 0, 1 ) by BFS: " << g.length_bfs( 0, 1 ) << std::endl;
    std::cerr << "Length of ( 0, 2 ) by DFS: " << g.length_dfs( 0, 2 ) << std::endl;
    std::cerr << "Length of ( 0, 2 ) by BFS: " << g.length_bfs( 0, 2 ) << std::endl;

    int length = 0, e = 0;
    length = g.find_longest_path_from_bfs( 0, e );
    std::cerr << "Longest node from ( 0 ) by BFS: " << e << " with " << length << std::endl;
    length = g.find_longest_path_from_bfs( 1, e );
    std::cerr << "Longest node from ( 1 ) by BFS: " << e << " with " << length << std::endl;
    length = g.find_longest_path_from_bfs( 2, e );
    std::cerr << "Longest node from ( 2 ) by BFS: " << e << " with " << length << std::endl;

    std::cerr << "Add the edge ( 0, 2 )" << std::endl;
    g.add_edge( 0, 2 ); g.add_edge( 2, 0 );

    std::cerr << "Length of ( 0, 0 ) by DFS: " << g.length_dfs( 0, 0 ) << std::endl;
    std::cerr << "Length of ( 0, 0 ) by BFS: " << g.length_bfs( 0, 0 ) << std::endl;
    std::cerr << "Length of ( 0, 1 ) by DFS: " << g.length_dfs( 0, 1 ) << std::endl;
    std::cerr << "Length of ( 0, 1 ) by BFS: " << g.length_bfs( 0, 1 ) << std::endl;
    std::cerr << "Length of ( 0, 2 ) by DFS: " << g.length_dfs( 0, 2 ) << std::endl;
    std::cerr << "Length of ( 0, 2 ) by BFS: " << g.length_bfs( 0, 2 ) << std::endl;

    length = g.find_longest_path_from_bfs( 0, e );
    std::cerr << "Longest node from ( 0 ) by BFS: " << e << " with " << length << std::endl;
    length = g.find_longest_path_from_bfs( 1, e );
    std::cerr << "Longest node from ( 1 ) by BFS: " << e << " with " << length << std::endl;
    length = g.find_longest_path_from_bfs( 2, e );
    std::cerr << "Longest node from ( 2 ) by BFS: " << e << " with " << length << std::endl;

    return( 0 );
}
