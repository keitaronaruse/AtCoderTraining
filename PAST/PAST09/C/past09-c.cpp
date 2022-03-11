/**
* @file past09-c.cpp
* @brief PAST 9 Problem C - 最速正解者
  @author Keitaro Naruse
* @date 2022-03-12
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_c
*/

#include <iostream>
#include <vector>
#include <string>

int main()
{
    //  N = [ 6, 10^3 ]
    int N;
    std::cin >> N;
    //  Pi = [ A - F ], Vi = { AC, WA }
    std::vector< char > P( N );
    std::vector< std::string > V( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> P.at( i ) >> V.at( i );
    }

    const int K = 6;
    std::vector< int > first_AC( K, 0 );
    for( int i = 0; i < N; i ++ ) {
        //  Problem index
        int p = P.at( i ) - 'A';
        if( V.at( i ) == "AC" ) {
            if( first_AC.at( p ) == 0 ) {
                first_AC.at( p ) = i + 1;
                bool is_all_found = true;;
                for( int k = 0; k < K; k ++ ) {
                    if( first_AC.at( k ) == 0 ) {
                        is_all_found = false;
                        break;
                    }
                }
                if( is_all_found ) {
                    break;
                }
            }
        }
    }
    for( int k = 0; k < K; k ++ ) {
        std::cout << first_AC.at( k ) << std::endl;
    }

    return( 0 );
}
