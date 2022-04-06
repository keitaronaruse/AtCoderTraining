/**
* @file abc225-c.cpp
* @brief ABC225 Problem C - Calendar Validator
* @author Keitaro Naruse
* @date 2022-04-06
* @copyright MIT License
* @details https://atcoder.jp/contests/abc225/tasks/abc225_c
*/

// # Solution

#include <iostream>
#include <vector>

int main()
{
    //  Read N = [ 1, 10^4 ], M = [ 1, 7 ]
    int N, M;
    std::cin >> N >> M;
    //  Read Bij = [ 1, 10^9 ]
    std::vector< std::vector < int > > B( N, std::vector< int >( M, 0 ) );
    for( int i = 0; i < N ; i ++ ) {
        for( int j = 0; j < M; j ++ ) {
            std::cin >> B.at( i ).at( j );
        }
    }
    
    //  Main
    bool isYes = false;
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return( 0 );
}
