/**
* @file abc245-a.cpp
* @brief ABC245 Problem A - Good morning
* @author Keitaro Naruse
* @date 2022-03-26
* @copyright MIT License
* @details https://atcoder.jp/contests/abc245/tasks/abc245_a
*/

// # Solution

#include <iostream>

int main()
{
    //  Read A, B, C, D
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    if( ( A < C ) || ( ( A == C ) && ( B <= D ) ) ) {
        std::cout << "Takahashi" << std::endl;
    }
    else {
        std::cout << "Aoki" << std::endl;
    }

    //  Finalize
    return( 0 );
}
