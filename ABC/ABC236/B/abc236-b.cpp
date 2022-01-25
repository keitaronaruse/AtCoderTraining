/**
* @file abc236-b.cpp
* @brief ABC236 Problem B - Who is missing?
* @author Keitaro Naruse
* @date 2022-01-23
* @copyright MIT License
* @details https://atcoder.jp/contests/abc236/tasks/abc236_b
*/

// # Solution

#include <iostream>
#include <vector>
#include <map>

const bool Debug = false;

int main()
{
    //  Read N 
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read Ai
    std::vector< int > A( 4 * N, 0 );
    std::map< int, int > counters;
    for( int i = 0; i < 4 * N - 1; i ++ ) {
        std::cin >> A.at( i );
        counters[ A.at( i ) ] ++;
    }
    if( Debug ) {
        for( int i = 0; i < 4 * N - 1; i ++ ) {
            std::cerr << A.at( i ) << " ";
        }
        std::cerr << std::endl;
    }
    
    for( auto p: counters ) {
        if( p.second == 3 ) {
            std::cout << p.first << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
