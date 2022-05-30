/**
 * @file abc253-d.cpp
 * @brief ABC253 Problem D - FizzBuzz Sum Hard
 * @author Keitaro Naruse
 * @date 2022-05-28
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc253/tasks/abc253_d
 */

// # Solution

#include <iostream>
#include <algorithm>

namespace nrs {
template < class T >
T gcd( T a, T b ) {
    T dividend = ( a > b ) ? a : b;
    T divisor = ( a > b ) ? b : a;
    T residue = dividend % divisor;

    while( residue != 0 ) {
        dividend = divisor;
        divisor = residue;
        residue = dividend % divisor;
    }

    return ( divisor );
}

template < class T >
T lcm( T a, T b ) {
    long long g = nrs::gcd( a, b );
    return ( std::max( a, b ) / g * std::min( a, b ) );
}
}  // namespace nrs

int main( ) {
    //  Read N, A, B = [ 1, 10^9 ]
    long long N, A, B;
    std::cin >> N >> A >> B;

    //  Main
    long long sum_N = N * ( N + 1 ) / 2L;

    long long kA = N / A;
    long long sum_A = A * kA * ( kA + 1 ) / 2L;

    long long kB = N / B;
    long long sum_B = B * kB * ( kB + 1 ) / 2L;

    long long C = nrs::lcm( A, B );
    long long kC = N / C;
    long long sum_C = C * kC * ( kC + 1 ) / 2L;

    long long answer = sum_N - sum_A - sum_B + sum_C;
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
