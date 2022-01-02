/*
    052 - Dice Product（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_az
        Author: Keitaro Naruse
        Date:   2021-12-18, 2022-01-02
        MIT License
*/

// # Solution
// - sum1 = ( A11 + A12 + ... + A16 )
// - sum2 = ( A21 + A22 + ... + A26 ) 
// - sum1 * sum2
//   = A11*A21 + A11*A22 + ... + A11*A26
//   + A12*A21 + A12*A22 + ... + A12*A26
//   + ...
//   + A16*A21 + A16*A22 + ... + A16*A26
// - sum1 * sum2 * ... * sumN

#include <iostream>
#include <vector>

//  Very large Prime
const long long Large_Prime = 1000000007LL;

const bool Debug = false;

int main()
{
    //  Initialize
    //  Constant
    const int M = 6;

    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    
    //  Read Aij and make Si
    std::vector< std::vector< int > > A( N, std::vector< int >( M, 0 ) );
    std::vector< int > S( N, 0LL );

    long long sum = 1LL;    
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < M; j ++) {
            std::cin >> A.at( i ).at( j );
            S.at( i ) += A.at( i ).at( j );
            if( Debug ) {
                std::cerr << A.at( i ).at( j ) << " ";
            }
        }
        if( Debug ) {
            std::cerr << ": " << S.at( i ) << std::endl;
        }
        sum *= ( long long ) S.at( i );
        sum %= Large_Prime;
    }

    //  Main
    //  Display results
    std::cout << sum  << std::endl;
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
