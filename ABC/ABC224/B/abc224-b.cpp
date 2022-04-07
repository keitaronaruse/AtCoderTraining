/**
* @file abc224-b.cpp
* @brief ABC224 Problem B - Mongeness
* @author Keitaro Naruse
* @date 2022-04-07
* @copyright MIT License
* @details https://atcoder.jp/contests/abc224/tasks/abc224_b
*/

// # Solution

#include <iostream>
#include <vector>

int main()
{
    //  Read H, W = [ 2, 50 ]
    int H, W;
    std::cin >> H >> W;
    //  Read Aij = [ 1, 10^9 ]
    std::vector< std::vector< int > > A( H, std::vector< int >( W ) ); 
    for( int h = 0; h < H; h ++ ) {
        for( int w = 0; w < W; w ++ ) {
            std::cin >> A.at( h ).at( w );
        }
    }

    //  Main
    bool isYes = true;
    // for( int i1 = 0; i1 < H - 1; i1 ++ ) {
    //     for( int i2 = i1 + 1; i2 < H; i2 ++ ) {
    //         for( int j1 = 0; j1 < W - 1; j1 ++ ) {
    //             for( int j2 = j1 + 1; j2 < W; j2 ++ ) {
    //                 if( A.at( i1 ).at( j1 ) + A.at( i2 ).at( j2 ) 
    //                     > A.at( i2 ).at( j1 ) + A.at( i1 ).at( j2 ) ) {
    //                     isYes = false;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // }
    for( int i = 0; i < H - 1; i ++ ) {
        for( int j = 0; j < W - 1; j ++ ) {
            if( A.at( i ).at( j ) + A.at( i + 1 ).at( j + 1 ) 
                > A.at( i + 1 ).at( j ) + A.at( i ).at( j + 1 ) ) {
                isYes = false;
                break;
            }
        }
    }

    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return( 0 );
}
