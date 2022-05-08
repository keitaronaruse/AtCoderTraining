/**
 * @file abc250-c.cpp
 * @brief ABC250 Problem C - Adjacent Swaps
 * @author Keitaro Naruse
 * @date 2022-05-08
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc250/tasks/abc250_c
 */

// # Solution

#include <iostream>
#include <vector>
#include <map>

int main( ) {
    //  Read N = [ 2, 2*10^5 ], Q = [ 1, 2*10^5 ]
    int N, Q;
    std::cin >> N >> Q;

    //  Read Xi = [ 1, N ]
    std::vector< int > X( Q );
    for( int k = 0; k < Q; k++ ) {
        std::cin >> X.at( k );
    }

    //  Main
    //  Preprocess
    std::map< int, int > val_idx, idx_val;
    for( int i = 1; i <= N; i++ ) {
        val_idx[ i ] = i;
        idx_val[ i ] = i;
    }
    //  Find the solution
    for( int k = 0; k < Q; k++ ) {
        //  Find the two numbers
        int x = X.at( k ), y;
        int i = val_idx[ x ], j = i + 1;
        if( i == N ) {
            j = i - 1;
        }
        y = idx_val[ j ];
        //  Swap them
        val_idx[ y ] = i;
        val_idx[ x ] = j;
        idx_val[ i ] = y;
        idx_val[ j ] = x;
    }
    //  Output the solution
    for( int i = 1; i <= N; i++ ) {
        std::cout << idx_val[ i ] << " ";
    }
    std::cout << std::endl;

    //  Finalize
    return ( 0 );
}
