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

// - Mange overflow as calculting the combination 
//   by reducing multipliers by divisors

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

//  Very large prime
const long long large_prime = 1000000007LL;

/*
    mod_combination()
        returns modulo by the large prime      
*/
long long mod_combination( const std::vector< long long >& mod_factorial, int n, int k )
{
    long long mod_combination = 0LL;
    
    //  Boundary
    if( ( k == 0 ) || ( k == n ) ) {
        return(mod_combination)
    }

    //  (n, k) == (n, n-k)
    if( k > n - k ) {
        k = n - k;
    }

    //  
    return( mod_combination );
}

int main()
{
    //  Read N and K
    int N = 0, L = 0; 
    std::cin >> N >> L;
    // std::cerr << N << " " << L << std::endl;

    std::vector< long long > mod_factorial( N, 0LL );
    mod_factorial.at( 0 ) = 1LL;
    for( int i = 1; i < N; i ++ ) {
        mod_factorial.at( i ) 
        = mod_factorial.at( i - 1 ) * ( long long )( i + 1 ) % large_prime;
        if( i % 1000 == 0 ) {
            std::cerr << mod_factorial.at( i )  << std::endl;
        }
    }

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
