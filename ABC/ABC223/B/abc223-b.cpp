/**
* @file abc223-b.cpp
* @brief ABC223 Problem B - String Shifting
* @author Keitaro Naruse
* @date 2022-04-12
* @copyright MIT License
* @details https://atcoder.jp/contests/abc223/tasks/abc223_b
*/

// # Solution

#include <iostream>
#include <string>

int main()
{
    //  Read | S | = [ 1, 1000 ]
    std::string S;
    std::cin >> S;

    //  Main
    std::string S2 = S + S;
    std::string s_min = S, s_max = S;
    for( size_t i = 0; i < S.size(); i ++ ) {
        std::string s = S2.substr( i, S.size() );
        if( s < s_min ) {
            s_min = s;
        }
        if( s_max < s ) {
            s_max = s;
        }
    }
    std::cout << s_min << std::endl << s_max << std::endl;

    //  Finalize
    return( 0 );
}
