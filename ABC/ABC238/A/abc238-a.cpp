/**
* @file abc238-a.cpp
* @brief ABC238 Problem A - Exponential or Quadratic 
* @author Keitaro Naruse
* @date 2022-02-06
* @copyright MIT License
* @details https://atcoder.jp/contests/abc238/tasks/abc238_a
*/

// # Solution

#include <iostream>
#include <cmath>

const bool Debug = false;

int main()
{
    //  Read N = [ 1, 10^9 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Main
    double n = ( double ) N;
    if( n * std::log( 2.0 ) > 2.0 * std::log( n ) ) {
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
