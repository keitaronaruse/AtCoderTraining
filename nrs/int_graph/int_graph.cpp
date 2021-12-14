/*
    int_graph.hpp
        Author: Keitaro Naruse
        Date:   2021-12-13
        MIT License
*/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <queue>

class int_graph {
public: 
    int_graph( int n ) : size( n ) {
        adjacent_nodes = std::vector< std::list< int > > ( size );
    };

    void add_edge( int a, int b ) {
        adjacent_nodes.at( a ).push_back( b );
        adjacent_nodes.at( b ).push_back( a );
    }

    bool is_connect_dfs( int s, int g ) {
        //  Initialize
        visited = std::vector< bool > ( size, false );
        std::stack< int > to_visit_stack;

        //  Main
        visited.at( s ) = true;
        to_visit_stack.push( s );

        while( !to_visit_stack.empty() ) {
            int v = to_visit_stack.top();
            to_visit_stack.pop();
            
            if( v == g ) {
                return( true );
            }

            for( int u : adjacent_nodes.at( v ) ) {
                if( !visited.at( v ) ) {
                    visited.at( v ) = true;
                    to_visit_stack.push( u );
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

        //  Main
        visited.at( s ) = true;
        to_visit_queue.push( s );
        while( !to_visit_queue.empty() ) {
            int v = to_visit_queue.front();
            to_visit_queue.pop();
            if( v == g ) {
                return( true );
            }
            for( int u : adjacent_nodes.at( v ) ) {
                if( !visited.at( u ) ) {
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
    for( int j = 0; j < M; j ++ ) {
        int A = 0, B = 0;
        std::cin >> A >> B;
        int a = A - 1, b = B - 1;
        if( g.is_connect_dfs( a, b ) ) {
            //  Debug
            std::cerr << "False by connectivity" << std::endl;
            isYes = false;
            break;
        }
        g.add_edge( a, b );
        degrees.at( a ) ++;
        degrees.at( b ) ++;
        if( ( degrees.at( a ) > 2 ) || ( degrees.at( b ) > 2 ) ) {
            //  Debug
            std::cerr << "False by degree" << std::endl;
            isYes = false;
            break;
        }
    }

    //  Main

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
