/**
* @file abc229-a.cpp
* @brief ABC229 Problem A - First Grid
* @author Keitaro Naruse
* @date 2022-03-21
* @copyright MIT License
* @details https://atcoder.jp/contests/abc229/tasks/abc229_a
*/

// # Solution

#include <iostream>
#include <string>

int main()
{
    //  Read | S | = 2
    std::string S1, S2;
    std::cin >> S1 >> S2;

    //  Main
    if(    ( S1 == "#." && S2 == ".#" ) 
        || ( S1 == ".#" && S2 == "#." )
    ) {
        std::cout << "No" << std::endl;
    }
    else {
        std::cout << "Yes" << std::endl;
    }
    
    //  Finalize
    return( 0 );
}
