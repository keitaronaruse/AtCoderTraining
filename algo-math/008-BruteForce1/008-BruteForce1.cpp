/**
* @file 008-BruteForce1.cpp
* @brief 008 - Brute Force 1
* @author Keitaro Naruse
* @date 2022-01-20
* @copyright MIT License
* @details https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_h
*/

#include <iostream>

const bool Debug = false; 

int main()
{
    //  Read N = [ 1, 1000 ] and S = [ 1, 2000 ]
    int N = 0, S = 0;
    std::cin >> N >> S;
    if( Debug ) {
        std::cerr << N << " " << S << std::endl;
    }

    //  Main
    int count = 0;
    for( int i = 1; i <= N; i ++ ) {
        for( int j = 1; j <= N; j ++ ) {
            if( i + j <= S ) {
                count ++;
            }
        }
    }
    //  Display the result
    std::cout << count << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
