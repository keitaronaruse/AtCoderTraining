/*
    ABC232 Problem A - QQ solver
        https://atcoder.jp/contests/abc232/tasks/abc232_a
        Author: Keitaro Naruse
        Date:   2021-12-19, 2022-01-10
        MIT License
*/

// # Solution
// - Read as a string and convert to interger by the ascii code 

#include <iostream>
#include <string>

const bool Debug = false;

int main()
{
    //  Read S
    std::string S;
    std::cin >> S;
    if( Debug ) {
        std::cerr << S << std::endl;;
    }

    //  Display result
    std::cout << ( S.at( 0 ) -'0' ) * ( S.at( 2 ) -'0' ) << std::endl;
    
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
