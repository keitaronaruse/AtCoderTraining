/**
* @file abc236-c.cpp
* @brief ABC236 Problem C
* @author Keitaro Naruse
* @date 2022-01-23
* @copyright MIT License
* @details https://atcoder.jp/contests/abc236/tasks/abc236_c
*/

// # Solution

#include <iostream>
#include <vector>
#include <string>

const bool Debug = false;

int main()
{
    //  Read N and M
    int N = 0, M = 0;
    std::cin >> N >> M;
    if( Debug ) {
        std::cerr << N << " " << M << std::endl;
    }
    //  Read Si
    std::vector< std::string > S( N, "" );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> S.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << S.at( i ) << " ";
        }
        std::cerr << std::endl;
    }
    //  Read Tj
    std::vector< std::string > T( M, "" );
    for( int j = 0; j < M; j ++ ) {
        std::cin >> T.at( j );
    }
    if( Debug ) {
        for( int j = 0; j < M; j ++ ) {
            std::cerr << T.at( j ) << " ";
        }
        std::cerr << std::endl;
    }
    //  Main
    int j = 0;
    for( int i = 0; i < N; i ++ ) {
        //  If matched, increment j
        if( S.at( i ) == T.at( j ) ) {
            std::cout << "Yes" << std::endl;
            j ++ ;
        }
        //  If not matched, do no increment j
        else {
            std::cout << "No" << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
