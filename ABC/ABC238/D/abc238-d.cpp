/**
* @file abc238-d.cpp
* @brief ABC238 Problem D - AND and SUM
* @author Keitaro Naruse
* @date 2022-02-07
* @copyright MIT License
* @details https://atcoder.jp/contests/abc238/tasks/abc238_d
*/

// # Solution
// - x XOR y = s - 2*a
// - x AND y = a
//            x: 0 0 1 1
//            y: 0 1 0 1
//  p = x XOR y: 0 1 1 0 
//  q = x AND y: 0 0 0 1
// - Never happnes -> No
//   - s < 2*a
//   - p == 1 and q == 1 -> No

#include <iostream>
#include <vector>
#include <bitset>

const bool Debug = false;

int main()
{
    //  Read T = [ 1, 10^5 ]
    int T = 0;
    std::cin >> T;
    if( Debug ) {
        std::cerr << T << std::endl;
    }
    //  Read si, ai = [ 0, 2^60 ]
    std::vector< unsigned long long > a( T, 0uLL ), s( T, 0uLL );
    for( int i = 0; i < T; i ++ ) {
        std::cin >> a.at( i ) >> s.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < T; i ++ ) {
            std::cerr << a.at( i ) << " " << s.at( i ) << std::endl;
        }
    }

    //  Main
    for( int i = 0; i < T; i ++ ) {
        bool isYes = true;
        if( s.at( i ) < 2uLL * a.at( i ) ) {
            isYes = false;
        }
        else {
            std::bitset< 60 > p( s.at( i ) - 2uLL * a.at( i ) );
            std::bitset< 60 > q( a.at( i ) );
            if( Debug ) {
                std::cerr << p << std::endl << q << std::endl;
            }
            //            x: 0 0 1 1
            //            y: 0 1 0 1
            //  p = x XOR y: 0 1 1 0 
            //  q = x AND y: 0 0 0 1
            //  Never happnes: p == 1 and q == 1
            isYes = true;
            for( int k = 0; k < 60; k ++ ) {
                if( p[ k ] && q[ k ] ) {
                    isYes = false;
                    break;
                }
            }
        }
        if( isYes ) {
            std::cout << "Yes" << std::endl;
        }
        else {
            std::cout << "No" << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
