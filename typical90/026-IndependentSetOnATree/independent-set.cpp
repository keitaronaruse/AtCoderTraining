/*
    026 - Independent Set on a Tree（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_z
        Author: Keitaro Naruse
        Date:   2022-01-05
        MIT License
*/

// # Solution

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

const bool Debug = false;

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Make a graph instance
    nrs::adj_graph g( N );
    
    //  Read A and B
    for( int i = 0; i < N - 1; i ++ ) {
        int A = 0, B = 0;
        std::cin >> A >> B;
        if( Debug ) {
            std::cerr << A << " " << B << std::endl;
        }
        A --; B --;
        g.add_edge( A, B ); g.add_edge( B, A );
    }

    //  Main
    int b = 0, e = -1;
    g.length_dfs( b, e );
    if( Debug ) {
        for( auto v : g.length ) {
            std::cerr << v << " ";
        }
        std::cerr << std::endl;
    }

    std::vector< int > even, odd;
    for( int i = 0; i < N; i ++ ) {
        if ( g.length.at( i ) % 2 == 0 ) {
            even.push_back( i );
        }
        else {
            odd.push_back( i );
        }
    }

    if( even.size() > odd.size() ) {
        for( int i = 0; i < N / 2; i ++ ) {
            std::cout << even.at( i ) + 1 << " ";
        }
        std::cout << std::endl;
    }
    else {
        for( int i = 0; i < N / 2; i ++ ) {
            std::cout << odd.at( i ) + 1 << " ";
        }
        std::cout << std::endl;
    }
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
