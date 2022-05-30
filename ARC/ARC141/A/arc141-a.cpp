/**
 * @file arc141-a.cpp
 * @brief ARC141 Problem A - Periodic Number
 * @author Keitaro Naruse
 * @date 2022-05-29
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc141/tasks/arc141_a
 */

// # Solution

#include <iostream>
#include <string>
#include <vector>

namespace nrs {
    template < class T >
    int num_digits( T n ) {
        int num_digits = 0;
        while( n != T( 0 ) ) {
            n /= T( 10 );
            num_digits++;
        }
        return ( num_digits );
    }

    long long int_pow( long long a, int k ) {
        long long pow = 1L;
        for( int i = 0; i < k; i++ ) {
            pow *= a;
        }
        return ( pow );
    }
}

int main( ) {
    //  Read T = [ 1, 10^4 ]
    int T;
    std::cin >> T;

    //  Read Ni = [ 11, 10^18 ]
    std::vector< long long > N( T );
    for( int i = 0; i < T; i++ ) {
        std::cin >> N.at( i );
    }

    //  Main
    for( int i = 0; i < T; i++ ) {
        int num_digits = nrs::num_digits( N.at( i ) );
        std::cout << num_digits << std::endl;
        std::cout << nrs::int_pow( 10L, num_digits - 1 ) - 1L << std::endl;

        const std::string str_n = std::to_string( N.at( i ) );
        long long max_n = std::stoll( std::string( str_n.size( ) - 1, '9' ) );

        //  k: period length
        for( int k = 1; k <= 9; k++ ) {
            std::string str_m;
            long long m;
            int block_remainder = str_n.size( ) % k;
            int block_num = str_n.size( ) / k;
            if( block_remainder == 0 && block_num >= 2 ) {
                std::string str_block = str_n.substr( 0, k );
                for( int j = 0; j < block_num; j++ ) {
                    str_m += str_block;
                }
                m = std::stoll( str_m );
                if( m <= N.at( i ) ) {
                    max_n = std::max( max_n, m );
                }

                str_m = "";
                str_block.at( k - 1 )--;
                for( int j = 0; j < block_num; j++ ) {
                    str_m += str_block;
                }
                m = std::stoll( str_m );
                if( m <= N.at( i ) ) {
                    max_n = std::max( max_n, m );
                }
            }
        }
        std::cout << max_n << std::endl;
    }

    //  Finalize
    return ( 0 );
}
