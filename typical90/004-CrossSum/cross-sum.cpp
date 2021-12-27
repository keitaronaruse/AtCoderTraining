/*
    004 - Cross Sum（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_d
        Author: Keitaro Naruse
        Date:   2021-11-25, 2021-12-27
        MIT License
*/

//  # Solution: Memoization
//  - Make a sum table of rows and one of colums
//  - Calculate the target sum with the row and column tables

#include <iostream>
#include <vector>

//  Debug flag
const bool Debug = false;

int main()
{
    //  Read H and W
    int H = 0, W = 0; 
    std::cin >> H >> W;
    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
    }

    //  Read Ai
    std::vector< std::vector< int > > A( H, std::vector<int>( W, 0 ) );
    for( int i = 0; i < H; i ++ ) {
        for( int j = 0; j < W; j ++ ) {
            std::cin >> A.at( i ).at( j );
            if( Debug ) {
                std::cerr << A.at( i ).at( j ) << " ";
            }
        }
        if( Debug ) {
            std::cerr << std::endl;
        }
    }

    //  Main
    //  Memoization strategy
    //  Calculate sum of columns for each row
    std::vector<int> row_table( H, 0 );
    std::vector<int> col_table( W, 0 );
    for( int i = 0; i < H; i ++ ) {
        for( int j = 0; j < W; j++ ) {
            row_table.at( i ) +=  A.at( i ).at( j );
            col_table.at( j ) +=  A.at( i ).at( j );
        }
    }
    if( Debug ) {
        std::cerr << "row table" << std::endl;
        for( int i = 0; i < H; i ++ ) {
            std::cerr << row_table.at( i ) << " ";
        }
        std::cerr << std::endl;

        std::cerr << "column table" << std::endl;
        for( int j = 0; j < W; j++ ) {
            std::cerr << col_table.at( j ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Calculate and display target sums
    for( int i = 0; i < H; i ++ ) {
        for( int j = 0; j < W; j ++ ) {
            std::cout << row_table.at( i ) + col_table.at( j ) - A.at( i ).at( j ) << " ";
        }
        std::cout << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
