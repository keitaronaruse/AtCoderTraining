/**
* @file abc243-a.cpp
* @brief ABC243 Problem A - Shampoo
* @author Keitaro Naruse
* @date 2022-03-12, 2022-03-14
* @copyright MIT License
* @details https://atcoder.jp/contests/abc243/tasks/abc243_a
*/

// # Solution

#include <iostream>

int main()
{
    char ret = ' ';
    //  Read V, A, B, C = [ 1, 10^5 ]
    int V, A, B, C;
    std::cin >> V >> A >> B >> C;

    //  Main
    int r = V % ( A + B + C );
    if( 0 <= r && r < A ) {
        ret = 'F';
    }
    else if( A <= r && r < ( A + B ) ) {
        ret = 'M';
    }
    else if( ( A + B ) <= r && r < ( A + B + C ) ) {
        ret = 'T';
    }
    std::cout << ret << std::endl;
    
    //  Finalize
    return( 0 );
}
