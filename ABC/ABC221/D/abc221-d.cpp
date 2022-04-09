/**
* @file abc221-d.cpp
* @brief ABC221 Problem D - Online games
* @author Keitaro Naruse
* @date 2022-04-09
* @copyright MIT License
* @details https://atcoder.jp/contests/abc221/tasks/abc221_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
    //  Read N = [ 2, 2 * 10^5 ]
    int N;
    std::cin >> N;
    //  Read Ai, Bi = [ 1, 10^9 ]
    std::vector< int > A( N ), B( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i );
    }
    
    //  Main
    //  Preprocess
    const int M = 2000000001;
    std::vector< long long > tick( M, 0L );
    int K = 0;
    for( int i = 0; i < N; i ++ ) {
        tick.at( A.at( i ) ) ++;
        int k = A.at( i ) + B.at( i );
        tick.at( k ) --;
        K = std::max( k, K );
    }
    //  Find solution
    std::map< int, int > person_day;
    int accum = 0L;
    for( int k = 0; k <= K; k ++ ) {
        ;
    }

    //  Finalize
    return( 0 );
}
