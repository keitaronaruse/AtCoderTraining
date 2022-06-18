/**
 * @file abc256-c.cpp
 * @brief ABC256 Problem C - Filling 3x3 arrayC
 * @author Keitaro Naruse
 * @date 2022-06-18
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc256/tasks/abc256_c
 */

// # Solution

#include <iostream>

int main( ) {
    //  Read hi, wi = [ 3, 30 ]
    int h1, h2, h3, w1, w2, w3;
    std::cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    //  Main
    int answer = 0;
    for( int a = 1; a <= 28; a++ ) {
        for( int b = 1; b <= 28; b++ ) {
            for( int d = 1; d <= 28; d++ ) {
                for( int e = 1; e <= 28; e++ ) {
                    int c = h1 - a - b;
                    int f = h2 - d - e;
                    int g = w1 - a - d;
                    int h = w2 - b - e;
                    if( c >= 1 && f >= 1 && g >= 1 && h >= 1 ) {
                        int i = h3 - g - h;
                        if( i >= 1 && c + f + i == w3 ) {
                            answer++;
                        }
                    }
                }
            }
        }
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
