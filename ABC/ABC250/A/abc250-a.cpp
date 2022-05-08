/**
 * @file abc250-a.cpp
 * @brief ABC250 Problem A - Adjacent Squares
 * @author Keitaro Naruse
 * @date 2022-05-08
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc250/tasks/abc250_a
 */

// # Solution

#include <iostream>
#include <vector>

int main( ) {
    //  Read H, W = [ 1, 10 ], R = [ 1, H ], C = [ 1, W ]
    int H, W, R, C;
    std::cin >> H >> W >> R >> C;

    //  Main
    int answer = 0;
    if( H == 1 && W == 1 ) {
        answer = 0;
    }
    else if( H == 1 ) {
        if( C == 1 || C == W ) {
            answer = 1;
        }
        else {
            answer = 2;
        }
    }
    else if( W == 1 ) {
        if( R == 1 || R == H ) {
            answer = 1;
        }
        else {
            answer = 2;
        }
    }
    else {
        if( ( R == 1 || R == H ) && ( C == 1 || C == W ) ) {
            //  Corner cases
            answer = 2;
        }
        else if( R == 1 || R == H || C == 1 || C == W ) {
            //  Edge cases
            answer = 3;
        }
        else {
            //  Inside cases
            answer = 4;
        }
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
