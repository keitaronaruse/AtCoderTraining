/**
* @file abc227-b.cpp
* @brief ABC227 Problem B - KEYENCE building
* @author Keitaro Naruse
* @date 2022-04-04
* @copyright MIT License
* @details https://atcoder.jp/contests/abc227/tasks/abc227_b
*/

// # Solution

#include <iostream>
#include <vector>

int f( int a, int b )
{
    return( 4*a*b + 3*a + 3*b );
}

int main()
{
    //  Read N = [ 1, 20 ]
    int N;
    std::cin >> N;
    //  Read Si = [ 1, 10^3 ]
    std::vector< int > S( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> S.at( i );
    }

    //  Main
    int count = 0;
    for( int i = 0; i < N; i ++ ) {
        bool is_possible = false;
        bool is_loop = true;
        for( int a = 1; a <= S.at( i ) && is_loop; a ++ ) {
            for( int b = 1; b <= a && is_loop; b ++ ) {
                int v = f( a, b );
                if( v == S.at( i ) ) {
                    is_possible = true;
                    is_loop = false;
                    break;
                }
                else if( v > S.at( i ) ) {
                    break;
                }
            }
        }
        if( !is_possible ) {
            count ++;
        }
    }
    std::cout << count << std::endl;

    //  Finalize
    return( 0 );
}
