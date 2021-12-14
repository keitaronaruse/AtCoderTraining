/*
    ABC231 Problem D - Neighbors
        https://atcoder.jp/contests/abc231/tasks/abc231_d
        Author: Keitaro Naruse
        Date:   2021-12-11, 2012-12-12
        MIT License
*/

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <stack>
#include <queue>

// # Solution
// - Make a graph of the number as nodes and the constraints as edges  
// - Condition 1: The graph should not include any loop
// - Condition 2: The degrees should not exceeds 2

class int_graph {
public: 
    int_graph( int n ) : size( n ) {
        // adjacent_nodes = std::vector< std::set< int > > ( size );
        adjacent_nodes = std::vector< std::list< int > > ( size );
    };

    void add_edge( int a, int b ) {
        // adjacent_nodes.at( a ).insert( b );
        // adjacent_nodes.at( b ).insert( a );
        adjacent_nodes.at( a ).push_back( b );
        adjacent_nodes.at( b ).push_back( a );
    }

    bool is_connect_dfs( int s, int g ) {
        //  Initialize
        visited = std::vector< bool > ( size, false );
        std::stack< int > to_visit_stack;

        //  Initial boundary check
        // if( s == g ) {
        //     return( true );
        // }

        //  Main
        visited.at( s ) = true;
        to_visit_stack.push( s );
        while( !to_visit_stack.empty() ) {
            int v = to_visit_stack.top();
            to_visit_stack.pop();
            for( int u : adjacent_nodes.at( v ) ) {
                if( u == g ) {
                    //  What should we do in 
                    // Unvisited and goal?
                    return( true );
                }
                else if( !visited.at( u ) ) {
                    visited.at( u ) = true;
                    to_visit_stack.push( u );
                }
                else if( visited.at( u ) ) {
                    //  What should we do?
                }
            }
        }

        //  Finalize
        return( false );
    }

    bool is_connect_bfs( int s, int g ) {
        //  Initialize
        visited = std::vector< bool > ( size, false );
        std::queue< int > to_visit_queue;

        //  Initial boundary check
        // if( s == g ) {
        //     return( true );
        // }

        //  Main
        visited.at( s ) = true;
        to_visit_queue.push( s );
        while( !to_visit_queue.empty() ) {
            int v = to_visit_queue.front();
            to_visit_queue.pop();
            for( int u : adjacent_nodes.at( v ) ) {
                if( u == g ) {
                    return( true );
                }
                else if( !visited.at( u ) ) {
                    visited.at( u ) = true;
                    to_visit_queue.push( u );
                }
            }
        }

        //  Finalize
        return( false );
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
    std::vector< std::list< int > > adjacent_nodes;
    std::vector< bool > visited;
};

int main()
{
    //  Initialize
    //  Read constants
    int N = 0, M = 0;
    std::cin >> N >> M;
    //  Debug
    // std::cerr << N << " " << M << std::endl;

    //  Graph search instance
    int_graph g( N );
    
    //  Result
    bool isYes = true;

    //  Read Ai and Bi and store them as adjacent nodes
    std::vector< int > degrees( N, 0 );
    for( int j = 0; j < M ; j ++ ) {
        int A = 0, B = 0;
        std::cin >> A >> B;
        //  Debug
        // std::cerr << A << " " << B << std::endl;
        int a = A - 1, b = B - 1;
        //  Condition 1
        if( g.is_connect_dfs( a, b ) ) {
            isYes = false;
            break;
        }
        else {
            g.add_edge( a, b );
            //  Condition 2
            degrees.at( a ) ++;
            degrees.at( b ) ++;
            if( ( degrees.at( a ) > 2 ) || ( degrees.at( b ) > 2 ) ) {
                isYes = false;
                break;
            }
        }
    }

    //  Debug
    //  Dispaly degrees
    // for( int i = 0; i < N; i++ ) {
    //     std::cerr << i << ": " << degrees.at( i ) << std::endl;
    // }

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
