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
        long long max_n = 0L;

        //  k: period length
        for( int k = 1; k <= 9; k++ ) {
            std::string str_m;
            if( ( int ) str_n.size( ) % k == 0 &&
                ( int ) str_n.size( ) / k >= 2 ) {
                std::string str_block = str_n.substr( 0, k );
                if( str_n.substr( 0, k ) > str_n.substr( k, k ) ) {
                    str_block = str_n.substr( 0, k );
                    str_block.at( k - 1 )--;
                }
                for( int j = 0; j < ( int ) str_n.size( ) / k; j++ ) {
                    str_m += str_block;
                }
                if( str_m <= str_n ) {
                    max_n = std::max( max_n, std::stoll( str_m ) );
                }
            }
            max_n = std::max( max_n, std::stoll( std::string( str_n.size( ) - 1, '9' ) ) );
        }
        std::cout << max_n << std::endl;
    }

    //  Finalize
    return ( 0 );
}
