/*
    042 - Multiple of 9（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_ap
        Author: Keitaro Naruse
        Date:   2022-01-11, 2022-01-12
        MIT License
*/

// # Solution
// - K = (d1,d2,...), d1+d2+...= 9k
// # dp(k)
// - dp[0] 
//   - 1: 1+(0)
//   - 2: 1+(1)
//   - 3: 1+(2) = 1+(1+1) 
//   - 4: 1+(3) = 1+(1+(2))
//   - k: 1+(k-1) 

#include <iostream>
#include <vector>
#include <algorithm>

const int Large_Prime = 1000000007;
const bool Debug = false;

int main()
{
    //  Read K
    int K = 0;
    std::cin >> K;
    if( Debug ) {
        std::cerr << K << std::endl;
    }

    //  Main
    const int R = 9;
    int result = 0LL;
    if( K % R == 0 ) {
        std::vector< int > dp( K + 1, 0 );
        dp.at( 0 ) = 1;
        for( int k = 1; k < K + 1; k ++ ) {
            int J = std::min( k + 1, R + 1 );
            for( int j = 1; j < J; j ++ ) {
                dp.at( k ) += dp.at( k - j );
                if( dp.at( k ) > Large_Prime ) {
                    dp.at( k ) -= Large_Prime;
                }
            }
        }
        if( Debug ) {
            for( int k = 0; k < K + 1; k ++ ) {
                std::cerr << dp.at( k ) << " ";
            }
            std::cerr << std::endl;
        }
        result = dp.at( K );
    }
    //  Display result
    std::cout << result << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
