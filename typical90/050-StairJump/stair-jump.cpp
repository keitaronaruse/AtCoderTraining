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

//  Very large prime
const long long large_prime = 1000000007LL;

/*
    mod_combination()
        returns modulo by the large prime
        
*/
long long mod_combination( int n, int k )
{
    long long c = 1LL;

    for( int i = n - k + 1; i <= n; i ++ ) {
        c *= ( long long ) i;
        c %= large_prime;
    }
    for( int j = 1; j <= k; j ++ ) {
        c /= ( long long ) j;
    }
    return( c );
}

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
            patterns %= large_prime;
            std::cerr << "All 1s pattern: 1"  << std::endl;
        }
        else {
            if( k < i ) {
                patterns += mod_combination( i + 1, k );
                patterns %= large_prime;
                std::cerr << "Put " << k << "-Ls among " << i + 1 << " 1-slots"  << " " 
                << mod_combination( i + 1, k ) << std::endl;
            }
            else {
                patterns += mod_combination( k + 1, i ) ;
                patterns %= large_prime;
                std::cerr << "Put " << i << "-1s among " << k + 1 << " L-slots"  << " "
                << mod_combination( k + 1, i ) << std::endl;
            }
        }
    }
    //  Output result
    std::cout << patterns << std::endl;
    
    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
