/**
* @file abc248-b.cpp
* @brief ABC248 Problem B - Slimes
* @author Keitaro Naruse
* @date 2022-04-16
* @copyright MIT License
* @details https://atcoder.jp/contests/abc248/tasks/abc248_b
*/

// # Solution

#include <iostream>

int main()
{
    //  Read A = [ 1, B ], B = [ A, 10^9 ], K = [ 2, 10^3 ]
    long long A, B, K;
    std::cin >> A >> B >> K;

    //  Main
    int answer = 0;
    long long a = A;
    while( a < B ) {
        a *= K;
        answer ++;
    }
    std::cout << answer << std::endl;
    
    //  Finalize
    return( 0 );
}
