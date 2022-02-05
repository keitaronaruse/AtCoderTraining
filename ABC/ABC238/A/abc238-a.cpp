/**
* @file abc238-a.cpp
* @brief ABC238 Problem A
* @author Keitaro Naruse
* @date 2022-02-06
* @copyright MIT License
* @details https://atcoder.jp/contests/abc238/tasks/abc238_a
*/

// # Solution

#include <iostream>
#include <vector>
#include <string>

const bool Debug = false;

int main()
{
    //  Constant
    long long  max_value = 1LL << 31LL;
    long long  min_value = - max_value;

    //  Read N
    long long N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Main
    if( min_value <= N && N < max_value ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
