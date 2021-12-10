/*
    046 - I Love 46（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_at
        Author: Keitaro Naruse
        Date:   2021-12-11
        MIT License
*/

// # Solution
// - M = 46
// - i = [ 0 :: M - 1 ]
// - j = [ 0 :: M - 1 ]
// - k = [ 0 :: M - 1 ]
//  ( i + j + k ) % M == 0

#include <iostream>
#include <vector>
#include <utility>

int main()
{
    //  Read N and Q
    // int N = 0, Q = 0;
    // std::cin >> N >> Q;
    //  Debug
    // std::cerr << N << " " << Q << std::endl;

    //  Read Ai
    // std::vector< int > A( N );
    // for( int i = 0; i < N; i ++ ) {
    //     std::cin >> A.at( i );
        //  Debug
        // std::cerr << A.at( i ) << " ";
    // }
    //  Debug
    // std::cerr << std::endl;

    //  Main
    const int M = 46;
    //  ( i + j + k ) % M == 0
    int count = 0;
    for( int i = 0; i < M; i ++ ) {
        for( int j = 0; j < M; j ++ ) {
            for( int k = 0; k < M; k ++ ) {
                count ++ ;
            }
        }
    }
    std::cerr << count << std::endl;
    
    //  Finalize
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
