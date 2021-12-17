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
#include <algorithm>

//  Very large prime
const long long large_prime = 1000000007LL;

/*
    mod_combination()
        returns modulo by the large prime      
*/
int mod_combination( int n, int k )
{
    int c = 1;

    //  (n, k) == (n, n-k)
    if( k > n - k ) {
        k = n - k;
    }

    // if( ( k == 0 ) || ( k == n ) ) {
    //     c = ;
    // }
    // else if () {
    //     ;
    // }

    return( c );
}

int main()
{
    //  Read N and K
    int N = 0, L = 0; 
    std::cin >> N >> L;
    // std::cerr << N << " " << L << std::endl;

    std::vector< std::vector< int > > combination( N, std::vector<int>( N / 2 + 1 ) );

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
