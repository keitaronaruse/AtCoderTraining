/**
 * @file abc254-b.cpp
 * @brief ABC254 Problem B - Practical Computing
 * @author Keitaro Naruse
 * @date 2022-06-04
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc254/tasks/abc254_b
 */

// # Solution

#include <iostream>
#include <vector>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) {
    for( const auto& k : v ) {
        os << k << " ";
    }
    return ( os );
}

int main( ) {
    //  Read N = [ 1, 30 ]
    int N;
    std::cin >> N;

    //  Main
    //  Preprocess and boundaries
    std::vector< std::vector< int > > A( N );
    for( int i = 0; i < N; i++ ) {
        A.at( i ) = std::vector< int >( i + 1 );
        A.at( i ).at( 0 ) = 1;
        A.at( i ).at( i ) = 1;
    }
    //  Find teh solution
    for( int i = 1; i < N; i++ ) {
        for( int j = 1; j < i; j++ ) {
            A.at( i ).at( j ) =
                A.at( i - 1 ).at( j - 1 ) + A.at( i - 1 ).at( j );
        }
    }

    //  Output the solution
    for( int i = 0; i < N; i++ ) {
        std::cout << A.at( i ) << std::endl;
    }

    //  Finalize
    return ( 0 );
}
