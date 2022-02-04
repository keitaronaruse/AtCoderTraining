/**
* @file H-Grid1.cpp
* @brief H - Grid 1
* @author Keitaro Naruse
* @date 2022-02-05
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_h
*/

#include <iostream>
#include <vector>
#include <algorithm>
const int Large_Prime = 1000000007;
const bool Debug = false;

int main()
{
    //  Read H, W = [ 2, 10^3 ]
    int H = 0, W = 0;
    std::cin >> H >> W;
    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
    }
    //  Read aij = { '.', '#' }
    std::vector< std::vector< char > > a( H, std::vector< char >( W, ' ' ) );
    for( int h = 0; h < H; h ++ ) {
        for( int w = 0; w < W; w ++ ) {
            std::cin >> a.at( h ).at( w );
        }
    }
    if( Debug ) {
        for( int h = 0; h < H; h ++ ) {
            for( int w = 0; w < W; w ++ ) {
                std::cerr << a.at( h ).at( w );
            }
            std::cerr << std::endl;
        }
    }

    //  Main
    std::vector< std::vector< int > > dp_comb( H + 1, std::vector< int >( W + 1, 0 ) );
    dp_comb.at( 1 ).at( 1 ) = 1;
    for( int h = 1; h <= H; h ++ ) {
        for( int w = 1; w <= W; w ++ ) {
            if( a.at( h - 1 ).at( w - 1 ) == '.' ) {
                dp_comb.at( h ).at( w ) += dp_comb.at( h - 1 ).at( w ) + dp_comb.at( h ).at( w - 1 );
                if( dp_comb.at( h ).at( w ) >= Large_Prime ) {
                    dp_comb.at( h ).at( w ) %= Large_Prime;
                }
            }
            else if( a.at( h - 1 ).at( w - 1 ) == '#' ) {
                dp_comb.at( h ).at( w ) = 0;
            }
        }
    }
    //  Display the result
    std::cout << dp_comb.at( H ).at( W ) << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
