/**
* @file past09-e.cpp
* @brief PAST 9 Problem E - キーボード
  @author Keitaro Naruse
* @date 2022-03-12
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_e
*/

#include <iostream>
#include <vector>
#include <string>

bool is_left_hand( int d )
{
    if( 1 <= d && d <= 5 ) {
        return( true );
    }
    else {
        return( false );
    }
}

int main()
{
    //  N = [ 1, 2 * 10^200,000 ]
    std::string N; 
    std::cin >> N;

    //  D: digits = [ 1 - 10 ]
    const int K = N.size(); 
    std::vector< int > D( K );
    for( int i = 0; i < K; i ++ ) {
        if( N.at( i ) == '0' ) {
            D.at( i ) = 10;
        }
        else {
            D.at( i ) = N.at( i ) - '0';
        }
    }
    //  total_time 500 * K = 100,000,000
    //  The first stroke always takes 500 msec
    int total_time = 500;
    for( int i = 1; i < K; i ++ ) {
        //  Takes 301 msec if the current digit is same as the previous one
        if( D.at( i ) == D.at( i - 1 ) ) {
            total_time += 301;
        }
        //  Takes 210 msec if the current and previos digits are stroked by the same hand
        else if( is_left_hand( D.at( i ) ) && is_left_hand( D.at( i - 1 ) ) ) {
            total_time += 210;
        }
        //  Takes 210 msec if the current and previos digits are stroked by the same hand
        else if( !is_left_hand( D.at( i ) ) && !is_left_hand( D.at( i - 1 ) ) ) {
            total_time += 210;
        }
        else {
            total_time += 100;
        }
    }
    std::cout << total_time << std::endl;

    return( 0 );
}
