/*
    ABC233 Problem D
        https://atcoder.jp/contests/abc233
        Author: Keitaro Naruse
        Date:   2021-12-25, 2022-01-11
        MIT License
*/

// # Solution
// - Ci = A1 + A2 + ... + Ai
// - Ci - Cj = (A1 + A2 + ... + Ai) - (A1 + A2 + ... + Aj)
//           = Aj+1 + Aj+2 + ... Ai


#include <iostream>
#include <vector>

const bool Debug = true;

int main()
{
    //  Read N and K
    int N = 0;
    long long K = 0LL;
    std::cin >> N >> K;
    if( Debug ) {
        std::cerr << N << " " << K << std::endl;
    }
    //  Read Ai and make Bi
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    if( Debug ) {
        std::cerr << "A: ";
        for( int i = 0; i < N; i ++ ) {
            std::cerr << A.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Main
    //  Make a cumulative sum to i
    //  Boundary: C.at( 0 ) = 0
    //  C.at( 1 ) = A.at( 0 ) + C.at( 0 ) = A.at( 0 )
    std::vector< long long > C( N + 1, 0LL );
    for( int i = 0; i < N; i ++ ) {
        C.at( i + 1 ) = C.at( i ) + ( long long ) B.at( i );
    }
    if( Debug ) {
        std::cerr << "C: ";
        for( int i = 0; i <= N; i ++ ) {
            std::cerr << C.at( i ) << " ";
        }
        std::cerr << std::endl;
    }
    //  Make Count 
    long long count = 0LL;
    std::vector< int > D( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        for( int j = i + 1; j <= N; j ++ ) {
            if( C.at( j ) - C.at( i ) == K ) {
                D.at( i ) ++;
                count ++;
            }
        }
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << D.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Display result
    std::cout << count << std::endl;
    
    return( 0 );
}
