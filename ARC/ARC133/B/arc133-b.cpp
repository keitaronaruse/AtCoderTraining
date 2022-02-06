/**
* @file arc133-b.cpp
* @brief ARC133 Problem B - Dividing Subsequence
* @author Keitaro Naruse
* @date 2022-02-03
* @copyright MIT License
* @details https://atcoder.jp/contests/arc134/tasks/arc133_b
*/

// # Solution

#include <iostream>
#include <vector>

const bool Debug = false;

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
    std::vector< std::vector< int > > PQ( N );
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j++ ) {
            if( Q.at( j ) % P.at(i) == 0 ) {
                PQ.at( i ).push_back( j );
            }
        }
    }
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
