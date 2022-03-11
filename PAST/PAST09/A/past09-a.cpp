/**
* @file past09-a.cpp
* @brief PAST 9 Problem A - アトラクション
  @author Keitaro Naruse
* @date 2022-03-12
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_a
*/

#include <iostream>

int main()
{
    //  H, h = [ 100, 200 ], W, w = [ 50, 100 ]
    int H, W, h, w;
    std::cin >> H >> W >> h >> w;

    if( H <= h && w <= W ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    return( 0 );
}
