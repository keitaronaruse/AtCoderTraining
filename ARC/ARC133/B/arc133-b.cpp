/**
* @file arc133-b.cpp
* @brief ARC133 Problem B - Dividing Subsequence
* @author Keitaro Naruse
* @date 2022-02-03
* @copyright MIT License
* @details https://atcoder.jp/contests/arc133/tasks/arc133_b
*/

// # Solution

#include <iostream>
#include <vector>
#include <utility>

const bool Debug = true;

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

template< class T1, class T2 >
std::ostream& operator<<( std::ostream& os, const std::pair< T1, T2 >& p )
{
    os << "( " << p.first << ", " << p.second << " )";
}

int main()
{
    //  Read N = [ 1, 2*10^5 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read Pi = [ 1, N ]
    std::vector< int > P( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> P.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << P.at( i ) << " ";
        }
        std::cerr << std::endl;
    }
    //  Read Qi = [ 1, N ]
    std::vector< int > Q( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> Q.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << Q.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Main
    //  Preprocess
    std::vector< int > q_index( N + 1, 0 );
    for( int i = 0; i < N; i ++ ) {
        q_index.at( Q.at( i ) ) = i;
    }
    if( Debug ) {
        std::cerr << q_index << std::endl;
    }

    //  Make pairs of multiples
    std::vector< std::pair< int, int > > PQ;
    for( int i = 0; i < N; i ++ ) {
        for( int k = P.at( i ); k < N + 1; k += P.at( i ) ) {
            PQ.push_back( std::make_pair( i, q_index.at( k ) ) );
        }
    }
    if( Debug ) {
        std::cerr << PQ << std::endl;
    }
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
