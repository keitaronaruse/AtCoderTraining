/*
    069 - Colorful Blocks 2（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bq
        Author: Keitaro Naruse
        Date:   2021-12-21, 2022-01-02 
        MIT License
*/

// # Solution
// - Answer = K * (K-1) * (K-2)^{N-2}
// - (K-2)^n, represent n as bit and make a table

#include <iostream>
#include <vector>
#include <bitset>

const bool Debug = false;

int main()
{
    //  Initialize
    const unsigned long long  Large_Prime = 1000000007LL;
    const int Max_Bit = 64;

    //  Read N and K
    unsigned long long N = 0LL, K = 0LL;
    std::cin >> N >> K;
    if( Debug ) {
        std::cerr << N << " " << K << std::endl;
    }

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
        cases *= ( K - 1 );
        cases %= Large_Prime;

        std::bitset< Max_Bit > b( N - 2 );
        std::vector< unsigned long long > patterns( Max_Bit, 0LL );
        patterns.at( 0 ) = K - 2LL;
        for( int i = 1; i < Max_Bit; i ++ ) {
            patterns.at( i ) = patterns.at( i - 1 ) * patterns.at( i - 1 );
            patterns.at( i ) %= Large_Prime;
        }
        if( Debug ) {
            for( int i = 0; i < Max_Bit; i ++ ) {
                std::cerr << patterns.at( i ) << " ";
            }
            std::cerr << std::endl;
        }

        //  Main
        for( int i = 0; i < Max_Bit; i ++ ) {
            if( b[i] ) {
                cases *= patterns.at( i );
                cases %= Large_Prime;
            }
        }
    }

    //  Display result
    std::cout << cases << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
