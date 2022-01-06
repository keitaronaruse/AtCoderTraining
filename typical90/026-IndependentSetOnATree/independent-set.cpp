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

const bool Debug = true;

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
    g.    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
