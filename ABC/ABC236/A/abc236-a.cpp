/**
* @file abc236-a.cpp
* @brief ABC236 Problem A
* @author Keitaro Naruse
* @date 2022-01-23
* @copyright MIT License
* @details https://atcoder.jp/contests/abc236/tasks/abc236_a
*/

// # Solution

#include <iostream>
#include <vector>
#include <string>

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
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << A.at( i ) << " ";
        }
        std::cerr << std::endl;
    }
    //  Read S
    std::string S = "";
    std::cin >> S;
    if( Debug ) {
        std::cerr << S << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
