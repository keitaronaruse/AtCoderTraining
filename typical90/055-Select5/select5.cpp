/*
    055 - Select 5（★2）
        https://atcoder.jp/contests/typical90/tasks/typical90_bc
        Author: Keitaro Naruse
        Date:   2021-11-30
        MIT License
*/

// # Solution
// - Ai = (ki * P + Qi)
// - Ai*Aj*...*Am 
//   = (ki * P + Ri)*(kj * P + Rj) *...* (km * P + Rm)
//   = (...)*P + Ri*Rj*...Rm
// - Ai*Aj*...*Am % P == Ri*Rj*...Rm % P

#include <iostream>
#include <vector>

int main()
{
    //  Read N, P, Q
    int N = 0, P = 0, Q = 0;
    std::cin >> N >> P >> Q;
    //  Debug
    // std::cerr << N << " " << P << " " << Q << std::endl;
    
    //  Read Ai and make Ri
    std::vector< int > A( N );
    std::vector< int > R( N );
    for( int i = 0; i != N; i ++ ) {
        std::cin >> A.at( i );
        R.at( i ) = A.at( i ) % P;
        //  Debug
        // std::cerr << A.at( i ) << ":" << R.at( i ) << " ";
    }
    //  Debug
    // std::cerr << std::endl;

    //  Make all the patterns of picking up 5 out of N
    int count = 0;
    for( int i = 0; i != N; i ++ ) {
        for( int j = i + 1; j != N; j ++ ) {
            for( int k = j + 1; k != N; k ++ ) {
                for( int l = k + 1; l != N; l ++ ) {
                    for( int m = l + 1; m != N; m ++) {
                        int index[] = { i, j, k, l, m }; 
                        //  Debug
                        // std::cerr << index[0] << " " << index[1] << " " << index[2] << " " << index[3] << " " << index[4] << std::endl;
                        long long r = (long long) R.at( index[ 0 ] ) ;
                        for( int n = 1; n != 5; n ++ ) {
                            r = ( r * (long long) R.at( index[ n ] ) ) % (long long) P;
                        }
                        if( r == (long long) Q ) {
                            count ++;
                        }
                    }
                }
            }
        }
    }

    //  Display result
    std::cout << count << std::endl;
    
    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
