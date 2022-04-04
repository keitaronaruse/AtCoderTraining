/**
* @file abc246-d.cpp
* @brief ABC246 Problem D - 2-variable Function
* @author Keitaro Naruse
* @date 2022-04-02, 2022-04-04
* @copyright MIT License
* @details https://atcoder.jp/contests/abc246/tasks/abc246_d
*/

// # Solution

#include <iostream>
#include <algorithm>

long long f( long long a, long long b ) 
{
    return( a*a*a + a*a*b + a*b*b + b*b*b );
}

int main()
{
    //  Read N = [ 0, 10^18 ]
    long long N;
    std::cin >> N;

    //  Main
    long long a = 0L, b = 1000000L, X = 4000000000000000001L;
    while( a <= b ) {
        long long F = f( a, b );
        if( F >= N ) {
            X = std::min( X, F );
            b --;
        }
        else {
            a ++;
        }
    }
    std::cout << X << std::endl;

    //  Finalize
    return( 0 );
}
