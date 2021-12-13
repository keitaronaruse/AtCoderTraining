/*
    Depth First Search
        Author: Keitaro Naruse
        Date:   2021-12-13
        MIT License
*/

#include <iostream>
#include <vector>
#include <set>
#include <stack>

/*
    dfs()
    - Input
      - s, a start node id
      - g, a goal node
      - adj_nodes_set, a graph given by adjacent nodes
    - Output
      - return
        - true if s is conncted to s in the grapf of adj_nodes_set
        - false otherwise
*/
bool dfs( int s, int g, const std::vector< std::set< int > >& adj_nodes_set )
{
    //  Initialize
    int n = adj_nodes_set.size();
    std::vector< bool > visited( n, false );
    std::stack< int > visiting;

    //  Initial boundary check
    if( s == g ) {
        return( true );
    }

    //  Main
    visited.at( s ) = true;
    visiting.push( s );
    while( !visiting.empty() ) {
        int v = visiting.top();
        visiting.pop();
        for( int u : adj_nodes_set.at( v ) ) {
            if( u == g ) {
                return( true );
            }
            else if( !visited.at( u ) ) {
                visited.at( u ) = true;
                visiting.push( u );
            }
        } 
    }

    //  Finalize
    return( false );
}

/*
    print_adj_nodes_set()
    - Input
      - output stream, os
      - adj_nodes_set, a graph given by adjacent nodes
    - Output
      - print adjacent nodes to os
*/
std::ostream& print_adj_nodes_set( std::ostream& os, const std::vector< std::set< int > >& adj_nodes_set )
{
    //  Initailize
    int n = adj_nodes_set.size();

    //  Dispaly adjacent nodes
    for( int i = 0; i < n; i++ ) {
        os << i << ": ";
        for( int v : adj_nodes_set.at( i ) ) {
            std::cerr << v << " ";
        }
        os << std::endl;
    }

    //  Finalize
    return( os );
}

int main()
{
    //  Initialize
    //  Read constants
    int N = 0, M = 0;
    std::cin >> N >> M;
    //  Debug
    // std::cerr << N << " " << M << std::endl;

    //  Read Ai and Bi and store them as adjacent nodes
    std::vector< std::set< int > > adj_nodes_set( N, std::set< int >() );
    std::vector< int > degrees( N, 0 );
    for( int i = 0; i < M; i ++ ) {
        int A = 0, B = 0;
        std::cin >> A >> B;
        //  Debug
        // std::cerr << A << " " << B << std::endl;
        if( dfs( 0, N - 1, adj_nodes_set ) ) {
            std::cerr << "Connected" << std::endl;
        }
        int a = A - 1, b = B - 1;
        adj_nodes_set.at( a ).insert( b );
        adj_nodes_set.at( b ).insert( a );
        degrees.at( b ) ++;
    }

    //  Debug
    //  Dispaly degrees
    // for( int i = 0; i < N; i++ ) {
    //     std::cerr << i << ": " << degrees.at( i ) << std::endl;
    // }

    //  Main
    int S = 1, G = N;
    std::cerr << S << "-" << G << ":" << dfs( S - 1, G - 1, adj_nodes_set ) << std::endl;
    print_adj_nodes_set( std::cerr, adj_nodes_set );

    //  Finalize
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
