/**
* @file arc131-a.cpp
* @brief ARC131 Problem A - Two Lucky Numbers
* @author Keitaro Naruse
* @date 2022-05-01
* @copyright MIT License
* @details https://atcoder.jp/contests/arc131/tasks/arc131_a
*/

// # Solution

#include <iostream>
#include <vector>

int main()
{
    //  Read A, B = [ 1, 10^8 ]
    int A, B;
    std::cin >> A >> B;

    //  Main
    long long x = B * 5L + A * 1000000000L;
    std::cout << x << std::endl;

    //  Finalize
    return( 0 );
}
