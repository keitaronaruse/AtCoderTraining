/*
    ABC231 Problem D - Neighbors
        https://atcoder.jp/contests/abc231/tasks/abc231_d
        Author: Keitaro Naruse
        Date:   2021-12-11, 2021-12-12, 2021-12-13, 2021-12-14
        MIT License
*/

#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>

// # Solution
// - Make a graph of the number as nodes and the constraints as edges  
// - Condition 1: The degrees should not exceeds 2
// - Condition 2: The graph should not include any loop

class int_graph {
public: 
    int_graph( int n ) : size( n ) {
        adjacent_nodes = std::vector< std::set< int > > ( size );
    };

    void add_edge( int a, int b ) {
        adjacent_nodes.at( a ).insert( b );
        adjacent_nodes.at( b ).insert( a );
    }

    bool is_connect_dfs( int s, int g ) {
        //  Initialize
        visited = std::vector< bool > ( size, false );
        std::stack< int > to_visit;

        //  Main
        visited.at( s ) = true;
        to_visit.push( s );
        while( ! to_visit.empty() ) {
            int v = to_visit.top();
            to_visit.pop();
            for( int u : adjacent_nodes.at( v ) ) {
                if( u == g ) {
                    //  Goal
                    return( true );
                }
                else if( !visited.at( u ) ) {
                    //  Push to stack
                    visited.at( u ) = true;
                    to_visit.push( u );
                }
                else if( visited.at( u ) ) {
                    //  Already visited, nothing to do
                }
            }
        }

        //  Finalize
        return( false );
    }

    bool is_connect_bfs( int s, int g ) {
        //  Initialize
        visited = std::vector< bool > ( size, false );
        std::queue< int > to_visit;

        //  Main
        visited.at( s ) = true;
        to_visit.push( s );
        while( ! to_visit.empty() ) {
            int v = to_visit.front();
            to_visit.pop();
            for( int u : adjacent_nodes.at( v ) ) {
                if( u == g ) {
                    return( true );
                }
                else if( !visited.at( u ) ) {
                    visited.at( u ) = true;
                    to_visit.push( u );
                }
            }
        }

        //  Finalize
        return( false );
    }

    int degree( int v ) const {
        return( adjacent_nodes.at( v ).size() );
    }

    std::ostream& print_adjacent_nodes( std::ostream& os ) {
        //  Dispaly adjacent nodes
        for( int i = 0; i < size; i ++ ) {
            os << i << ": ";
            for( int v : adjacent_nodes.at( i ) ) {
                os << v << " ";
            }
            os << std::endl;
        }
        //  Finalize
        return( os );
    }
private:
    int size;
    // std::vector< std::set< int > > adjacent_nodes;
    std::vector< std::set< int > > adjacent_nodes;
    std::vector< bool > visited;
};

int main()
{
    //  Initialize
    int N = 0, M = 0;
    std::cin >> N >> M;

    //  Graph search instance
    int_graph g( N );
    
    //  Result
    bool isYes = true;

    //  Read Ai and Bi and store them as adjacent nodes
    for( int j = 0; j < M ; j ++ ) {
        int A = 0, B = 0;
        std::cin >> A >> B;
        int a = A - 1, b = B - 1;

        //  Condition 1
        //  If the edge( a, b ) is added to the graph, 
        //  the condition 1 will not be satisfied
        if( ( g.degree( a ) == 2 ) || ( g.degree( b ) == 2 ) ) {
            isYes = false;
            break;
        }
        //  Condition 2
        if( g.is_connect_dfs( a, b ) ) {
            isYes = false;
            break;
        }
        else {
            g.add_edge( a, b );
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
    return( 0 );
}
