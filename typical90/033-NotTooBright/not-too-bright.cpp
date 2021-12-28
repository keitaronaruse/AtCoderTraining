/*
    033 - Not Too Bright
        https://atcoder.jp/contests/typical90/tasks/typical90_ag
        Author: Keitaro Naruse
        Date:   2021-11-28, 2021-12-29
        MIT License
*/

//  # Solution
//  - The next tiling pattern gives us the maximum number of light-on cells
//  - *.*.
//  - ....
//  - ( H / 2 + H % 2 ) * ( W / 2 + W % 2 )

#include <iostream>

const bool Debug = false;

int main()
{
    //  Initialize
    //  Read H and W
    int H = 0, W = 0;
    std::cin >> H >> W;
    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
    }

    //  Main
    //  Boundary cases
    if(  ( H == 1 ) || ( W == 1 ) ) {
        std::cout << H * W << std::endl;
    }
    //  Regular cases
    else {
        std::cout << ( ( H / 2 ) + ( H % 2 ) ) * ( ( W / 2 ) + ( W % 2 ) ) << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
