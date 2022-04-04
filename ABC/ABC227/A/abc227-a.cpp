/**
* @file abc227-a.cpp
* @brief ABC227 Problem A - Last Card
* @author Keitaro Naruse
* @date 2022-04-04
* @copyright MIT License
* @details https://atcoder.jp/contests/abc227/tasks/abc227_a
*/

// # Solution

#include <iostream>

int main()
{
    //  Read N, K = [ 1, 10^3 ], A = [ 1, N ]
    int N, K, A;
    std::cin >> N >> K >> A;
    
    //  Main
    std::cout << ( A - 1 + K - 1 ) % N + 1 << std::endl;

    //  Finalize
    return( 0 );
}
