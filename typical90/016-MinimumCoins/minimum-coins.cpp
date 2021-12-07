/*
    016 - Minimum Coins（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_p
        Author: Keitaro Naruse
        Date:   2021-12-06
        MIT License
*/

// # Solution
// - Loop i for the number of A coins
// - Loop j for the number of B coins
// - the number of C coins is determined by N = i*A + j*B + k*C

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  The number of maximum coins
    const int L = 9999;
    //  Read N, A, B, C
    int N = 0, A = 0, B = 0, C = 0;
    std::cin >> N >> A >> B >> C;
    //  Debug
    // std::cerr << N << std::endl << A << " " << B << " " << C << std::endl;
    
    //  Main
    int minimum_coins = L;
    for( int i = 0; i <= L; i ++ ) {
        for( int j = 0; j <= L - i; j ++ ) {
            long long K = ( ( long long ) N - i * (long long)A - j * B ) / C;
            if( K >= 0 ) {
                int k = ( int ) K;
                if( i * A + j * B + k * C == N ) {
                    //  Solution
                    minimum_coins = std::min( i + j + k, minimum_coins );
                }
            }
        }
    }

    //  Display result
    if( minimum_coins != L ) {
        std::cout << minimum_coins << std::endl;
    }

    //  Finalize
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
