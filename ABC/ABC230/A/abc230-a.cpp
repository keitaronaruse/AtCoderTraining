/*
    ABC230 Problem A
    A - AtCoder Quiz 3
        https://atcoder.jp/contests/abc230/tasks/abc230_a
        Author: Keitaro Naruse
        Date:   2021-12-03
        MIT License
*/

#include <iostream>
#include <cstdio>

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;

    //  Make and disply a string
    if( N >= 42 ) {
        std::printf( "AGC%03d\n", N + 1 );
    }
    else {
        std::printf( "AGC%03d\n", N );
    }

    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
