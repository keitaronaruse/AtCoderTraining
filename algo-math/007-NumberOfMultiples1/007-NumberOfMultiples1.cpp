/**
* @file 007-NumberOfMultiples1.cpp
* @brief 007 - Number of Multiples 1
* @author Keitaro Naruse
* @date 2022-01-20
* @copyright MIT License
* @details https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_g
*/

#include <iostream>

const bool Debug = false; 

int main()
{
    //  Read N = [ 1, 10^6 ]
    int N = 0, X = 0, Y = 0;
    std::cin >> N >> X >> Y;
    if( Debug ) {
        std::cerr << N << " " << X << " " << Y << std::endl;
    }

    //  Main
    int count = 0;
    for( int i = 1; i <= N; i ++ ) {
        if( i % X == 0 || i % Y == 0 ) {
            count ++;
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
