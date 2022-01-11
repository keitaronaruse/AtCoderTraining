/*
    ABC233 Problem D
        https://atcoder.jp/contests/abc233
        Author: Keitaro Naruse
        Date:   2021-12-25, 2022-01-11
        MIT License
*/

// # Solution
// - Si = A1 + A2 + ... + Ai
// - Condition: Si - Sj == K ( i > j )
// - Modified condition: Sj == Si - K
// - Counter: Sj and appearance counts by map
// - Count up: counts of Si - K 

#include <iostream>
#include <vector>
#include <map>

const bool Debug = false;

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
    //  Make the cumulative sums
    std::vector< long long > S( N + 1, 0LL );
    for( int i = 0; i < N; i ++ ) {
        S.at( i + 1 ) = S.at( i ) + ( long long ) A.at( i );
    }
    if( Debug ) {
        std::cerr << "S: ";
        for( int i = 0; i <= N; i ++ ) {
            std::cerr << S.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Register to a counter of the cumulative sums
    std::map< long long, long long > C;
    if( Debug ) {
        std::cerr << "C: ";
        for( auto c : C ) {
            std::cerr << "( " << c.first << ", " << c.second << " ) ";
        }
        std::cerr << std::endl;
    }

    //  Count the matched case by the counter
    //  C[ S.at( i ) ] == C[ S.at( j ) - K ]
    long long count = 0LL;
    for( int i = 0; i < N; i ++ ) {
        C[ S.at( i ) ] ++;
        count += C[ S.at( i + 1 ) - K ];
    } 

    //  Display result
    std::cout << count << std::endl;

    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
