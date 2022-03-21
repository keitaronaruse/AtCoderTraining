/**
* @file abc244-b.cpp
* @brief ABC244 Problem B - Go Straight and Turn Right
* @author Keitaro Naruse
* @date 2022-03-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc244/tasks/abc244_b
*/

// # Solution

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    //  Read N = [ 1, 10^5 ]
    int N = 0;
    std::cin >> N;

    //  Read | S | = T
    std::string S = "";
    std::cin >> S;

    //  Main
    int x = 0, y = 0, q = 0;
    for( int i = 0; i < N; i ++ ) {
        if( S.at( i ) == 'S' ) {
            switch( q ) {
                case 0: x ++ ; break;
                case 1: y ++ ; break;
                case 2: x -- ; break;
                case 3: y -- ; break;
                default: break;
            }
        }
        else if( S.at( i ) == 'R' ) {
            switch( q ) {
                case 0: q = 3; break;
                case 1: q = 0; break;
                case 2: q = 1; break;
                case 3: q = 2; break;
                default: break;
            }
        } 
    }
    std::cout << x << " " << y << std::endl;

    //  Finalize
    return( 0 );
}
