/**
* @file abc248-c.cpp
* @brief ABC248 Problem C - Dice Sum
* @author Keitaro Naruse
* @date 2022-04-16
* @copyright MIT License
* @details https://atcoder.jp/contests/abc248/tasks/abc248_c
*/

// # Solution

#include <iostream>
#include <vector>

const int P = 998244353;

int main()
{
    //  Read N
    int N, M, K;
    std::cin >> N >> M >> K;

    //  Main
    //  Preprocess
    std::vector< std::vector< int > > dp( N + 1, std::vector< int > ( K + 1, 0 ) );
    dp.at( 0 ).at( 0 ) = 1;
    for( int i = 1; i <= N; i ++ ) {
        for( int k = 1; k <= K; k ++ ) {
            for( int j = 1; j <= M; j ++ ) {
                if( k - j >= 0 ) {
                    dp.at( i ).at( k ) += dp.at( i - 1 ).at( k - j );
                    if( dp.at( i ).at( k ) > P ) {
                        dp.at( i ).at( k ) %= P;
                    }
                }
            }
        }
    }
    //  Find the solution
    int answer = 0;
    for( int k = 1; k <= K; k ++ ) {
        answer += dp.at( N ).at( k );
        if( answer > P ) {
            answer %= P;;
        }
    }
    std::cout << answer << std::endl;
    
    //  Finalize
    return( 0 );
}
