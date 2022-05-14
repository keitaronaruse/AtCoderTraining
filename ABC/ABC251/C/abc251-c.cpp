/**
 * @file abc251-c.cpp
 * @brief ABC251 Problem C - Poem Online Judge
 * @author Keitaro Naruse
 * @date 2022-05-14
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc251/tasks/abc251_c
 */

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) {
    for( const auto& k : v ) {
        os << k << " ";
    }
    return ( os );
}

int main( ) {
    //  Read N = [ 1, 10^5 ]
    int N;
    std::cin >> N;

    //  Read Si, | Si | = [ 1, 10 ]
    std::vector< std::string > S( N );
    std::vector< int > T( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> S.at( i ) >> T.at( i );
    }

    //  Main
    int max_score = -1, max_score_index = 0;
    std::map< std::string, int > submit;
    for( int i = 0; i < N; i++ ) {
        if( submit.find( S.at( i ) ) == submit.end( ) ) {
            submit[ S.at( i ) ] = T.at( i );
            if( max_score < T.at( i ) ) {
                max_score = T.at( i );
                max_score_index = i;
            }
        }
    }
    std::cout << max_score_index + 1 << std::endl;

    //  Finalize
    return ( 0 );
}
