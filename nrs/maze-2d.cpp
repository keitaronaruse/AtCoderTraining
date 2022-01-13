/**
* @file maze-2d.cpp
* @brief maze 2d
* @author Keitaro Naruse
* @date 2021-01-13
* @copyright MIT License
*/

#include <iostream>
#include <string>
#include <vector>

namespace nrs {
    ;
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
    const int H = S.size();
    const int W = S.at( 0 ).size();

    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
        for( int i = 0; i < S.size(); i ++ ) {
            std::cerr << S.at( i ) << std::endl;
        }
    }
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}