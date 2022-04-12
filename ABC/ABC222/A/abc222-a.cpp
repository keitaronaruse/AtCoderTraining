/**
* @file abc222-a.cpp
* @brief ABC222 Problem A - Four Digits
* @author Keitaro Naruse
* @date 2022-04-12
* @copyright MIT License
* @details https://atcoder.jp/contests/abc222/tasks/abc222_a
*/

// # Solution

#include <iostream>
#include <string>

int main()
{
    //  Read | N | = [ 1, 4 ]
    std::string N;
    std::cin >> N;

    //  Main
    std::string padding( 4 - N.size() , '0' );
    std::string S = padding + N;
    std::cout << S << std::endl;

    //  Finalize
    return( 0 );
}
