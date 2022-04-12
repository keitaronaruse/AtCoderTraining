/**
* @file abc222-c.cpp
* @brief ABC222 Problem C - Swiss-System Tournament
* @author Keitaro Naruse
* @date 2022-04-12
* @copyright MIT License
* @details https://atcoder.jp/contests/abc222/tasks/abc222_c
*/

// # Solution

#include <iostream>
#include <vector>
#include <string>

int main()
{
    //  Read N = [ 1, 50 ], M = [ 1, 100 ]
    int N, M;
    std::cin >> N >> M;
    //  Read Aij = [ 0, 100 ]
    std::vector< std::string > A( 2 * N );
    for( auto& a : A ) {
        std::cin >> a;
    } 

    //  Main
    int num = 0;
    for( const auto& p : a ) {
        if( p < P ) {
            num ++;
        }
    }
    std::cout << num << std::endl;

    //  Finalize
    return( 0 );
}
