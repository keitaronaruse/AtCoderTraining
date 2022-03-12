/**
* @file abc243-c.cpp
* @brief ABC243 Problem C - Collision 2
* @author Keitaro Naruse
* @date 2022-03-12
* @copyright MIT License
* @details https://atcoder.jp/contests/abc243/tasks/abc243_c
*/

// # Solution

#include <iostream>
#include <vector>
#include <string>
#include <map>

int main()
{
    //  Read N = [ 2, 2 * 10^5 ]
    int N = 0;
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
        std::vector< int > x_R = y_x_R[ y ];
        std::vector< int > x_L = y_x_L[ y ];
        for( int i = 0; i < x_R.size(); i ++ ) {
            for( int j = 0; j < x_L.size(); j ++ ) {
                if( x_R.at( i ) < x_L.at( j ) ) {
                    std::cout << "Yes" << std::endl;
                    return( 0 );
                }
            }
        }
    }
    std::cout << "No" << std::endl;

    //  Finalize
    return( 0 );
}
