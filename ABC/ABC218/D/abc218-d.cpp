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
#include <algorithm>

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
    std::vector< std::pair< int, int > > xy( N );
    for( int i = 0; i < N; i ++ ) {
        xy.at( i ).first = x.at( i );
        xy.at( i ).second = y.at( i );
    }
    std::sort( xy.begin(), xy.end() );
    
    int answer = 0;
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            if( xy.at( i ).first < xy.at( j ).first && xy.at( i ).second < xy.at( j ).second ) {
                if( 
                    std::binary_search( xy.begin(), xy.end(), std::make_pair( xy.at( i ).first, xy.at( j ).second ) ) 
                 && std::binary_search( xy.begin(), xy.end(), std::make_pair( xy.at( j ).first, xy.at( i ).second ) )
                ) {
                    answer ++;
                }
            }
        }
    }
    std::cout << answer << std::endl;

    //  Finalize
    return( 0 );
}
