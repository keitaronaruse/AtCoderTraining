/*
    ABC230 Problem A - AtCoder Quiz 3
        https://atcoder.jp/contests/abc230/tasks/abc230_a
        Author: Keitaro Naruse
        Date:   2021-12-03, 2022-01-09
        MIT License
*/
// # Solution
// - If N > 42, display N + 1
// - Zero padding 

#include <iostream>
#include <iomanip>
#include <string>

const bool Debug = false;

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;

    //  Make and disply a string
    std::string agc = "AGC";
    std::string padding;
    std::string number;
    if( N >= 42 ) {
        padding = "0";
        number = std::to_string( N + 1 );
    }
    else if( 10 <= N  ) {
        padding = "0";
        number = std::to_string( N );
    }
    else if( N < 10 ) {
        padding = "00";
        number = std::to_string( N );
    }
    std::cout << agc << padding << number << std::endl;

    //  Debug
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;        
    }
    return( 0 );
}
