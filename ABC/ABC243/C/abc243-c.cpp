/**
* @file abc243-c.cpp
* @brief ABC243 Problem C - Collision 2
* @author Keitaro Naruse
* @date 2022-03-12, 2022-03-14
* @copyright MIT License
* @details https://atcoder.jp/contests/abc243/tasks/abc243_c
*/

// # Solution

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

int main()
{
    //  Read N = [ 2, 2 * 10^5 ]
    int N;
    std::cin >> N;
    //  Read Xi, Yi = [ 0, 10^9 ]
    std::vector< int > X( N, 0 ), Y( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> X.at( i ) >> Y.at( i );
    }
    //  Read S
    std::string S;
    std::cin >> S;

    //  Main
    std::map< int, std::vector< int > > y_x_R, y_x_L;
    for( int i = 0; i < N; i ++ ) {
        if( S.at( i ) == 'R' ) {
            y_x_R[ Y.at( i ) ].push_back( X.at( i ) );
        }
        else if( S.at( i ) == 'L' ) {
            y_x_L[ Y.at( i ) ].push_back( X.at( i ) );
        }
    }

    for( auto p : y_x_R ) {
        int y = p.first;
        std::vector< int > x_R =  y_x_R[ y ];
        std::sort( x_R.begin(), x_R.end() );

        std::vector< int > x_L = y_x_L[ y ];
        std::sort( x_L.begin(), x_L.end() );

        if( x_R.size() != 0 && x_L.size() != 0 ) {
            if( x_R.at( 0 ) < x_L.at( x_L.size() - 1 ) ) {
                std::cout << "Yes" << std::endl;
                return( 0 );
            }
        }
    }
    std::cout << "No" << std::endl;

    //  Finalize
    return( 0 );
}
