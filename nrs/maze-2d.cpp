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
#include <queue>
#include <stack>
#include <utility>
#include <functional>

namespace nrs {
    class maze_2d {
        typedef std::pair< int, int > value_type;
        public:
            int height, width;
            std::vector< std::string > maze;
            std::vector< std::vector< int > > length;
            std::queue< value_type > q;
            std::stack< value_type > s;
            std::priority_queue< 
                std::pair< int, value_type >, 
                std::vector< std::pair< int, value_type > >,
                std::greater< std::pair< int, value_type > >
            > pq;
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
            std::pair< int, int > next_node_4_queue( ) {
                std::pair< int, int > v = q.front(); 
                int h = v.first, w = v.second; 
                q.pop();
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
                            if( length.at( i ).at( j ) == -1 ) {
                                length.at( i ).at( j ) = length.at( h ).at( w ) + 1;
                                q.push( std::make_pair( i, j ) );
                            }
                        }
                    }
                }
                return( v );
            }
            std::pair< int, int > next_node_4_stack() {
                std::pair< int, int > v = s.top(); 
                int h = v.first, w = v.second; 
                s.pop();
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
                            if( length.at( i ).at( j ) == -1 ) {
                                length.at( i ).at( j ) = length.at( h ).at( w ) + 1;
                                s.push( std::make_pair( i, j ) );
                            }
                        }
                    }
                }
                return( v );
            }

            std::pair< int, std::pair< int, int > > next_node_4_priority_queue() {
                std::pair< int, value_type > v = pq.top(); 
                int d = v.first;
                int h = v.second.first, w = v.second.second; 
                pq.pop();
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
                            if( length.at( i ).at( j ) == -1 ) {
                                length.at( i ).at( j ) = length.at( h ).at( w ) + 1;
                                pq.push( std::make_pair( 
                                        length.at( i ).at( j ), std::make_pair( i, j ) 
                                    ) 
                                );
                            }
                        }
                    }
                }
                return( v );
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
        m.q.push( std::make_pair( h, w ) );
        while( !m.q.empty() ) {
            std::pair< int, int > v = m.next_node_4_queue( );
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
        m.s.push( std::make_pair( h, w ) );
        while( !m.s.empty() ) {
            std::pair< int, int > v = m.next_node_4_stack( );
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
        m.pq.push( std::make_pair(
                0, 
                std::make_pair( h, w ) 
            )
        ); 
        while( !m.pq.empty() ) {
            std::pair< int, std::pair< int, int > > v = m.next_node_4_priority_queue( );
            if( Debug ) {
                std::cerr << "( " << v.second.first << ", " << v.second.second << " )" << " ";
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
