/**
* @file abc244-d.cpp
* @brief ABC244 Problem D
* @author Keitaro Naruse
* @date 2022-03-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc244/tasks/abc244_d
*/

// # Solution

#include <iostream>
#include <vector>

int main()
{
    //  Constant
    int N = 3;

    //  Read Ai = [ 3 ]
    std::vector< char > S( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> S.at( i );
    }
    std::vector< char > T( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> T.at( i );
    }

    //  Main
    std::vector< int > corr( N );
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            if( S.at( i ) == T.at( j ) ) {
                corr.at( i ) = j;
                break;
            }
        }
    }
    if( 
           ( corr.at( 0 ) == 0 &&  corr.at( 1 ) == 1 && corr.at( 2 ) == 2 ) 
        || ( corr.at( 0 ) == 1 &&  corr.at( 1 ) == 2 && corr.at( 2 ) == 0 ) 
        || ( corr.at( 0 ) == 2 &&  corr.at( 1 ) == 0 && corr.at( 2 ) == 1 ) 
    ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return( 0 );
}
