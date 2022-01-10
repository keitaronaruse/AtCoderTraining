/*
    ABC232 Problem D - Weak Takahashi
        https://atcoder.jp/contests/abc232/tasks/abc232_d
        Author: Keitaro Naruse
        Date:   2021-12-19, 2022-01-10
        MIT License
*/

// # Solution
// - 

#include <iostream>
#include <vector>

const bool Debug = true;

int main()
{
    //  Read H and W
    int H = 0, W = 0;
    std::cin >> H >> W;
    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
    }
    //  Read C
    std::vector< std::string > C( H );
    for( int i = 0; i < H; i ++ ) {
        std::cin >> C.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < H; i ++ ) {
            std::cerr << C.at( i ) << std::endl;
        }
    }

    //  Display result

    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
