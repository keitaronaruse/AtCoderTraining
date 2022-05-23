/**
 * @file abc252-d.cpp
 * @brief ABC252 Problem D - Distinct Trio
 * @author Keitaro Naruse
 * @date 2022-05-21, 2022-05-22
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc252/tasks/abc252_d
 */

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) {
    for( const auto& k : v ) {
        os << k << " ";
    }
    return ( os );
}

int main( ) {
    //  Constant
    const int M = 200000;

    //  Read N = [ 3, 2*10^5 ]
    int N;
    std::cin >> N;

    //  Read Ai = [ 1, M ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    //  Preprocess
    std::vector< int > count( M + 1, 0 );
    for( int i = 0; i < N; i ++ ) {
        count.at( A.at( i ) ) ++;
    }
    
    std::vector< int > count_smaller( M + 1, 0 );
    count_smaller.at( 0 ) = count.at( 0 );
    for( int j = 1; j <= M; j ++ ) {
        count_smaller.at( j ) = count_smaller.at( j - 1 ) + count.at( j );
    }

    int answer = 0;
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
