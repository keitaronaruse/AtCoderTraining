/**
* @file abc220-c.cpp
* @brief ABC220 Problem C - Long Sequence
* @author Keitaro Naruse
* @date 2022-04-08
* @copyright MIT License
* @details https://atcoder.jp/contests/abc220/tasks/abc220_c
*/

// # Solution

#include <iostream>
#include <vector>
#include <map>

int main()
{
    //  Read N = [ 1, 10^5 ]
    int N;
    std::cin >> N;
    //  Read Ai = [ 1, 10^9 ]
    std::vector< long long > A( N );
    for( auto& a : A ) {
        std::cin >> a;
    }
    //  Read X = [ 1, 10^18 ]
    long long X;
    std::cin >> X;

    //  Main
    std::map< long long , int > index;
    long long sum = 0L;
    for( int i = 0; i < N; i ++ ) {
        sum += A.at( i );
        index[ sum ] = i;
    }
    auto it = index.upper_bound( X % sum );
    long long k = X / sum * ( long long ) N + ( long long ) + it -> second + 1L;
    std::cout << k << std::endl;

    //  Finalize
    return( 0 );
}
