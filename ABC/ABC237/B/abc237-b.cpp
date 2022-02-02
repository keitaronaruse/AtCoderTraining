/**
* @file abc237-b.cpp
* @brief ABC237 Problem B - Matrix Transposition
* @author Keitaro Naruse
* @date 2022-01-30
* @copyright MIT License
* @details https://atcoder.jp/contests/abc237/tasks/abc237_b
*/

// # Solution
// - Represent a matrix in vector of vector
// - Display the matrix swtiching rows and columns

#include <iostream>
#include <vector>

const bool Debug = false;

int main()
{
    //  Read H, W
    int H = 0, W = 0;
    std::cin >> H >> W;
    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
    }
    //  Read Aij
    std::vector< std::vector< int > > A( H, std::vector< int >( W, 0 ) );
    for( int i = 0; i < H; i ++ ) {
        for( int j = 0; j < W; j ++ ) {
            std::cin >> A.at( i ).at( j );
        }
    }
    if( Debug ) {
        for( int i = 0; i < H; i ++ ) {
            for( int j = 0; j < W; j ++ ) {
                std::cerr << A.at( i ).at( j ) << " ";
            }
            std::cerr << std::endl;
        }
    }

    //  Main
    //  Make Bij
    std::vector< std::vector< int > > B( W, std::vector< int >( H, 0 ) );
    for( int j = 0; j < W; j ++ ) {
        for( int i = 0; i < H; i ++ ) {
            B.at( j ).at( i ) = A.at( i ).at( j );
            std::cout << B.at( j ).at( i ) << " ";
        }
        std::cout << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
