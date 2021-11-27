/*
    004 - Cross Sum（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_d
        Author: Keitaro Naruse
        Date:   2021-11-25
        MIT License
*/

//  # Solution: Memoization
//  - Make a sum table of rows and one of colums
//  - Calculate the target sum by the tables

#include <iostream>
#include <vector>

int main()
{
    //  Initialize
    //  Read H and W
    int H = 0, W = 0; 
    std::cin >> H >> W;
    //  Debug
    // std::cerr << H << " " << W << std::endl;

    //  Read Ai
    std::vector< std::vector< int > > A( H, std::vector<int>( W, 0 ) );
    for( int i = 0; i != H; i++ ) {
        for( int j = 0; j != W; j++ ) {
            std::cin >> A.at( i ).at( j );
            //  Debug
            // std::cerr << A.at( i ).at( j ) << " ";
        }
        //  Debug
        // std::cerr << std::endl;
    }

    //  Main
    //  Memoization strategy
    //  Calculate sum of columns for each row
    //  Debug
    // std::cerr << "row_table" << std::endl;
    // std::cerr << "col_table" << std::endl;
    std::vector<int> row_table( H, 0 );
    std::vector<int> col_table( W );
    for( int i = 0; i != H; i++ ) {
        for( int j = 0; j != W; j++ ) {
            row_table.at( i ) +=  A.at( i ).at( j );
            col_table.at( j ) +=  A.at( i ).at( j );
        }
        //  Debug
        // std::cerr << row_table.at( i ) << " ";
        // std::cerr << col_table.at( j ) << " ";
    }
    //  Debug
    // std::cerr << std::endl;

    //  Calculate and display target sums
    for( int i = 0; i != H; i++ ) {
        for( int j = 0; j != W; j++ ) {
            std::cout << row_table.at( i ) + col_table.at( j ) - A.at( i ).at( j ) << " ";
        }
        std::cout << std::endl;
    }

    //  Naive code of always summing-up results in TLE (too slow)
    // for( int i = 0; i != H; i++ ) {
    //     for( int j = 0; j != W; j++ ) {
    //         //  For i-th row, j-th colomn
    //         //  sum of rows and colmuns
    //         int sum = 0;
    //         //  sum up in the row direction
    //         for( int k = 0; k != H; k++) {
    //             sum += A.at( k ).at( j );
    //         }
    //         //  sum up in the colmun direction
    //         for( int k = 0; k != W; k++) {
    //             sum += A.at( i ).at( k );
    //         }
    //         //  Since A.at( i ).at( j ) is summed twice, substact it from sum
    //         sum -= A.at( i ).at( j );
    //         //  Outpu the results
    //         std::cout << sum << " ";
    //     }
    //     //  Outpu the results
    //     std::cout << std::endl;
    // }
    
    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
