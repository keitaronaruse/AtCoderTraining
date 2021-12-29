/*
    055 - Select 5（★2）
        https://atcoder.jp/contests/typical90/tasks/typical90_bc
        Author: Keitaro Naruse
        Date:   2021-11-30, 2021-12-29
        MIT License
*/

// # Solution
// - Principle
//   - Ai = (ki * P + Qi)
//   - Ai*Aj*...*Am 
//     = (ki * P + Ri)*(kj * P + Rj) *...* (km * P + Rm)
//     = (...)*P + Ri*Rj*...Rm
//   - Ai*Aj*...*Am % P == Ri*Rj*...Rm % P
// - Solution 1: Greedy
// - Solution 2: DP base

#include <iostream>
#include <vector>

const bool Debug = false;

/*
    greedy()
        returns the solution by the greedy 
*/
long long greedy( int N, int P, int Q, const std::vector< int >& R )
{
    long long count = 0LL;

    //  Make all the cases of picking up 5 out of N
    for( int i = 0; i < N; i ++ ) {
        for( int j = i + 1; j < N; j ++ ) {
            for( int k = j + 1; k < N; k ++ ) {
                for( int l = k + 1; l < N; l ++ ) {
                    for( int m = l + 1; m < N; m ++) {
                        long long r = ( long long ) R.at( i );
                        int index[] = { j, k, l, m };
                        for( int n = 0; n < 4; n ++ ) {
                            r *= ( long long ) R.at( index[ n ] );
                            r %= ( long long ) P;
                        }
                        if( r == ( long long ) Q ) {
                            count ++;
                        }
                        if( Debug ) {
                            std::cerr << i << " " << j << " " << k << " " << l << " " << m << std::endl;
                        } 
                    }
                }
            }
        }
    }
    return( count );
}

/*
    dp()
        returns the solution by the dynamic programming
        DP table
              n = 5
        R_0   Q
        R_1   Q
        ...   Q
        R_N-1 Q

*/

int main()
{
    //  Read N, P, Q
    int N = 0, P = 0, Q = 0;
    std::cin >> N >> P >> Q;
    if( Debug ) {
        std::cerr << N << " " << P << " " << Q << std::endl;
    }
    
    //  Read Ai and make Ri
    std::vector< int > A( N );
    std::vector< int > R( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        R.at( i ) = A.at( i ) % P;
        if( Debug ) {
            std::cerr << A.at( i ) << ":" << R.at( i ) << " ";
        }
    }
    if( Debug ) {
        std::cerr << std::endl;
    }

    long long count = greedy( N, P, Q, R ); 

    //  Display result
    std::cout << count << std::endl;
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;        ;
    }
    return( 0 );
}
