/*
    ABC231 Problem A - Water Pressure
        https://atcoder.jp/contests/abc231/tasks/abc231_a        
        Author: Keitaro Naruse
        Date:   2021-12-11, 2022-01-10
        MIT License
*/

// # Solution
// - Use real numbers for representing results

#include <iostream>

const bool Debug = false;

int main()
{
    //  Read D
    int D = 0;
    std::cin >> D;
    if( Debug ) {
        std::cerr << D << std::endl;
    }

    //  Display result
    std::cout << ( double ) D / 100.0 << std::endl;

    //  Debug
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
