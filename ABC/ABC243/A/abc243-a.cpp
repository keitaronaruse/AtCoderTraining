/**
* @file abc243-a.cpp
* @brief ABC243 Problem A - Shampoo
* @author Keitaro Naruse
* @date 2022-03-12
* @copyright MIT License
* @details https://atcoder.jp/contests/abc243/tasks/abc243_a
*/

// # Solution

#include <iostream>

int main()
{
    //  Read V, A, B, C = [ 1, 10^5 ]
    int V, A, B, C;
    std::cin >> V >> A >> B >> C;

    //  Main
    int v = V;
    while( true ) {
        v -= A;
        if( v < 0 ) {
            std::cout << "F" << std::endl;
            return( 0 );
        }
        v -= B;
        if( v < 0 ) {
            std::cout << "M" << std::endl;
            return( 0 );
        }
        v -= C;
        if( v < 0 ) {
            std::cout << "T" << std::endl;
            return( 0 );
        }
    }
    
    //  Finalize
    return( 0 );
}
