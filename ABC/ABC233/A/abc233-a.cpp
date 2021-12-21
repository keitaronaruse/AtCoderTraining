/*
    ABC233 Problem A
        https://atcoder.jp/contests/abc233
        Author: Keitaro Naruse
        Date:   2021-12-25
        MIT License
*/

// # Solution
// - 

#include <iostream>
#include <string>

int main()
{
    //  Read S
    std::string S;
    std::cin >> S;

    //  Display result
    std::cout << ( S.at( 0 ) -'0' ) * ( S.at( 2 ) -'0' ) << std::endl;
    
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
