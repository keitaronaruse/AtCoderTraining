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

namespace nrs {
    class maze_2d {
        public:
            int h, w;
            std::vector< std::string > s;
            std::vector< std::vector< int > > length;
        public:
            maze_2d() : h( 0 ), w( 0 ), 
                s( std::vector< std::string >( h, std::string("") ) ),
                length( h, std::vector< int >( w, -1 ) ) {
            }
            maze_2d( int H, int W ) : h( H ), w( W ), 
                s( std::vector< std::string >( h, std::string( w, '.' ) ) ),
                length( h, std::vector< int >( w, -1 ) ) {
            }
            maze_2d( const std::vector< std::string >& S ) : h( S.size() ), w( S.at( 0 ).size() ),
                s( S ), 
                length( h, std::vector< int >( w, -1 ) ) {
            }
            std::ostream& print_maze( std::ostream& os ) {
                for( int i = 0; i < h; i ++ ) {
                    for( int j = 0; j < w; j ++ ) {
                        os << s.at( i ).at( j );
                    }
                    os << std::endl;
                }
                return( os );
            }
            std::ostream& print_length( std::ostream& os ) {
                for( int i = 0; i < h; i ++ ) {
                    for( int j = 0; j < w; j ++ ) {
                        os << length.at( i ).at( j ) << " ";
                    }
                    os << std::endl;
                }
                return( os );
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

    nrs::maze_2d m1;
    nrs::maze_2d m2( 4, 8 );
    nrs::maze_2d m3 = m2;
    nrs::maze_2d m4( S );

    if( Debug ) {
        m1.print_maze( std::cerr );
        m1.print_length( std::cerr );
        m2.print_maze( std::cerr );
        m2.print_length( std::cerr );
        m3.print_maze( std::cerr );
        m3.print_length( std::cerr );
        m4.print_maze( std::cerr );
        m4.print_length( std::cerr );
    }

    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}