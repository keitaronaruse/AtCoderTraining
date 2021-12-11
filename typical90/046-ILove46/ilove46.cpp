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
    const int M = 46;
    //  Read N
    int N = 0;
    std::cin >> N;
    //  Debug
    std::cerr << N << std::endl;

    //  Read Ai and make ai
    std::vector< int > A( N ), a( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        a.at( i ) = A.at( i ) % M;
        // Debug
        std::cerr << a.at( i ) << " ";
    }
    //  Debug
    std::cerr << std::endl;

    //  Read Bi and make bi
    std::vector< int > B( N ), b( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> B.at( i );
        b.at( i ) = B.at( i ) % M; 
        // Debug
        std::cerr << b.at( i ) << " ";
    }
    //  Debug
    std::cerr << std::endl;

    //  Read Ci and make ci
    std::vector< int > C( N ), c( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> C.at( i );
        c.at( i ) = C.at( i  ) % M;
        //  Debug
        std::cerr << c.at( i ) << " ";
    }
    //  Debug
    std::cerr << std::endl;

    //  Main
    //  
    int count = 0;
    for( int i = 0; i < M; i ++ ) {
        for( int j = 0; j < M; j ++ ) {
            for( int k = 0; k < M; k ++ ) {
                if( ( i + j + k ) % M == 0 ) {
                    count ++ ;
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
