/*
    ABC235 Problem A - Rotate
        https://atcoder.jp/contests/abc235/tasks/abc235_a
        Author: Keitaro Naruse
        Date:   2022-01-15
        MIT License
*/

// # Solution
// - Read a 3-digit number and decompose it to each of the digits
// - Calculate the value

#include <iostream>
#include <string>

const bool Debug = false;

int main()
{
    //  Read ABC
    int ABC = 0;
    std::cin >> ABC;
    if( Debug ) {
        std::cerr << ABC << std::endl;
    }
    int a = ABC / 100;
    ABC %= 100;  

    int b = ABC / 10;
    ABC %= 10;

    int c = ABC;
    
    std::cout << 100 * a + 10 * b + c + 100 * b + 10 * c + a + 100 * c + 10 * a + b << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
