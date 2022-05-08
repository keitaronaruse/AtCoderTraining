/**
 * @file agc057-a.cpp
 * @brief AGC057 Problem A
 * @author Keitaro Naruse
 * @date 2022-05-08
 * @copyright MIT License
 * @details https://atcoder.jp/contests/agc057/tasks/agc057_a
 */

// # Solution

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template < class K, class V >
std::ostream& operator<<( std::ostream& os, const std::pair< K, V >& p ) {
    os << "( " << p.first << ", " << p.second << " )";
    return ( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) {
    for( const auto& k : v ) {
        os << k << " ";
    }
    return ( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os,
                          const std::vector< std::vector< T > >& vv ) {
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return ( os );
}

int main( ) {
    //  Read T = [ 1. 10^4 ]
    int T;
    std::cin >> T;

    //  Read Li = [ 1, Ri ], Ri = [ Li, 10^9 ]
    std::vector< int > L( T ), R( T );
    for( int i = 0; i < T; i++ ) {
        std::cin >> L.at( i ) >> R.at( i );
    }

    //  Main
    for( int i = 0; i < T; i++ ) {
        int L_num_digits = 0;
        int l = L.at( i );
        while( l != 0 ) {
            L_num_digits ++; 
            l /= 10;
        }
        int R_num_digits = 0;
        int r = R.at( i );
        while( r != 0 ) {
            R_num_digits ++;
            r /= 10;
        }

        int R_digits_min = 1;
        for( int j = 1; j < R_num_digits; j ++ ) {
            R_digits_min *= 10;
        }

        int answer = 0;
        if( R_num_digits - L_num_digits == 0 ) {
            answer = R.at( i ) - L.at( i ) + 1;
        }
        else if( R_num_digits - L_num_digits == 1 ) {
            int R_high_num = R.at( i ) - R_digits_min + 1;
            int R_low_num = R_digits_min - L.at( i );
            if( R_low_num > R_high_num ) {
                if( R_high_num + R_low_num < R_digits_min ) {
                    answer = R_low_num + R_high_num;
                }
                else {
                    answer = R_digits_min;
                }
            }
            else {
                if( R_high_num < R_digits_min ) {
                    answer = R_digits_min;
                }
                else {
                    answer = R_high_num;
                }
            }
        }
        else {
            int R_high_num = R.at( i ) - R_digits_min + 1;
            int R_low_num = R_digits_min - ( R_digits_min / 10 );
            answer = std::max( R_high_num, R_low_num ); 
        }
        std::cout << answer << std::endl;
    }

    //  Finalize
    return ( 0 );
}
