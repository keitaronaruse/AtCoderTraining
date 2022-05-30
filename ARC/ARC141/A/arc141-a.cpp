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
