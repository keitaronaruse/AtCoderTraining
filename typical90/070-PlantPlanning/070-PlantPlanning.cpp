/*
* @file 070-PlantPlanning.cpp
* @brief 070 - Plant Planning（★4）
* @author Keitaro Naruse
* @date 2022-01-29
* @copyright MIT License
* @details https://atcoder.jp/contests/typical90/tasks/typical90_br
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = true;

int main()
{
    //  Read N = [ 1, 10^5 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read Xi and Yi = [ -10^9, 10^9 ]
    std::vector< int > X( N, 0 ), Y( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> X.at( i ) >> Y.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << X.at( i ) << " " << Y.at( i ) << std::endl;
        }
    }

    //  Main
    //  Preprocess
    std::vector< int > x( N , 0 ), y( N, 0 );
    //  org  x: -1  0  1 -2  4
    //  sort x: -2 -1  0  1  4
    //  offs x:  0  1  2  3  6
    //  Divide at 0: (-, 1+2+3+6) -> 12
    //  Divide at 1: (1, 1+2+5) -> 9
    //  Divide at 2: (2+1, 1+4) -> 8 <- !
    //  Divide at 3: (3+2+1, 3) -> 9
    //  Divide at 6: (6+5+4+3, -) -> 18
    //  Display the result
    std::cout << "" << std::endl;
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
