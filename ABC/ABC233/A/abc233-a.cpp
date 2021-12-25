/*
    ABC233 Problem A - 10yen Stamp
        https://atcoder.jp/contests/abc233/tasks/abc233_a
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
    const int M = 10;

    //  Read X and Y
    int X = 0, Y = 0;
    std::cin >> X >> Y;

    //  Display result
    int num = 0;
    if( X >= Y ) {
        num = 0;
    }
    else {
        if( ( Y - X ) % M == 0 ) {
            num = ( Y - X ) / M;
        }
        else {
            num = ( Y - X ) / M + 1;
        }
    }
    std::cout << num << std::endl;
    
    return( 0 );
}
