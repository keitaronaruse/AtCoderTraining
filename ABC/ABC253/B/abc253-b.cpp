/**
 * @file abc253-b.cpp
 * @brief ABC253 Problem B - Distance Between Tokens
 * @author Keitaro Naruse
 * @date 2022-05-28
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc253/tasks/abc253_b
 */

// # Solution

#include <iostream>
#include <string>
#include <vector>

namespace nrs {
    /**
    * @brief absolute value
    * @param[in] an integer
    * @return T absolute value of a given integer
    */    
    template < class T >
    T abs( T a )
    {
        return( ( a > 0 ) ? a : -a );
    }
}

int main( ) {
    //  Read N = [ 2, 100 ]
    int H, W;
    std::cin >> H >> W;

    //  Read Ai = [ 0, 10^9 ]
    std::vector< std::string > S( H );
    for( int i = 0; i < H; i++ ) {
        std::cin >> S.at( i );
    }

    //  Main
    const int K = 2;
    int idx = 0;
    std::vector<int> Pi( K ), Pj( K );
    for( int i = 0; i < H; i ++ ) {
        for(int j = 0; j < W; j ++ ) {
            if( S.at( i ).at( j ) == 'o' ) {
                Pi.at( idx ) = i;
                Pj.at( idx ) = j;
                idx ++;
            }
        }
    }
    int answer = nrs::abs( Pi.at( 0 ) - Pi.at(1) ) + nrs::abs( Pj.at( 0 ) - Pj.at(1) );
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
