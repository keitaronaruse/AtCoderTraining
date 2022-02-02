/**
* @file abc237-a.cpp
* @brief ABC237 Problem A - Not Overflow
* @author Keitaro Naruse
* @date 2022-01-30, 2022-02-02
* @copyright MIT License
* @details https://atcoder.jp/contests/abc237/tasks/abc237_a
*/

// # Solution
// - Represent 2^31 as long long by the bit shift operation 

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
