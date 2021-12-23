/*
    069 - Colorful Blocks 2（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bq
        Author: Keitaro Naruse
        Date:   2021-12-21, 2021-12-23 
        MIT License
*/

// # Solution

#include <iostream>
#include <vector>
#include <bitset>

// # Solution
// - k = 0
// - k = 1
// - k = 63 


int main()
{
    //  Initialize
    const unsigned long long  Large_Prime = 1000000007LL;
    const int Max_Bit = 64;

    //  Read N and K
    unsigned long long N = 0LL, K = 0LL;
    std::cin >> N >> K;

    //  Main
    unsigned long long cases = K % Large_Prime;
    //  Boundary case
    if( N == 1LL ) {
        //  Do nothing
        ;
    }
    else if( N == 2LL ) {
        cases *= ( K - 1 );
        cases %= Large_Prime;
    }
    else if( N > 2LL ) {
        std::bitset< Max_Bit > b( N - 2 );
        std::cerr << b << std::endl;

        std::vector< unsigned long long > patterns( Max_Bit, 0LL );
        patterns.at( 0 ) = K - 2LL;
        for( int i = 1; i < Max_Bit; i ++ ) {
            patterns.at( i ) = patterns.at( i - 1 ) * ( K - 2LL );
            patterns.at( i ) %= Large_Prime;
        }
        //  Debug
        for( int i = 0; i < Max_Bit; i ++ ) {
            std::cerr << patterns.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Display result
    std::cout << cases << std::endl;

    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
