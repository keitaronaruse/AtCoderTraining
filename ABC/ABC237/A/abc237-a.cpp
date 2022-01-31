/**
* @file abc237-a.cpp
* @brief ABC237 Problem A - Not Overflow
* @author Keitaro Naruse
* @date 2022-01-30
* @copyright MIT License
* @details https://atcoder.jp/contests/abc237/tasks/abc237_a
*/

// # Solution

#include <iostream>
#include <vector>
#include <string>

const bool Debug = false;

int main()
{
    //  Constant
    long long  min_value = -2147483648LL;
    long long  max_value =  2147483648LL;

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
