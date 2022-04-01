/**
* @file abc227-c.cpp
* @brief ABC227 Problem C - ABC conjecture
* @author Keitaro Naruse
* @date 2022-04-01
* @copyright MIT License
* @details https://atcoder.jp/contests/abc227/tasks/abc227_c
*/

// # Solution

#include <iostream>

long long find_num_b_c( long long b, long long M )
{
    long long count = 0L;
    long long c = M / b;
    while( b <= c ) {
        count += ( c - b + 1 );
        b ++;
        c = M / b;
    }
    return( count );
}

int main()
{
    //  Read N = [ 1, 10^11 ]
    long long N;
    std::cin >> N;
    
    //  Main
    long long count = 0L;
    for( long long k = 1L; k * k * k <= N; k ++ ) {
        count += find_num_b_c( k, N / k );
    }

    std::cout << count << std::endl;

    //  Finalize
    return( 0 );
}
