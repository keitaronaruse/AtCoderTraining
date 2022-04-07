/**
* @file abc224-c.cpp
* @brief ABC224 Problem C - Triangle?
* @author Keitaro Naruse
* @date 2022-04-07
* @copyright MIT License
* @details https://atcoder.jp/contests/abc224/tasks/abc224_c
*/

// # Solution

#include <iostream>
#include <vector>

int main()
{
    //  Read N = [ 3, 300 ]
    int N;
    std::cin >> N;
    //  Read Xi, Yi = [ -10^9, 10^9 ]
    std::vector< long long > X( N ), Y( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> X.at( i ) >> Y.at( i );
    }
    
    //  Main
    //  0 <= i < j < k < N 
    int count = 0;
    for( int i = 0; i < N - 2; i ++ ) {
        for( int j = i + 1; i < j && j < N - 1; j ++ ) {
            for( int k = j + 1; j < k && k < N; k ++ ) {
                long long ax = X.at( j ) - X.at( i );
                long long ay = Y.at( j ) - Y.at( i );
                long long bx = X.at( k ) - X.at( i );
                long long by = Y.at( k ) - Y.at( i );
                if( ax * by != ay * bx ) {
                    count ++;
                }
                
            }
        }
    }
    std::cout << count << std::endl;

    //  Finalize
    return( 0 );
}
