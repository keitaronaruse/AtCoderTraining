/*
    ABC231 Problem D - Neighbors
        https://atcoder.jp/contests/abc231/tasks/abc231_d
        Author: Keitaro Naruse
        Date:   2021-12-11
        MIT License
*/

#include <iostream>
#include <vector>
#include <set>
#include <stack>

// # Solution
// - Make a graph of the number as nodes and the constraints as edges  
// - If the degree of a node exceeds 2, the constraints are not satisfied 
// - If the graph includes n-loops (n > 2), the constraints are not satisfied


/*
    find_larger2_loop
        Determine if a given node has a n-loop (n > 2)
        Input: 
        - v: start node
        - edges
        Output: true if it has loop
        - true: if v has a loop
        - false: else
*/
bool find_larger2_loop( int v, const std::vector< std::set< int > >& edges )
{
    std::stack< int > visiting_nodes;
    std::vector< bool > visited( edges.size(), false );

    //  Initialize
    for( int u : edges.at( v ) ) {
        visiting_nodes.push( u );
    }

    //  Main
    while( !visiting_nodes.empty() ) {
        int u = visiting_nodes.top();
        visiting_nodes.pop();
        visited.at( u ) = true;
        //  Loop case
        if( u == v ) {
            return( true );
        }
        else {
            for( int w : edges.at( u ) ) {
                if( !visited.at( w ) ) {
                    visiting_nodes.push( w );
                }
            }
        }
    }

    return( false );
}

int main()
{
    //  Read N and M
    int N = 0, M = 0;
    std::cin >> N >> M;
    //  Debug
    // std::cerr << N << " " << M << std::endl;

    //  Read Ai and Bi and represet is 
    std::vector< std::set< int > > edges( N );  
    for( int j = 0; j < M; j ++ ) {
        int A = 0, B = 0;
        std::cin >> A >> B;
        // std::cerr << A << " " << B << std::endl;
        edges.at( A - 1 ).insert( B - 1 ); 
        edges.at( B - 1 ).insert( A - 1 ); 
    }

    //  Condition 1: 
    //  All of the degrees should be 0, 1, 2 -> Do not exceed 2
    bool isYes = true;
    for( int i = 0; ( i < N ) && isYes; i ++ ) {
        if( edges.at( i ).size() > 2 ) {
            isYes = false;
        }
    }
    //  Condition 2: 
    //  Edges do not include n-loops n > 2 such as i - j, j - k, k - i  
    for( int i = 0; ( i < N ) && isYes; i ++ ) {
        std::cerr << i << ": " << find_larger2_loop( i, edges ) << std::endl;
        if( find_larger2_loop( i, edges ) ) {
            isYes = false;
        }
    }
    
    //  Display result
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
