/*
    052 - Dice Product（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_az
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
    //  Constant
    const int M = 6;
    //  Read N
    int N = 0;
    std::cin >> N;
    std::cerr << N << std::endl;
    
    //  Read Aij
    std::vector< std::vector< int > > A( N, std::vector< int >( M, 0 ) );
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < M; j ++) {
            std::cin >> A.at( i ).at( j );
            std::cerr << A.at( i ).at( j ) << " ";
        }
        std::cerr << std::endl;
    }
    
    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
