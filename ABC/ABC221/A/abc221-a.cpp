/**
* @file abc221-a.cpp
* @brief ABC221 Problem A - Seismic magnitude scales 
* @author Keitaro Naruse
* @date 2022-04-11
* @copyright MIT License
* @details https://atcoder.jp/contests/abc221/tasks/abc221_a
*/

// # Solution

#include <iostream>

int main()
{
    //  Read A = [ B, 9 ], B = [ 3, A ]
    int A, B;
    std::cin >> A >> B;

    //  Main
    //  Find solution
    int scale = 1;
    for( int i = 0; i < A - B; i ++ ) {
        scale *= 32;
    }
    std::cout << scale << std::endl;

    //  Finalize
    return( 0 );
}
