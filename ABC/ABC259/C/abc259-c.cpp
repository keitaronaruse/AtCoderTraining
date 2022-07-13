/**
 * @file abc259-c.cpp
 * @brief ABC259 Problem C - XX to XXX
 * @author Keitaro Naruse
 * @date 2022-07-09
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc259/tasks/abc259_c
 */

// # Solution

#include <iostream>
#include <string>

int main( ) {
    //  Read | S, T | = [ 2, 2*10^5 ]
    std::string S, T;
    std::cin >> S >> T;

    //  Main
    bool isYes = true;
    int N = S.size( ), M = T.size( );
    if( N <= M ) {
        int i = 0, j = 0;
        while( j < M ) {
            if( S.at( i ) == T.at( j ) ) {
                if( i < N - 1 ) {
                    i++;
                }
                j++;
            } else {
                if( j >= 2 && T.at( j ) == T.at( j - 1 ) &&
                    T.at( j - 1 ) == T.at( j - 2 ) ) {
                    j++;
                } else {
                    isYes = false;
                    break;
                }
            }
        }
    } else {
        isYes = false;
    }
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    //  Finalize

    return ( 0 );
}
