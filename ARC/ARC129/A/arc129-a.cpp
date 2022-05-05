/**
 * @file arc129-a.cpp
 * @brief ARC129 Problem A - Smaller XOR
 * @author Keitaro Naruse
 * @date 2022-05-05
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc129/tasks/arc129_a
 */

// # Solution

#include <iostream>
#include <vector>
#include <bitset>

int main( ) {
    //  Read N, L, R = [ 1, 10^18 ]
    unsigned long long N, L, R;
    std::cin >> N >> L >> R;

    //  Main
    //  Preprocess
    const int Z = 64;
    std::bitset< Z > n( N ), lower( 0LL ), upper( 0LL );
    for( int k = Z - 2; k >= 0; k-- ) {
        if( n[ k ] == 1 ) {
            lower[ k ] = 0;
            upper[ k ] = 1;
        }
        else {
            if( upper[ k + 1 ] == 1 ) {
                upper[ k + 1 ] = 1;
            }
            else {
                upper[ k + 1 ] = 0;
            }
            lower[ k + 1 ] = 0;
        }
    }
    if( lower.none() ) {
        lower[ 0 ] = 1;
    }
    std::cout << n << std::endl;
    std::cout << lower << std::endl;
    std::cout << upper << std::endl;

    //  Find the solution
    long long answer = 0LL;
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
