/*
    026 - Independent Set on a Tree（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_z
        Author: Keitaro Naruse
        Date:   2022-01-05, 2022-01-06
        MIT License
*/

// # Solution
// - Make a tree and sweep a tree by DFS
// - Assign an alternative color in a found order

#include <iostream>
#include <vector>
#include <stack>

namespace nrs {
    class adj_graph {
        public:
            int n;
            std::vector< std::vector< int > > adj_nodes;
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
            void add_edge( int b, int e ) {
                adj_nodes.at( b ).push_back( e );
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
        g.add_edge( A, B ); 
        g.add_edge( B, A );
    }

    //  Main
    //  DFS: Setup
    std::vector< int > length( N, -1 );
    std::stack< int > s;
    std::vector< int > even, odd;
    //  DFS: Initial node
    int b = 0; 
    length.at( b ) = 0;
    s.push( b );
    //  DFS: Main
    while( !s.empty() ) {
        int v = g.next_node_dfs( s, length );
        length.at( v ) %= 2;
        if( length.at( v ) == 0 ) {
            even.push_back( v );
        }
        else {
            odd.push_back( v );
        }
    }
    
    if( Debug ) {
        for( auto v : length ) {
            std::cerr << v << " ";
        }
        std::cerr << std::endl;
        for( auto v : even ) {
            std::cerr << v + 1 << " ";
        }
        std::cerr << std::endl;
        for( auto v : odd ) {
            std::cerr << v + 1 << " ";
        }
        std::cerr << std::endl;
    }

    //  Display results
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
