/*
    026 - Independent Set on a Tree（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_z
        Author: Keitaro Naruse
        Date:   2022-01-05
        MIT License
*/

// # Solution
// - Make a tree and sweep a tree by DFS
// - Assign an alternative color in a found order

#include <iostream>
#include <vector>
#include <stack>

class color_tree  {
public:
    int n;
    std::vector< std::vector< int > > adj_nodes;
    std::vector< int > length;
    std::vector< int > even, odd;
public:
    color_tree( int N ) : n( N ) {
        adj_nodes = std::vector< std::vector< int > >( N );
    }
    void add_edge( int b, int e ) {
        adj_nodes.at( b ).push_back( e );
    }
    void color_dfs( int b ) {
        std::stack< int > s;
        length = std::vector< int >( n, -1 );
        
        length.at( b ) = 0;
        even.push_back( b );
        s.push( b );
        while( !s.empty() ) {
            int v = s.top(); 
            s.pop();
            //  Common procedure
            for( auto u : adj_nodes.at( v ) ) {
                if( length.at( u ) == -1 ) {
                    length.at( u ) = ( length.at( v ) + 1 ) % 2;
                    if( length.at( u ) == 0 ) {
                        even.push_back( u );
                    }
                    else {
                        odd.push_back( u );
                    }
                    s.push( u );
                }
            }
        }
    }
};

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
    color_tree t( N );
    
    //  Read A and B
    for( int i = 0; i < N - 1; i ++ ) {
        int A = 0, B = 0;
        std::cin >> A >> B;
        if( Debug ) {
            std::cerr << A << " " << B << std::endl;
        }
        A --; B --;
        t.add_edge( A, B ); 
        t.add_edge( B, A );
    }

    //  Main
    int b = 0;
    t.color_dfs( b );
    
    if( Debug ) {
        for( auto v : t.length ) {
            std::cerr << v << " ";
        }
        std::cerr << std::endl;
        for( auto v : t.even ) {
            std::cerr << v << " ";
        }
        std::cerr << std::endl;
        for( auto v : t.odd ) {
            std::cerr << v << " ";
        }
        std::cerr << std::endl;
    }

    //  Display results
    if( t.even.size() > t.odd.size() ) {
        for( int i = 0; i < N / 2; i ++ ) {
            std::cout << t.even.at( i ) + 1 << " ";
        }
        std::cout << std::endl;
    }
    else {
        for( int i = 0; i < N / 2; i ++ ) {
            std::cout << t.odd.at( i ) + 1 << " ";
        }
        std::cout << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
