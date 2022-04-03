/**
* @file abc246-b.cpp
* @brief ABC246 Problem B - Get Closer
* @author Keitaro Naruse
* @date 2022-04-02
* @copyright MIT License
* @details https://atcoder.jp/contests/abc246/tasks/abc246_b
*/

// # Solution

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    //  Read A, B
    double A, B;
    std::cin >> A >> B;

    //  Main
    double d = std::sqrt( std::pow( A, 2.0) + std::pow( B, 2.0 ) );
    double x = A / d;
    double y = B / d;
    std::cout << std::fixed << std::setprecision( 12 ) << x << " " << y << std::endl; 

    //  Finalize
    return( 0 );
}
