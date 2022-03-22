/**
* @file abc244-a.cpp
* @brief ABC244 Problem A - Last Letter
* @author Keitaro Naruse
* @date 2022-03-20, 2022-03-21
* @copyright MIT License
* @details https://atcoder.jp/contests/abc244/tasks/abc244_a
*/

// # Solution

#include <iostream>
#include <string>

int main()
{
    //  Read N = [ 1, 10^3 ]
    int N = 0;
    std::cin >> N;

    //  Read | S | = N
    std::string S = "";
    std::cin >> S;

    //  Main
    // std::cout << S.at( S.size() - 1 ) << std::endl;
    std::cout << S.back() << std::endl;

    //  Finalize
    return( 0 );
}
