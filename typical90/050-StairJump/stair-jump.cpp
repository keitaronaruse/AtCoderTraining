/*
    050 - Stair Jump（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_ax
        Author: Keitaro Naruse
        Date:   2021-12-15
        MIT License
*/

// # Solution
// - K = N / L
// - k = [ K::-1::0 ]
//   - i = N - k*L
//   - Find the number of ways to put i among k+1

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Read N and K
    int N = 0, L = 0; 
    std::cin >> N >> L;
    std::cerr << N << " " << L << std::endl;

    //  Main
    long long patterns = 0LL;
    int K = N / L; 
    for( int k = 0; k <= K; k ++ ) {
        int i = N - k * L;
        if( k == 0 ) {
            //  All 1s, only a singlepattern
            patterns ++ ;
            std::cerr << "All 1s pattern: 1"  << std::endl;
        }
        else {
            if( k < i ) {
                patterns ++ ;
                std::cerr << "Put " << k << "-Ls among " << i + 1 << " 1-slots"  << std::endl;
            }
            else {
                patterns ++ ;
                std::cerr << "Put " << i << "-1s among " << k + 1 << " L-slots"  << std::endl;
            }
        }
    }
    //  Output result
    const long long large_prime = 1000000007LL;
    std::cout << patterns % large_prime << std::endl;
    
    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
