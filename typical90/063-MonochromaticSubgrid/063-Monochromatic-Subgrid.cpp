/*
* @file 063-Monochromatic-Subgrid.cpp
* @brief 063 - Monochromatic Subgrid（★4）
* @author Keitaro Naruse
* @date 2022-01-29
* @copyright MIT License
* @details https://atcoder.jp/contests/typical90/tasks/typical90_bk
*/

// # Solution
// - Try all combonations in H by the greedy method 
// - Find the same number in the column

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>

const bool Debug = false;

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
    int max_indecies = 0, max_count = 0, max_number = 0;
    for( int indecies = 1; indecies < ( 1 << H ); indecies ++ ) {
        std::bitset< 8 > bs( indecies );
        std::vector< int > same_num( W, 0 );
        std::vector< bool > is_same( W, true );
        std::map< int, int > counters;
        for( int h = 0; h < H; h ++ ) {
            if( bs[ h ] ) {
                for( int w = 0; w < W; w ++ ) {
                    if( is_same.at( w ) ) {
                        if( same_num.at( w ) == 0 ) {
                            same_num.at( w ) = P.at( h ).at( w );
                        }
                        else if( same_num.at( w ) != P.at( h ).at( w ) ){
                            is_same.at( w ) = false;
                        }
                    }
                }
            }
        }
        for( int h = 0; h < H; h ++ ) {
            for( int w = 0; w < W; w ++ ) {
                if( bs[ h ] && is_same.at( w ) ) {
                    counters[ same_num.at( w ) ] ++;
                }
            }
        }
        for( auto p : counters ) {
            if( p.second > max_count ) {
                max_count = p.second;
                max_number = p.first;
                max_indecies = indecies;
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
            std::cerr << "max_number: " << max_number << " max_count: " << max_count << std::endl;
        }
    }
    //  Display the result
    std::cout << max_count << std::endl;
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
