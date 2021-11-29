/*
    055 - Select 5（★2）
        https://atcoder.jp/contests/typical90/tasks/typical90_bc
        Author: Keitaro Naruse
        Date:   2021-11-29
        MIT License
*/

// # Solution
// - Ai = (ki * P + Qi)
// - Ai*Aj*...*Am 
//   = (ki * P + Qi)*(kj * P + Qj) *...* (km * P + Qm)
//   = (...)*P + Qi*Qj*...Qm
// - Ai*Aj*...*Am % P == Qi*Qj*...Qm % P

#include <iostream>
#include <vector>

int main()
{
    //  Read N, P, Q
    int N = 0, P = 0, Q = 0;
    std::cin >> N >> P >> Q;
    //  Debug
    std::cerr << N << " " << P << " " << Q << std::endl;
    
    //  Read Ai
    std::vector< int > A( N );
    for( int i = 0; i != N; i ++ ) {
        std::cin >> A.at( i );
        //  Debug
        std::cerr << A.at( i ) << " ";
    }
    //  Debug
    std::cerr << std::endl;

    //  Make all the patterns of picking up 5 out of N
    int count = 0;
    for( int i = 0; i != N; i ++ ) {
        for( int j = i + 1; j != N; j ++ ) {
            for( int k = j + 1; k != N; k ++ ) {
                for( int l = k + 1; l != N; l ++ ) {
                    for( int m = l + 1; m != N; m ++) {
                        //  Debug
                        // std::cerr << i << " " << j << " " << k << " " << l << " " << m << std::endl;
                        count ++;
                    }
                }

            }
        }
    }

    //  Display 
    //  Debug
    std::cerr << count << std::endl;
    
    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
