/**
 * @file abc260-d.cpp
 * @brief ABC260 Problem D - Draw Your Cards
 * @author Keitaro Naruse
 * @date 2022-07-17
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc260/tasks/abc260_d
 */

// # Solution

#include <iostream>
#include <vector>
#include <set>
#include <functional>

int main( ) {
    //  Read N = [ 1, 2*10^5 ], K = [ 1, N ]
    int N, K;
    std::cin >> N >> K;
    //  Read Pi = [ 1, N ]
    std::vector< int > P( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> P.at( i );
    }

    //  Main
    //  Preprocess
    // std::set< int, std::greater< int > > deck;
    std::vector< std::set< int, std::greater< int > > > decks;

    std::vector< int > turns( N, -1 );
    for( int i = 0; i < N; i++ ) {
        std::cout << turns.at( i ) << std::endl;
    }

    //  Finalize
    return ( 0 );
}
