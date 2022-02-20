/**
* @file abc239-a.cpp
* @brief ABC239 Problem A - Horizon
* @author Keitaro Naruse
* @date 2022-02-19, 2022-02-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc239/tasks/abc239_a
*/

// # Solution

#include <iostream>
#include <iomanip>
#include <cmath>

const bool Debug = false;

int main()
{
    //  Read h = [ 1, 10^5 ]
    int H = 0;
    std::cin >> H;
    if( Debug ) {
        std::cerr << H << std::endl;
    }

    //  Main
    double x = ( double ) H;
    double h = std::sqrt( x * ( 12800000.0 + x ) );
    std::cout << std::fixed << std::setprecision( 9 ) << h << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
