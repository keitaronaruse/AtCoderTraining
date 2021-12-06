/*
    016 - Minimum Coins（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_p
        Author: Keitaro Naruse
        Date:   2021-12-06
        MIT License
*/

// # Solution
// - Loop for k, the number of coins
// - Split k into (ka, kb, kc) and judge if ka*A + kb*B + kc*C == N

#include <iostream>
#include <vector>
#include <cstdio>

int main()
{
    //  The number of maximum coins
    // const int K = 9999;
    const int K = 500;
    //  Read N, A, B, C
    int N = 0, A = 0, B = 0, C = 0;
    std::cin >> N >> A >> B >> C;
    //  Debug
    std::cerr << N << std::endl
    << A << " " << B << " " << C << std::endl;

    //  Main
    long long count = 0LL;
    for( int k = 0; k <= K; k ++ ) {
        for( int ka = 0; ka <= k; ka ++ ) {
            for( int kb = 0; kb <= k - ka; kb ++ ) {
                for( int kc = 0; kc <= k - ka - kb; kc ++ ) {
                    count ++;
                }
            }
        }
    }
    std::cerr << count << std::endl;

    //  Finalize
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
