/*
* @file 063-Monochromatic-Subgrid.cpp
* @brief 063 - Monochromatic Subgrid
* @author Keitaro Naruse
* @date 2022-01-29
* @copyright MIT License
* @details https://atcoder.jp/contests/typical90/tasks/typical90_bk
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

std::ostream& operator<<( std::ostream& os, const std::vector< int >& v )
{
    for( auto e : v ) {
        os << e << " ";
    }
    return( os );
}

std::ostream& operator<<( std::ostream& os, const std::vector< bool >& v )
{
    for( auto e : v ) {
        if( e ) {
            os << "*" << " ";
        }
        else {
            os << "." << " ";
        }
    }
    return( os );
}

const bool Debug = true;

int main()
{
    //  Read H =  [ 1, 8 ] and W = [ 1, 10^4 ]
    int H = 0, W = 0;
    std::cin >> H >> W;
    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
    }
    //  Read Pij = [ 1, H * W ] = [ 1, 8 * 10^4 ]
    std::vector< std::vector< int > > P( H, std::vector< int >( W, 0 ) );
    for( int h = 0; h < H; h ++ ) {
        for( int w = 0; w < W; w ++ ) {
            std::cin >> P.at( h ).at( w );
        }
    }
    if( Debug ) {
        for( int h = 0; h < H; h ++ ) {
            for( int w = 0; w < W; w ++ ) {
                std::cerr << P.at( h ).at( w ) << " ";
            }
            std::cerr << std::endl;
        }
    }

    //  Main
    //  Find the same number in columns
    for( int indicies = 1; indicies < ( 1 << H ); indicies ++ ) {
        std::bitset< 8 > bs( indicies );
        std::vector< int > same_num( W, 0 );
        std::vector< bool > is_same( W, true );
        for( int h = 0; h < H; h ++ ) {
            if( bs[ h ] ) {
                for( int w = 0; w < W; w ++ ) {
                    if( is_same.at( w ) ) {
                        if( same_num.at( w ) == 0 ) {
                            same_num.at( w ) = P.at( h ).at( w );
                        }
                        else if( same_num.at( w ) != P.at( h ).at( w ) ) {
                            is_same.at( w ) = false;
                        }
                    }
                }
            }
        }
        if( Debug ) {
            std::cerr << bs << std::endl;
            for( int h = 0; h < H; h ++ ) {
                for( int w = 0; w < W; w ++ ) {
                    if( bs[ h ] && is_same.at( w ) ) {
                        std::cerr << same_num.at( w ) << " ";
                    }
                    else {
                        std::cerr << "." << " ";
                    }
                }
                std::cerr << std::endl;
            }
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
