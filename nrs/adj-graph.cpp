/*
    nrs::adj_graph
        The class of a graph structure by adjacent nodes 
        Author: Keitaro Naruse
        Date:   2021-12-31, 2022-01-12
        MIT License
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

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
                    }
                }
                if( e == -1 ) {
                    e = max_node;
                }
                return( length.at( e ) );
            }
            /*
                next_node_dfs()
                    returns the next node of DFS from the give stack and length
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
            /*
                next_node_bfs()
                    returns the next node of BFS from the give queue and length
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
    };
}

int hw2id( int h, int w, int W )
{
    return( h * W + w );
}

void id2hw( int id, int& h, int& w, int W )
{
    w = id % W;
    h = ( id - w )  / W;
}

const bool Debug = true;

//  Test driver
int main()
{
    //  An example of a graph
    //   012345
    //  0.#..#.
    //  1......
    //  2.#..#.
    const int H = 3;
    const int W = 6;
    const int N = hw2id( H - 1, W - 1, W ) + 1;
    
    //  Make a graph instance
    nrs::adj_graph g( N );
    g.add_u_edge( hw2id( 0, 0, W ), hw2id( 1, 0, W ) ); 
    g.add_u_edge( hw2id( 1, 0, W ), hw2id( 2, 0, W ) ); 
    g.add_u_edge( hw2id( 1, 0, W ), hw2id( 1, 1, W ) ); 
    g.add_u_edge( hw2id( 1, 1, W ), hw2id( 1, 2, W ) );
    g.add_u_edge( hw2id( 1, 2, W ), hw2id( 0, 2, W ) ); 
    g.add_u_edge( hw2id( 1, 2, W ), hw2id( 2, 2, W ) );
    g.add_u_edge( hw2id( 0, 2, W ), hw2id( 0, 3, W ) ); 
    g.add_u_edge( hw2id( 1, 2, W ), hw2id( 1, 3, W ) );
    g.add_u_edge( hw2id( 2, 2, W ), hw2id( 2, 3, W ) ); 
    g.add_u_edge( hw2id( 0, 3, W ), hw2id( 1, 3, W ) ); 
    g.add_u_edge( hw2id( 2, 3, W ), hw2id( 1, 3, W ) ); 
    g.add_u_edge( hw2id( 1, 3, W ), hw2id( 1, 4, W ) ); 
    g.add_u_edge( hw2id( 1, 4, W ), hw2id( 1, 5, W ) ); 
    g.add_u_edge( hw2id( 1, 5, W ), hw2id( 0, 5, W ) ); 
    g.add_u_edge( hw2id( 1, 5, W ), hw2id( 2, 5, W ) ); 
    
    //  Test edges
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << i << ": ";
            for( int v : g.adj_nodes.at( i ) ) {
                std::cerr << v << " ";
            }
            std::cerr << std::endl;
        }
    }
    //  Make graph utilities
    std::vector< int > length;
    int b = 0, e = 0;

    //  BFS
    //  BFS: Setup
    length = std::vector< int > ( N, -1 );
    std::queue< int > q;
    //  BFS: Initial node
    b = hw2id( 0, 0, W ); e = hw2id( 2, 5, W ); 
    length.at( b ) = 0;
    q.push( b );
    //  BFS: Main
    std::cerr << "BFS: ";
    while( !q.empty() ) {
        int v = g.next_node_bfs( q, length );
        id2hw( v, b, e, W );
        std::cerr << "( " << b << ", " << e << " )" << " ";
    }
    std::cerr << std::endl;
    for( auto d : length ) {
        std::cerr << d << " ";
    }
    std::cerr << std::endl;

//  0 -1  4  5 -1  7
//  1  2  3  4  5  6
//  2 -1  4  5 -1  7 

    //  DFS
    //  DFS: Setup
    // std::vector< int > length( N, -1 );
    // std::stack< int > s;
    //  DFS: Initial node
    // int b = 0; 
    // length.at( b ) = 0;
    // s.push( b );
    //  DFS: Main
    // std::cerr << "DFS: ";
    // while( !s.empty() ) {
    //     int v = g.next_node_dfs( s, length );
    //     std::cerr << v << " ";
    // }
    // std::cerr << std::endl;
    
    
    //  Variables
    // int length = 0, b = 0, e = 0;
    
    //  Find a path lenght from b to e by DFS
    // b = 0; e = 0; length = g.length_dfs( b, e );
    // std::cerr << "DFS: Length from " << b << " to " << e << " is " << length << std::endl; 
    // b = 0; e = 1; length = g.length_dfs( b, e );
    // std::cerr << "DFS: Length from " << b << " to " << e << " is " << length << std::endl; 
    // b = 0; e = 2; length = g.length_dfs( b, e );
    // std::cerr << "DFS: Length from " << b << " to " << e << " is " << length << std::endl; 

    //  Find a path lenght from b to e by BFS
    // b = 0; e = 0; length = g.length_bfs( b, e );
    // std::cerr << "BFS: Length from " << b << " to " << e << " is " << length << std::endl; 
    // b = 0; e = 1; length = g.length_bfs( b, e );
    // std::cerr << "BFS: Length from " << b << " to " << e << " is " << length << std::endl; 
    // b = 0; e = 2; length = g.length_bfs( b, e );
    // std::cerr << "BFS: Length from " << b << " to " << e << " is " << length << std::endl; 

    //  Find the farest node and its path lenght by DFS
    // b = 0; e = -1; length = g.length_dfs( b, e );
    // std::cerr << "DFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 
    // b = 1; e = -1; length = g.length_dfs( b, e );
    // std::cerr << "DFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 
    // b = 2; e = -1; length = g.length_dfs( b, e );
    // std::cerr << "DFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 

    //  Find the farest node and its path lenght by BFS
    // b = 0; e = -1; length = g.length_bfs( b, e );
    // std::cerr << "BFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 
    // b = 1; e = -1; length = g.length_bfs( b, e );
    // std::cerr << "BFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 
    // b = 2; e = -1; length = g.length_bfs( b, e );
    // std::cerr << "BFS: Farest node from " << b << " is " << e << " with a lenght of  " << length << std::endl; 

    return( 0 );
}
