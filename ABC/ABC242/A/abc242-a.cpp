/**
* @file abc242-a.cpp
* @brief ABC242 Problem A - T-shirt
* @author Keitaro Naruse
* @date 2022-03-05
* @copyright MIT License
* @details https://atcoder.jp/contests/abc242/tasks/abc242_a
*/

// # Solution

#include <iostream>
#include <iomanip>

const bool Debug = false;

int main()
{
    //  Read A, B, C, X = [ 1, 1000 ]
    int A = 0, B = 0, C = 0, X = 0;
    std::cin >> A >> B >> C >> X;
    if( Debug ) {
        std::cerr << A << " " << B << " " << C << " " << X << std::endl;
    }

    //  Main
    double p = 0.0;
    if( X <= A ) {
        p = 1.0;
    }
    else if( B < X ) {
        p = 0.0;
    }
    else {
        p = ( double) C / ( ( double )B - ( double )A );
    }
    std::cout << std::fixed << std::setprecision( 12 ) << p << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
