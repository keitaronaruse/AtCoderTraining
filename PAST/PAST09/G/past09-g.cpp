/**
* @file past09-g.cpp
* @brief PAST 9 Problem G - 連結 
  @author Keitaro Naruse
* @date 2022-03-12
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_g
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>

int main()
{
    //  Constants
    const int K = 3;

    //  A, B = [ 1, 9 ]
    int A, B;
    std::cin >> A >> B;

    //  S1, S2, S3
    std::vector< std::string > S( K );
    for( int k = 0; k < K; k ++ ) {
        std::cin >> S.at( k );
    }

    //  Possible positions
    const int N = 9;
    std::set< std::pair< int, int > > curr_positions, prev_positions;
    curr_positions.insert( std::make_pair( A - 1, B - 1 ) );

    while( curr_positions != prev_positions ) {
        prev_positions = curr_positions;
        curr_positions.clear();
        for( auto p : prev_positions ) {
            curr_positions.insert( p );
            int v = p.first;
            int u = p.second;
            for( int h = 0; h < K; h ++ ) {
                for( int w = 0; w < K; w ++ ) {
                    if( S.at( h ).at( w ) == '#' ) {
                        if( 0 <= v + h - 1 && v + h - 1 < N && 0 <= u + w - 1 && u + w - 1 < N ) {
                            curr_positions.insert( std::make_pair( v + h - 1, u + w - 1 ) );
                        }
                    }
                }
            }
        } 
    }
    std::cout << curr_positions.size() << std::endl;

    return( 0 );
}
