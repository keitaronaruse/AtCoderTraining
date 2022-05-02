/**
 * @file arc131-c.cpp
 * @brief ARC131 Problem C - Zero XOR
 * @author Keitaro Naruse
 * @date 2022-05-03
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc131/tasks/arc131_c
 */

// # Solution

#include <iostream>
#include <vector>
#include <string>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) {
    for( const auto& k : v ) {
        os << k << " ";
    }
    return ( os );
}

int main( ) {
    //  Read N = [ 1, 4*10^5 ]
    int N;
    std::cin >> N;

    //  Read Ai = [ 1, 10^9 ]
    std::vector< unsigned int > A( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    bool first_win = false;
    if( N % 2 == 1 ) {
        first_win = true;
    } 
    else {
        unsigned int all_xor = 0;
        for( int i = 0; i < N; i++ ) {
            all_xor ^= A.at( i );
        }
        for( int i = 0; i < N; i++ ) {
            if( A.at( i ) == all_xor ) {
                first_win = true;
                break;
            }
        }
    }

    std::string answer = first_win ? "Win" : "Lose";
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
