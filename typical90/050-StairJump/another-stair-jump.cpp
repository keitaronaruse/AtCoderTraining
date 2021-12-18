/*
    050 - Stair Jump（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_ax
        Author: Keitaro Naruse
        Date:   2021-12-18
        MIT License
*/

// # Solution
//  - By dynamic programming
//  - dp[ i ] = dp[ i - 1 ] + dp[ i - L ]

#include <iostream>
#include <vector>

//  Very large Prime
const long long Large_Prime = 1000000007LL;

int main()
{
    //  Initialize
    //  Read N and K
    int N = 0, L = 0; 
    std::cin >> N >> L;
    // std::cerr << N << " " << L << std::endl;

    //  Main
    std::vector< long long > dp( N, 0 );

    //  Initialize DP
    dp.at( 0 ) = 1;
    for( int i = 1; i < L; i ++ ) {
        dp.at( i ) = dp.at( i - 1 );
    }

    //  Display the result
    std::cout << count << std::endl;
    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
