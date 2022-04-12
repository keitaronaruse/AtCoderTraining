/**
* @file abc222-b.cpp
* @brief ABC222 Problem B - Failing Grade
* @author Keitaro Naruse
* @date 2022-04-12
* @copyright MIT License
* @details https://atcoder.jp/contests/abc222/tasks/abc222_b
*/

// # Solution

#include <iostream>
#include <vector>

int main()
{
    //  Read N = [ 1, 10^5 ], P = [ 1, 100 ]
    int N, P;
    std::cin >> N >> P;
    //  Read ai = [ 0, 100 ]
    std::vector< int > a( N );
    for( auto& p : a ) {
        std::cin >> p;
    } 

    //  Main
    int num = 0;
    for( const auto& p : a ) {
        if( p < P ) {
            num ++;
        }
    }
    std::cout << num << std::endl;

    //  Finalize
    return( 0 );
}
