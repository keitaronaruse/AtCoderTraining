/*
    003 - Longest Circular Road（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_c
        Author: Keitaro Naruse
        Date:   2022-01-02, 2021-01-03
        MIT License
*/

// # Solution
// - Find a diameter of a given graph, 
// - by finding the longest path from b to u, then u to e

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

const bool Debug = false;

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Make an insatnce of the given graph
    nrs::adj_graph g( N );
    
    //  Read A and B
    std::vector< int > A( N ), B( N );
    for( int i = 0; i < N - 1; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i );
        if( Debug ) {
            std::cerr << A.at( i ) << " " << B.at( i ) << std::endl;
        }
        A.at( i ) --;
        B.at( i ) --;
        g.add_edge( A.at( i ), B.at( i ) );
        g.add_edge( B.at( i ), A.at( i ) );
    }

    //  Main
    int diameter = 0, b = 0, e = 0;
    diameter = g.find_longest_path_from_bfs( b, e );
    if( Debug ) {
        std::cerr << "from " << b << " to " << e << " by " << diameter << std::endl;
    } 
    diameter = g.find_longest_path_from_bfs( e, b );
    if( Debug ) {
        std::cerr << "from " << e << " to " << b << " by " << diameter << std::endl;
    } 
    //  Display result
    std::cout << diameter + 1 << std::endl; 

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
