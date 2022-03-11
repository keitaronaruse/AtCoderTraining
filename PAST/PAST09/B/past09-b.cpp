/**
* @file past09-b.cpp
* @brief PAST 9 Problem B - 穴の開いた硬貨
  @author Keitaro Naruse
* @date 2022-03-12
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_b
*/

#include <iostream>
#include <vector>

int main()
{
    //  N = [ 1, 10^5 ]
    int N;
    std::cin >> N;
    //  Ai, Bi = [ 1, 10^3 ]
    std::vector< int > A( N ), B( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i );
    }

    int num_50yen_coins = 0, num_5yen_coins = 0; 
    for( int i = 0; i < N; i ++ ) {
        int changes = B.at( i ) - A.at( i );
        if( changes % 100 >= 50 ) {
            num_50yen_coins ++;
        }
        if( changes % 10 >= 5 ) {
            num_5yen_coins ++;
        }
    }
    std::cout << num_50yen_coins + num_5yen_coins << std::endl;

    return( 0 );
}
