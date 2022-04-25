/**
* @file arc139-a.cpp
* @brief ARC139 Problem X
* @author Keitaro Naruse
* @date 2022-04-24, 2022-04-25
* @copyright MIT License
* @details https://atcoder.jp/contests/arc139/tasks/arc139_a
*/

// # Solution
// - Principle
//   - Right shift of n bits followed by left shift of n bits make the n-LSB zero
// - Procedure
//   - if T[i] < T[i-1], A += (1 << T[i])
//   - if T[i] >= T[i-1], A >>= n, A++, (another A++ if LSB == 0), A <<= n

#include <iostream>
#include <vector>

int main()
{
    //  Read N = [ 1, 10^5 ]
    int N;
    std::cin >> N;
    //  Read Ti = [ 0, 40 ]
    std::vector< int > T( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> T.at( i );
    }

    //  Main
    long long ans = 1LL << T.at( 0 );
    for( int i = 1; i < N; i ++ ) {
        if( T.at( i ) < T.at( i - 1 ) ) {
            ans += ( 1LL << T.at( i ) );
        }
        else {
            ans >>= T.at( i );
            ans ++;
            if( ( ans & 1L ) == 0LL ) {
                ans ++;
            }
            ans <<= T.at( i );
        }
    }
    std::cout << ans << std::endl;

    //  Finalize
    return( 0 );
}
