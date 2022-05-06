/**
 * @file arc129-b.cpp
 * @brief ARC129 Problem B - Range Point Distance 
 * @author Keitaro Naruse
 * @date 2022-05-06
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc129/tasks/arc129_b
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
    const int Z = 64;
    std::bitset< Z > n( N );

    unsigned long long answer = 0LL;
    for( int i = Z - 1; i >= 0; i-- ) {
        std::bitset< Z > lower( 0LL ), upper( 0LL );
        if( n[ i ] == 1 ) {
            //  Lower bound
            lower[ i ] = upper[ i ] = 1;
            if( i >= 1 ) {
                for( int j = i - 1; j >= 0; j-- ) {
                    lower[ j ] = 0;
                    upper[ j ] = 1;
                }
            }

            unsigned long long LB = lower.to_ullong( );
            unsigned long long UB = upper.to_ullong( );
            if( L <= UB && LB <= R ) {
                if( LB < L ) {
                    LB = L;
                }
                if( R < UB ) {
                    UB = R;
                }
                answer += ( UB - LB + 1LL );
            }
        }
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
