/*
    nrs::adj_graph
        The class of a graph structure by adjacent nodes 
        Author: Keitaro Naruse
        Date:   2021-12-31, 2022-01-06
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
            /*
                length_dfs()
                    returns a path length from b to e by the depth first search
                    if e == -1, stores the farset node from b in e and returns the diameter
            */
            int length_dfs( int b, int& e ) {
                std::stack< int > s;
                length = std::vector< int >( n, -1 );
                int max_length = length.at( b ) = 0;
                int max_node = e;
                
                s.push( b );
                while( !s.empty() ) {
                    int v = s.top(); s.pop();
                    //  Mode of finding a path length from b to the farest node e
                    if( e == -1 ) {
                        if( max_length < length.at( v ) ) {
                            max_length = length.at( v );
                            max_node = v;
                        }
                    }
                    //  Mode of finding a path length from b to e
                    else {
                        if( v == e ) {
                            break;
                        }
                    }
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
                }
                if( e == -1 ) {
                    e = max_node;
                }
                return( length.at( e ) );
            }
            /*
                length_bfs()
                    returns a path length from b to e by the breadth first search
                    if e == -1, stores the farset node from b in e and returns the diameter
            */
            int length_bfs( int b, int& e ) {
                std::queue< int > s;
                length = std::vector< int >( n, -1 );
                int max_length = length.at( b ) = 0;
                int max_node = e;
                
                s.push( b );
                while( !s.empty() ) {
                    int v = s.front(); s.pop();
                    //  Mode of finding a path length from b to the farest node e
                    if( e == -1 ) {
                        if( max_length < length.at( v ) ) {
                            max_length = length.at( v );
                            max_node = v;
                        }
                    }
                    //  Mode of finding a path length from b to e
                    else {
                        if( v == e ) {
                            break;
                        }
                    }
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
                }
                if( e == -1 ) {
                    e = max_node;
                }
                return( length.at( e ) );
            }
        public:
            int n;
            std::vector< std::set< int > > adj_nodes;
            std::vector< int > length;
    };
}

//  Test driver
int main()
{
    nrs::adj_graph g( 3 );

    //  Make a graph
    std::cerr << "Add the edge ( 0, 1 )" << std::endl;
    g.add_edge( 0, 1 ); g.add_edge( 1, 0 );
    std::cerr << "Add the edge ( 1, 2 )" << std::endl;
    g.add_edge( 1, 2 ); g.add_edge( 2, 1 );

    //  Variables
    int length = 0, b = 0, e = 0;
    
    //  Find a path lenght from b to e by DFS
    b = 0; e = 0; length = g.length_dfs( b, e );
    std::cerr << "DFS: Length from " << b << " to " << e << " is " << length << std::endl; 
    b = 0; e = 1; length = g.length_dfs( b, e );
    std::cerr << "DFS: Length from " << b << " to " << e << " is " << length << std::endl; 
    b = 0; e = 2; length = g.length_dfs( b, e );
    std::cerr << "DFS: Length from " << b << " to " << e << " is " << length << std::endl; 

    //  Find a path lenght from b to e by BFS
    b = 0; e = 0; length = g.length_bfs( b, e );
    std::cerr << "BFS: Length from " << b << " to " << e << " is " << length << std::endl; 
    b = 0; e = 1; length = g.length_bfs( b, e );
    std::cerr << "BFS: Length from " << b << " to " << e << " is " << length << std::endl; 
    b = 0; e = 2; length = g.length_bfs( b, e );
    std::cerr << "BFS: Length from " << b << " to " << e << " is " << length << std::endl; 

    //  Find the farest node and its path lenght by DFS
    b = 0; e = -1; length = g.length_dfs( b, e );
    std::cerr << "DFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 
    b = 1; e = -1; length = g.length_dfs( b, e );
    std::cerr << "DFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 
    b = 2; e = -1; length = g.length_dfs( b, e );
    std::cerr << "DFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 

    //  Find the farest node and its path lenght by BFS
    b = 0; e = -1; length = g.length_bfs( b, e );
    std::cerr << "BFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 
    b = 1; e = -1; length = g.length_bfs( b, e );
    std::cerr << "BFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 
    b = 2; e = -1; length = g.length_bfs( b, e );
    std::cerr << "BFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 

    //  Modify the graph
    std::cerr << "Add the edge ( 0, 2 )" << std::endl;
    g.add_edge( 0, 2 ); g.add_edge( 2, 0 );

    //  Find a path lenght from b to e by DFS
    b = 0; e = 0; length = g.length_dfs( b, e );
    std::cerr << "DFS: Length from " << b << " to " << e << " is " << length << std::endl; 
    b = 0; e = 1; length = g.length_dfs( b, e );
    std::cerr << "DFS: Length from " << b << " to " << e << " is " << length << std::endl; 
    b = 0; e = 2; length = g.length_dfs( b, e );
    std::cerr << "DFS: Length from " << b << " to " << e << " is " << length << std::endl; 

    //  Find a path lenght from b to e by BFS
    b = 0; e = 0; length = g.length_bfs( b, e );
    std::cerr << "BFS: Length from " << b << " to " << e << " is " << length << std::endl; 
    b = 0; e = 1; length = g.length_bfs( b, e );
    std::cerr << "BFS: Length from " << b << " to " << e << " is " << length << std::endl; 
    b = 0; e = 2; length = g.length_bfs( b, e );
    std::cerr << "BFS: Length from " << b << " to " << e << " is " << length << std::endl; 

    //  Find the farest node and its path lenght by DFS
    b = 0; e = -1; length = g.length_dfs( b, e );
    std::cerr << "DFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 
    b = 1; e = -1; length = g.length_dfs( b, e );
    std::cerr << "DFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 
    b = 2; e = -1; length = g.length_dfs( b, e );
    std::cerr << "DFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 

    //  Find the farest node and its path lenght by BFS
    b = 0; e = -1; length = g.length_bfs( b, e );
    std::cerr << "BFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 
    b = 1; e = -1; length = g.length_bfs( b, e );
    std::cerr << "BFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 
    b = 2; e = -1; length = g.length_bfs( b, e );
    std::cerr << "BFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 

    return( 0 );
}
