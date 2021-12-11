/*
    ABC231 Problem A - Water Pressure
        https://atcoder.jp/contests/abc231/tasks/abc231_a        
        Author: Keitaro Naruse
        Date:   2021-12-11
        MIT License
*/

// # Solution
// - Use real numbers for representing results

#include <iostream>
#include <vector>

int main()
{
    //  Read D
    int D = 0;
    std::cin >> D;

    //  Display result
    std::cout << ( double ) D / 100.0 << std::endl;

    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
