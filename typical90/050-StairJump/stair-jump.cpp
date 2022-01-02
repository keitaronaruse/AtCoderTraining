/*
    050 - Stair Jump（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_ax
        Author: Keitaro Naruse
        Date:   2021-12-18, 2022-01-02
        MIT License
*/

// # Solution
//  - By dynamic programming
//  - dp[ i ] = dp[ i - 1 ] + dp[ i - L ]

#include <iostream>
#include <vector>

//  Very large Prime
const long long Large_Prime = 1000000007LL;

const bool Debug = false;

int main()
{
    //  Initialize
    //  Read N and K
    int N = 0, L = 0; 
    std::cin >> N >> L;
    if( Debug ) {
        std::cerr << N << " " << L << std::endl;
    }

    //  Main
    std::vector< long long > dp( N + 1, 0 );

    //  Initialize DP
    dp.at( 0 ) = 1L;
    for( int i = 1; i <= N; i ++ ) {
        if( i < L ) {
            dp.at( i ) = dp.at( i - 1 );
        }
        else {
            dp.at( i ) = ( dp.at( i - 1 ) + dp.at( i - L ) ) % Large_Prime;
        }
    }
    //  Display the result
    std::cout << dp.at( N ) << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
