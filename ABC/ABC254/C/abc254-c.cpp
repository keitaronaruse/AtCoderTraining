/**
 * @file abc254-c.cpp
 * @brief ABC254 Problem C - K Swap
 * @author Keitaro Naruse
 * @date 2022-06-04
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc254/tasks/abc254_c
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

template < class T >
std::ostream& operator<<( std::ostream& os,
                          const std::vector< std::vector< T > >& vv ) {
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return ( os );
}

int main( ) {
    //  Read N = [ 2, 2 * 10^5 ], K = [ 1, N - 1 ]
    int N, K;
    std::cin >> N >> K;

    //  Read Ai = [ 1, 10^9 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    //  Preprocess: Sort
    std::vector< int > Asorted = A;
    std::sort( Asorted.begin( ), Asorted.end( ) );
    //  Preprocess: Block decomposition
    std::vector< std::vector< int > > AK( K ), AsortedK( K );
    for( int i = 0; i < N; i++ ) {
        AK.at( i % K ).push_back( A.at( i ) );
        AsortedK.at( i % K ).push_back( Asorted.at( i ) );
    }

    //  Find the solution
    bool isYes = true;
    for( int k = 0; k < K; k ++ ) {
        std::sort( AK.at( k ).begin(), AK.at( k ).end() );
        if( AK.at( k ) != AsortedK.at( k ) ) {
            isYes = false;
            break;
        }
    }

    //  Output the solution
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return ( 0 );
}
