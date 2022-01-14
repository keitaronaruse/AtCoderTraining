/**
* @file maze-2d.cpp
* @brief maze 2d
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
            typedef std::vector< std::string > value_type; 
            int h, w;
            value_type s;
        public:
            maze_2d() : h( 0 ), w( 0 ), s( value_type ( h, std::string("") ) ) {
            }
            maze_2d( int H, int W ) : h( H ), w( W ), s( value_type ( h, std::string( w, '.' ) ) ) {
            }
            maze_2d( const value_type& S ) : h( S.size() ), w( S.at( 0 ).size() ), s( S ) {
            }
            friend std::ostream& operator<< ( std::ostream& os, const maze_2d& m ) {
                os << m.h << " " << m.w << std::endl;
                for( int h = 0; h < m.h; h ++ ) {
                    for( int w = 0; w < m.s.at( h ).size(); w ++ ) {
                        os << m.s.at( h ).at( w );
                    }
                    os << std::endl;
                }
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
        std::cerr << m1;
        std::cerr << m2;
        std::cerr << m3;
        std::cerr << m4;
    }

    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}