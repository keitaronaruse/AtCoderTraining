/*
    ABC233 Problem A - 10yen Stamp
        https://atcoder.jp/contests/abc233/tasks/abc233_a
        Author: Keitaro Naruse
        Date:   2021-12-25, 2022-01-11
        MIT License
*/

// # Solution
// - Calculate ( Y - X ) / 10 and round it up 

#include <iostream>
#include <string>

int div_ceil( int a, int b )
{
    return( ( a + b - 1 ) / b );
}

const bool Debug = true;

int main()
{
    const int M = 10;

    //  Read X and Y
    int X = 0, Y = 0;
    std::cin >> X >> Y;
    if( Debug ) {
        std::cerr << X << " " << Y << std::endl;
    }

    //  Caluculate the number
    int num = 0;
    if( X >= Y ) {
        num = 0;
    }
    else {
        num = div_ceil( Y - X, M );
    }

    //  Display the result
    std::cout << num << std::endl;
    
    return( 0 );
}
