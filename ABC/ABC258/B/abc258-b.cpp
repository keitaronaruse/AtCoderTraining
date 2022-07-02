/**
 * @file abc258-b.cpp
 * @brief ABC258 Problem B - Number Box
 * @author Keitaro Naruse
 * @date 2022-07-02
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc258/tasks/abc258_b
 */

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main( ) {
    //  Read N = [ 1, 10 ]
    int N;
    std::cin >> N;

    //  Read Ai = [ 1, 9 ]
    std::vector< std::vector< char > > A( N, std::vector< char >( N ) );
    for( int i = 0; i < N; i++ ) {
        for( int j = 0; j < N; j++ ) {
            std::cin >> A.at( i ).at( j );
        }
    }

    //  Main
    std::string answer = "";
    const int K = 8;
    std::vector< int > dh = { 1, 1, 0, -1, -1, -1, 0, 1 };
    std::vector< int > dw = { 0, 1, 1, 1, 0, -1, -1, -1 };
    for( int h = 0; h < N; h++ ) {
        for( int w = 0; w < N; w++ ) {
            for( int k = 0; k < K; k++ ) {
                std::string number( N, ' ');
                int v = h, u = w;
                for( int i = 0; i < N; i++ ) {
                    number.at( i ) = A.at( v ).at( u );
                    v = ( v + dh.at( k ) + N ) % N;
                    u = ( u + dw.at( k ) + N ) % N;
                }
                // std::cout << h << " " << w << " " << k << " ";
                // std::cout << number << std::endl;
                answer = std::max( answer, number );
            }
        }
    }
    std::cout << answer << std::endl;
    //  Finalize
    return ( 0 );
}
