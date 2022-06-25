/**
 * @file abc257-c.cpp
 * @brief ABC257 Problem C - Robot Takahashi
 * @author Keitaro Naruse
 * @date 2022-06-25, 2022-06-26
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc257/tasks/abc257_c
 */

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

int main( ) {
    //  Read N = [ 1, 2*10^5 ]
    int N;
    std::cin >> N;
    //  Read  S, | S | = N
    std::string S;
    std::cin >> S;
    //  Read Wi = [ 1, 10^9 ]
    std::vector< int > W( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> W.at( i );
    }

    //  Main
    //  Preprocess
    int Nc = 0, Na = 0;
    std::vector< std::pair< int, char > > W_CA( N );
    for( int i = 0; i < N; i++ ) {
        W_CA.at( i ) = std::make_pair( W.at( i ), S.at( i ) );
        if( S.at( i ) == '0' ) {
            Nc++;
        } else if( S.at( i ) == '1' ) {
            Na++;
        }
    }
    std::sort( W_CA.begin( ), W_CA.end( ),
               []( std::pair< int, char > a, std::pair< int, char > b ) {
                   if( a.first == b.first ) {
                       return ( a.second < b.second );
                   } else {
                       return ( a.first < b.first );
                   }
               } );

    int answer = 0;
    if( Nc == 0 || Na == 0 ) {
        answer = N;
    } else {
        answer = Na;
        int n_correct_c = 0, n_correct_a = Na;
        for( int k = 0; k < N; k++ ) {
            if( W_CA.at( k ).second == '0' ) {
                n_correct_c++;
            } else if( W_CA.at( k ).second == '1' ) {
                n_correct_a--;
            }
            if( k == N - 1 || W_CA.at( k ).first != W_CA.at( k + 1 ).first ) {
                answer = std::max( answer, n_correct_c + n_correct_a );
            }
        }
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
