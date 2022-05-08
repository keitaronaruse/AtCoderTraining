/**
 * @file abc250-d.cpp
 * @brief ABC250 Problem D - 250-like Number
 * @author Keitaro Naruse
 * @date 2022-05-08
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc250/tasks/abc250_d
 */

// # Solution

#include <iostream>
#include <algorithm>
#include <vector>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) {
    for( const auto& k : v ) {
        os << k << " ";
    }
    return ( os );
}

int main( ) {
    //  Read N = [ 1, 10^18 ]
    long long N;
    std::cin >> N;

    //  Main
    long long m;
    for( m = 1LL; m * m * m <= N; m++ ) {
        ;
    }
    const int M = ( int ) m;
    std::vector< bool > sieve( M + 1, true );
    sieve.at( 0 ) = false;
    sieve.at( 1 ) = false;
    for( int i = 2; i <= M; i++ ) {
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

    long long answer = 0LL;
    for( size_t i = 0; i < primes.size( ); i++ ) {
        long long p = primes.at( i );
        for( size_t j = i + 1; j < primes.size( ); j++ ) {
            long long q = primes.at( j );
            if( 2 < p * q && p * q <= N && 2 < p * q * q && p * q * q <= N && 2 < p * q * q * q && p * q * q * q <= N ) {
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
