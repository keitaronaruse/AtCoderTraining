/*
    048 - I will not drop out（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_av
        Author: Keitaro Naruse
        Date:   2021-12-14
        MIT License
*/

// # Solution
// - Read Ai and Bi, and calculate Ci = Ai - Bi 
// - Put Bi to S
// - Pick and remove the largers one from S
// - If it is Bj, put Cj to S

#include <iostream>
#include <vector>

int main()
{
    //  Read N and K
    int N = 0, K = 0; 
    std::cin >> N >> K;
    std::cerr << N << " " << K << std::endl;

    //  Read Ai and Bim and make Ci
    std::vector< int > A( N, 0 ), B( N, 0 ), C( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i );
        C.at( i ) = A.at( i ) - B.at( i );
        std::cerr << A.at( i ) << " " << B.at( i ) << " " << C.at( i ) << std::endl;
    }

    //  Main
    //  Output results
    // std::cout << std::endl;
    
    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
