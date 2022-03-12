/**
* @file abc243-b.cpp
* @brief ABC243 Problem B - Hit and Blow
* @author Keitaro Naruse
* @date 2022-03-12
* @copyright MIT License
* @details https://atcoder.jp/contests/abc243/tasks/abc243_b
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    //  Read N = [ 1, 10^3 ]
    int N;
    std::cin >> N;

    //  Read Ai, Bi = [ 1, 10^9 ]
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    //  Read Bi
    std::vector< int > B( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> B.at( i );
    }

    //  Main
    //  Case 1.
    int num_hits = 0;
    for( int i = 0; i < N; i ++ ) {
        if( A.at( i ) == B.at( i ) ) {
            num_hits ++;
        }
    }
    std::cout << num_hits << std::endl;
    //  Case 2.
    int num_blows = 0;
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            if( i != j && A.at( i ) == B.at( j ) ) {
                num_blows ++;
            }
        }
    }
    std::cout << num_blows << std::endl;

    //  Finalize
    return( 0 );
}
