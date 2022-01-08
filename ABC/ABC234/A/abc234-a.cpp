/*
    ABC234 Problem A - Weird Function
        https://atcoder.jp/contests/abc234/tasks/abc234_a
        Author: Keitaro Naruse
        Date:   2022-01-08
        MIT License
*/

// # Solution
// - Define f(t)

#include <iostream>

const bool Debug = false;

int f( int x )
{
    return( x * x + 2 * x + 3 );
}

int main()
{
    //  Read N
    int t = 0;
    std::cin >> t;
    if( Debug ) {
        std::cerr << t << std::endl;
    }

    //  Display result
    std::cout << f( f( f( t ) + t ) + f( f( t ) ) ) << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
