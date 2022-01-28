/**
* @file mdc.cpp
* @brief multi digit counter
* @author Keitaro Naruse
* @date 2022-01-23, 2022-01-28
* @copyright MIT License
* @details https://atcoder.jp/contests/abc236/tasks/abc236_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <list>

const bool Debug = true;

namespace nrs {
    class multi_digit_counter {
        public:
            size_t n;
            std::vector< int > digit;
            std::vector< int > max_value, min_value;
        public:
            multi_digit_counter( int n_ ) : n( n_ ) {
                digit = std::vector< int >( n, 0 );
                max_value = std::vector< int >( n, 0 );
                min_value = std::vector< int >( n, 0 );
            }
            bool set_max_value( const std::vector< int >& v ) {
                bool is_assignable = ( n == v.size() );
                if( is_assignable ) {
                    max_value = v;
                }
                return( is_assignable ); 
            }
            bool set_min_value( const std::vector< int >& v ) {
                bool is_assignable = ( n == v.size() );
                if( is_assignable ) {
                    min_value = v;
                }
                return( is_assignable ); 
            }
            bool next() {
                bool is_available = false;
                for( int i = n - 1; i >= 0; i -- ) {
                    digit.at( i ) ++;
                    if( digit.at( i ) >= max_value.at( i ) ) {
                        digit.at( i ) = min_value.at( i );
                    }
                    else {
                        is_available = true;
                        break;
                    }
                }
                return( is_available );
            }
    };
}

int main()
{
    //  Read N = [ 1, 8 ]
    int N = 8;

    //  Main
    std::vector< int > max_value( N, 0 ), min_value( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        max_value.at( i ) = 2 * ( N - i ) - 1;
        min_value.at( i ) = 0;
    }
    
    nrs::multi_digit_counter mdc( N );
    mdc.max_value = max_value;
    mdc.min_value = min_value;

    do {
        if( Debug ) {
            for( auto v : mdc.digit ) {
                std::cerr << v << " ";
            }
            std::cerr << std::endl;
        }
    } while( mdc.next() );

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
