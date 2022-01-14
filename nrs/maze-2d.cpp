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
#include <utility>

namespace nrs {
    class maze_2d {
        public:
            int height, width;
            std::vector< std::string > maze;
            std::vector< std::vector< int > > length;
        public:
            maze_2d() : height( 0 ), width( 0 ), 
                maze( std::vector< std::string >( height, std::string("") ) ),
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
            void init_length() {
                length = std::vector< std::vector< int > >( height, std::vector< int >( width, -1 ) );
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
            std::pair< int, int > next_node_bfs( std::queue< std::pair< int, int > >& q ) {
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
                                q.push( std::make_pair( i, j) );
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

    //  BFS: Breadth first search 
    std::queue< std::pair< int, int > > q;
    int h = 0, w = 0;
    m.length.at( h ).at( w ) = 0;
    q.push( std::make_pair( h, w ) );

    if( Debug ) {
        while( !q.empty() ) {
            std::pair< int, int > v = m.next_node_bfs( q );
            std::cerr << "( " << v.first << ", " << v.second << " )" << std::endl;
        }
    }
    if( Debug ) {
        m.print_length( std::cerr );
    }

    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}