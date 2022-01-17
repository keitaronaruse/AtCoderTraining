/**
* @file maze-2d.cpp
* @brief class of maze 2d and its test driver
* @author Keitaro Naruse
* @date 2021-01-13, 2021-01-14
* @copyright MIT License
*/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <functional>

namespace nrs {
    class maze_2d {
        public:
            //  state = ( h, w )
            typedef std::pair< int, int > state_type;
        public:
            int height, width;
            std::vector< std::string > maze;
            std::vector< std::vector< int > > length;
            std::queue< state_type > visiting_queue;
            std::stack< state_type > visiting_stack;
            std::priority_queue< 
                std::pair< int, state_type >, 
                std::vector< std::pair< int, state_type > >,
                std::greater< std::pair< int, state_type > >
            > visiting_priority_queue;
        public:
            maze_2d() : height( 0 ), width( 0 ), 
                maze( std::vector< std::string >( height, std::string( "" ) ) ),
                length( height, std::vector< int >( width, -1 ) ) {
            }
            maze_2d( int h, int w ) : height( h ), width( w ), 
                maze( std::vector< std::string >( height, std::string( width, '.' ) ) ),
                length( height, std::vector< int >( width, -1 ) ) {
            }
            maze_2d( const std::vector< std::string >& S ) : height( S.size() ), width( S.at( 0 ).size() ),
                maze( S ), 
                length( height, std::vector< int >( width, -1 ) ) {
            }
            std::ostream& print_maze( std::ostream& os ) {
                for( int i = 0; i < height; i ++ ) {
                    for( int j = 0; j < width; j ++ ) {
                        os << maze.at( i ).at( j );
                    }
                    os << std::endl;
                }
                return( os );
            }
            std::ostream& print_length( std::ostream& os ) {
                for( int i = 0; i < height; i ++ ) {
                    for( int j = 0; j < width; j ++ ) {
                        os << length.at( i ).at( j ) << " ";
                    }
                    os << std::endl;
                }
                return( os );
            }
            std::vector< state_type > get_four_neighbors( const state_type& h_w ) {
                std::vector< state_type > neighbors;
                int h = h_w.first, w = h_w.second;
                for( int k = 0; k < 4; k ++ ) {
                    int i = 0, j = 0;
                    switch( k ) {
                        case 0: i = h + 1; j = w + 0; break;
                        case 1: i = h + 0; j = w + 1; break;
                        case 2: i = h - 1; j = w + 0; break;
                        case 3: i = h + 0; j = w - 1; break;
                    }
                    if( 0 <= i && i < height && 0 <= j && j < width ) {
                        if( maze.at( i ).at( j ) == '.' ) {
                            neighbors.push_back( std::make_pair( i, j ) );
                        }
                    }
                }
                return( neighbors );
            }
            state_type next_node_four_neighbor_bfs( ) {
                state_type h_w = visiting_queue.front(); 
                visiting_queue.pop();
                int h = h_w.first, w = h_w.second;
                std::vector< state_type > neighbors = get_four_neighbors( h_w );
                for( auto n : neighbors ) {
                    int i = n.first, j = n.second;
                    if( length.at( i ).at( j ) == -1 ) {
                        length.at( i ).at( j ) = length.at( h ).at( w ) + 1;
                        visiting_queue.push( std::make_pair( i, j ) );
                    }
                }
                return( h_w );
            }
            state_type next_node_four_neighbor_dfs() {
                state_type h_w = visiting_stack.top(); 
                visiting_stack.pop();
                int h = h_w.first, w = h_w.second;
                std::vector< state_type > neighbors = get_four_neighbors( h_w );
                for( auto n : neighbors ) {
                    int i = n.first, j = n.second;
                    if( length.at( i ).at( j ) == -1 ) {
                        length.at( i ).at( j ) = length.at( h ).at( w ) + 1;
                        visiting_stack.push( std::make_pair( i, j ) );
                    }
                }
                return( h_w );
            }

            std::pair< int, state_type > next_node_four_neighbor_dijkstra() {
                std::pair< int, state_type > l_h_w = visiting_priority_queue.top(); 
                visiting_priority_queue.pop();
                state_type h_w = l_h_w.second;
                int h = h_w.first, w = h_w.second;
                std::vector< state_type > neighbors = get_four_neighbors( h_w );
                for( auto n : neighbors ) {
                    int i = n.first, j = n.second;
                    if( length.at( i ).at( j ) == -1 ) {
                        length.at( i ).at( j ) = length.at( h ).at( w ) + 1;
                        visiting_priority_queue.push( std::make_pair( 
                                length.at( i ).at( j ), std::make_pair( i, j ) 
                            ) 
                        );

                    }
                }
                return( l_h_w );
            }
    };
}

const bool Debug = true;

int main()
{
    const std::vector< std::string > S = {
        "....#.#.", 
        ".##.....",
        ".....#.#",
        "#..#...."
    };

    nrs::maze_2d m( S );
    if( Debug ) {
        m.print_maze( std::cerr );
    }

    //  Search: Initialize
    int h = 0, w = 0;
    m.length.at( h ).at( w ) = 0;

    const int mode = 2;
    if( mode == 0 ) {
        //  BFS: Breadth first search, queue 
        m.visiting_queue.push( std::make_pair( h, w ) );
        while( !m.visiting_queue.empty() ) {
            nrs::maze_2d::state_type v = m.next_node_four_neighbor_bfs( );
            if( Debug ) {
                std::cerr << "( " << v.first << ", " << v.second << " )" << " ";
            }
        }
        if( Debug ) {
            std::cerr << std::endl;
        }
    }
    // BFS: the order of node visit 
    // ( 0, 0 ) ( 1, 0 ) ( 0, 1 ) ( 2, 0 ) ( 0, 2 ) 
    // ( 2, 1 ) ( 0, 3 ) ( 3, 1 ) ( 2, 2 ) ( 1, 3 ) 
    // ( 3, 2 ) ( 2, 3 ) ( 1, 4 ) ( 2, 4 ) ( 1, 5 ) 
    // ( 3, 4 ) ( 1, 6 ) ( 0, 5 ) ( 3, 5 ) ( 2, 6 ) 
    // ( 1, 7 ) ( 3, 6 ) ( 0, 7 ) ( 3, 7 ) 
    //  BFS: length
    //   0  1  2  3 -1  7 -1  9 
    //   1 -1 -1  4  5  6  7  8 
    //   2  3  4  5  6 -1  8 -1 
    //  -1  4  5 -1  7  8  9 10 
    else if( mode == 1 ) {
        //  DFS: Depth first search 
        m.visiting_stack.push( std::make_pair( h, w ) );
        while( !m.visiting_stack.empty() ) {
            nrs::maze_2d::state_type v = m.next_node_four_neighbor_dfs( );
            if( Debug ) {
                std::cerr << "( " << v.first << ", " << v.second << " )" << " ";
            }
        }
        if( Debug ) {
            std::cerr << std::endl;
        }
    }
    //  DFS: the order of node visit
    // ( 0, 0 ) ( 0, 1 ) ( 0, 2 ) ( 0, 3 ) ( 1, 3 ) 
    // ( 1, 4 ) ( 1, 5 ) ( 0, 5 ) ( 1, 6 ) ( 1, 7 ) 
    // ( 0, 7 ) ( 2, 6 ) ( 3, 6 ) ( 3, 5 ) ( 3, 4 ) 
    // ( 3, 7 ) ( 2, 4 ) ( 2, 3 ) ( 2, 2 ) ( 2, 1 ) 
    // ( 2, 0 ) ( 3, 1 ) ( 3, 2 ) ( 1, 0 ) 
    // DFS: length
    //  0  1  2  3 -1  7 -1  9 
    //  1 -1 -1  4  5  6  7  8 
    //  8  7  6  5  6 -1  8 -1 
    // -1  8  7 -1 11 10  9 10 
    else if( mode == 2 ) {
        //  Dijkstra's algorithm: priority queue 
        m.visiting_priority_queue.push( std::make_pair(
                0, 
                std::make_pair( h, w ) 
            )
        ); 
        while( !m.visiting_priority_queue.empty() ) {
            std::pair< int, nrs::maze_2d::state_type > l_h_w = m.next_node_four_neighbor_dijkstra( );
            if( Debug ) {
                std::cerr << "( " << l_h_w.second.first << ", " << l_h_w.second.second << " )" << " ";
            }
        }
        if( Debug ) {
            std::cerr << std::endl;
        }
    }
    // Dijkstra's method: the order of node visit
    // ( 0, 0 ) ( 0, 1 ) ( 1, 0 ) ( 0, 2 ) ( 2, 0 ) 
    // ( 0, 3 ) ( 2, 1 ) ( 1, 3 ) ( 2, 2 ) ( 3, 1 ) 
    // ( 1, 4 ) ( 2, 3 ) ( 3, 2 ) ( 1, 5 ) ( 2, 4 ) 
    // ( 0, 5 ) ( 1, 6 ) ( 3, 4 ) ( 1, 7 ) ( 2, 6 ) 
    // ( 3, 5 ) ( 0, 7 ) ( 3, 6 ) ( 3, 7 ) 
    // Dijkstra's algorithm: length  
    //  0  1  2  3 -1  7 -1  9 
    //  1 -1 -1  4  5  6  7  8 
    //  2  3  4  5  6 -1  8 -1 
    // -1  4  5 -1  7  8  9 10 
    if( Debug ) {
        m.print_length( std::cerr );
    }
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
