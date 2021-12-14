/*
    048 - I will not drop out（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_av
        Author: Keitaro Naruse
        Date:   2021-12-14
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
    // std::cerr << N << std::endl;

    //  Read Ai and make ai
    std::vector< int > A( N, 0 ), a( M, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        a.at( A.at( i ) % M ) ++;
        // std::cerr << a.at( i ) << " ";
    }
    // std::cerr << std::endl;

    //  Debug
    // for( int j = 0; j < M; j ++ ) {
    //     std::cerr << a.at( j ) << " ";
    // }
    // std::cerr << std::endl;

    //  Read Bi and make bi
    std::vector< int > B( N, 0 ), b( M, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> B.at( i );
        b.at( B.at( i ) % M ) ++;
        // std::cerr << b.at( i ) << " ";
    }
    // std::cerr << std::endl;

    //  Debug
    // for( int j = 0; j < M; j ++ ) {
    //     std::cerr << b.at( j ) << " ";
    // }
    // std::cerr << std::endl;

    //  Read Ci and make ci
    std::vector< int > C( N, 0 ), c( M, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> C.at( i );
        c.at( C.at( i ) % M ) ++;
        // std::cerr << c.at( i ) << " ";
    }
    // std::cerr << std::endl;

    //  Debug
    // for( int j = 0; j < M; j ++ ) {
    //     std::cerr << c.at( j ) << " ";
    // }
    // std::cerr << std::endl;

    //  Main
    long long  count = 0LL;
    for( int i = 0; i < M; i ++ ) {
        for( int j = 0; j < M; j ++ ) {
            int k = ( ( M - i ) + ( M - j ) ) % M;
            count += ( long long ) a.at( i ) * ( long long ) b.at( j ) * ( long long ) c.at( k );
        }
    }
    //  Output results
    std::cout << count << std::endl;
    
    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
