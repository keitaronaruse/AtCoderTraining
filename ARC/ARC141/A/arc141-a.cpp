/**
 * @file arc141-a.cpp
 * @brief ARC141 Problem A - Periodic Number
 * @author Keitaro Naruse
 * @date 2022-05-29, 202206-05
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc141/tasks/arc141_a
 */

// # Solution

#include <iostream>
#include <string>
#include <vector>

namespace nrs {
    int num_digits( long long n ) {
        int num_digits = 0;
        while( n != 0L ) {
            n /= 10L;
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
}  // namespace nrs

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
        const std::string str_n( std::to_string( N.at( i ) ) );
        long long max_n = std::stoll( std::string( str_n.size( ) - 1, '9' ) );
        //  k: period length
        for( int k = 1; k <= 9; k++ ) {
            int block_num = ( int ) str_n.size( ) / k;
            int block_remainder = ( int ) str_n.size( ) % k;
            if( block_remainder == 0 && block_num >= 2 ) {
                std::string str_m = str_n.substr( 0, k );
                //  Pattern 1: "14", "10"
                std::string str = "";
                for( int j = 0; j < block_num; j++ ) {
                    str += str_m;
                }
                if( std::stoll( str ) <= N.at( i ) ) {
                    max_n = std::max( max_n, std::stoll( str ) );
                }

                //  Pattern 2: "13", "09"
                long long val_m = std::stoll( str_m ) - 1L;
                str_m = std::to_string( val_m );
                if( str_m.size() == k - 1 ) {
                    str_m = "0" + str_m;
                }
                str = "";
                for( int j = 0; j < block_num; j++ ) {
                    str += str_m;
                }
                if( std::stoll( str ) <= N.at( i ) ) {
                    max_n = std::max( max_n, std::stoll( str ) );
                }
            }
        }
        std::cout << max_n << std::endl;
    }

    //  Finalize
    return ( 0 );
}
