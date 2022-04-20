/**
* @file abc218-d.cpp
* @brief ABC218 Problem D - Rectangles
* @author Keitaro Naruse
* @date 2022-04-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc218/tasks/abc218_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <map>

int main()
{
    //  Read N = [ 4, 2*10^3 ]
    int N;
    std::cin >> N;
    //  Read xi, yi = [ 0, 10^9 ]
    std::vector< int > x( N ), y( N );
    for( int i = 0; i < N; i ++  ) {
        std::cin >> x.at( i ) >> y.at( i );
    }

    //  Main
    //  Preprocess
    std::map< int, std::vector< int > > x_pos;
    for( int i = 0; i < N; i ++ ) {
        x_pos[ x.at( i ) ].push_back( i );
    }
    //  Find the solution
    int answer = 0;
    for( auto it = x_pos.begin(); it != x_pos.end(); it ++ ) {
        if( it -> second.size() >= 2 ) {
            ;
        }
    }
    std::cout << answer << std::endl;

    //  Finalize
    return( 0 );
}
