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
            lower[ k ] = 1;
            upper[ k ] = 1;
        }
        else {
            lower[ k ] = 0;
            if( upper[ k + 1 ] == 1 ) {
                upper[ k ] = 1;
            }
            else {
                upper[ k ] = 0;
            }
        }
    }
    std::cout << n << std::endl;
    std::cout << lower << std::endl;
    std::cout << upper << std::endl;

    //  Find the solution
    unsigned long long LB = lower.to_ullong(), UB = upper.to_ullong();
    if( LB < L ) {
        LB = L;
    }
    if( R < UB ) {
        UB = R;
    }
    std::cout << N << " " << L << " " << R<< std::endl;
    std::cout << N << " " << LB << " " << UB << std::endl;
    long long answer = UB - ( LB - 1 );
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
