/**
* @file abc225-b.cpp
* @brief ABC225 Problem B - Star or Not
* @author Keitaro Naruse
* @date 2022-04-06
* @copyright MIT License
* @details https://atcoder.jp/contests/abc225/tasks/abc225_b
*/

// # Solution

#include <iostream>
#include <vector>

int main()
{
    //  Read N = [ 3, 10^5 ]
    int N;
    std::cin >> N;
    //  Read ai, bi = [ 1, N ]
    std::vector< int > a( N - 1 ), b( N - 1 );
    for( int i = 0; i < N - 1; i ++ ) {
        std::cin >> a.at( i ) >> b.at( i );
    }
    
    //  Main
    std::vector< int > degree( N + 1, 0 );
    for( int i = 0; i < N - 1; i ++ ) {
        degree.at( a.at( i ) ) ++;
        degree.at( b.at( i ) ) ++;
    }

    bool isYes = false;
    for( int i = 1; i <= N; i ++ ) {
        if( degree.at( i ) == N - 1 ) {
            isYes = true;
            break;
        }
    }
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return( 0 );
}
