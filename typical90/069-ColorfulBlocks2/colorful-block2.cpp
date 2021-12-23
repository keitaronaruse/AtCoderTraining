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

const long long  Large_Prime = 1000000007LL;

int main()
{
    //  Initialize
    //  Read N and K
    long long N = 0LL, K = 0LL;
    std::cin >> N >> K;
    //  Debug
    std::cerr << N << " " << K << std::endl;
    
    //  Main
    std::vector< long long > dp( N, 0LL ); 

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
