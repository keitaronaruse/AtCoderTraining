/**
 * @file abc259-b.cpp
 * @brief ABC259 Problem B - Counterclockwise Rotation
 * @author Keitaro Naruse
 * @date 2022-07-09
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc259/tasks/abc259_b
 */

// # Solution

#include <iostream>
#include <iomanip>
#include <cmath>

int main( ) {
    //  Read a, b = [ -10^3, 10^3 ]
    double a, b;
    std::cin >> a >> b;
    //  Read d= [ 1, 360 ]
    double d;
    std::cin >> d;

    //  Main
    double q = d / 180.0 * M_PI;
    double a2 = a * std::cos( q ) - b * std::sin( q );
    double b2 = a * std::sin( q ) + b * std::cos( q );

    std::cout << std::fixed << std::setprecision( 20 ) << a2 << " " << b2 << std::endl;

    //  Finalize
    return ( 0 );
}
