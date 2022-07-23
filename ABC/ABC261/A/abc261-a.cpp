/**
 * @file abc261-a.cpp
 * @brief ABC261 Problem A - Intersection
 * @author Keitaro Naruse
 * @date 2022-07-23
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc261/tasks/abc261_a
 */

// # Solution

#include <iostream>
#include <algorithm>

int main( ) {
    //  Read L1 ,R1, L2, R2 = [ 0, 100 ]
    int L1, R1, L2, R2;
    std::cin >> L1 >> R1 >> L2 >> R2;

    //  Main
    int answer = std::max( 0, std::min( R1, R2 ) - std::max( L1, L2 ) );
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
