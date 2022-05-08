/**
 * @file abc250-d.cpp
 * @brief ABC250 Problem D - 250-like Number
 * @author Keitaro Naruse
 * @date 2022-05-08, 2022-05-09
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc250/tasks/abc250_d
 */

// # Solution

#include <iostream>
#include <algorithm>
#include <vector>

int main( ) {
    //  Read N = [ 1, 10^18 ]
    long long N;
    std::cin >> N;

    //  Main
    //  Preprocess: Find M such as M^3 = N
    long long m;
    for( m = 1LL; m * m * m <= N; m++ ) {
        ;
    }
    const int M = ( int ) m;

    //  Preprocess: Find primes less than or eaul to M
    std::vector< bool > sieve( M + 1, true );
    sieve.at( 0 ) = false;
    sieve.at( 1 ) = false;
    for( int i = 2; i * i <= M; i++ ) {
        if( sieve.at( i ) ) {
            for( int j = i + i; j <= M; j += i ) {
                sieve.at( j ) = false;
            }
        }
    }
    std::vector< long long > primes;
    for( int i = 2; i <= M; i++ ) {
        if( sieve.at( i ) ) {
            primes.push_back( ( long long ) i );
        }
    }

    //  Find the solution
    long long answer = 0LL;
    for( size_t i = 0; i < primes.size( ); i++ ) {
        long long p = primes.at( i );
        for( size_t j = i + 1; j < primes.size( ); j++ ) {
            long long q = primes.at( j ), q3 = q * q * q;
            long long r = N / q3;
            if( p <= r && p * q3 <= N ) {
                answer++;
            } else {
                break;
            }
        }
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
