/*
    ABC235 Problem C - The Kth Time Query
        https://atcoder.jp/contests/abc235/tasks/abc235_c
        Author: Keitaro Naruse
        Date:   2022-01-15, 2022-01-17
        MIT License
*/

// # Solution
// - Introduce the associative memory for the counter

#include <iostream>
#include <vector>
#include <map>

const bool Debug = false;

int main()
{
    //  Read N and Q
    int N = 0, Q = 0;
    std::cin >> N >> Q;
    if( Debug ) {
        std::cerr << N << " " << Q << std::endl;
    }
    //  Read Ai
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << A.at( i ) << " ";
        }
        std::cerr << std::endl;
    }
    //  Read Xj and Kj 
    std::vector< int > X( Q, 0 ), K( Q, 0 );
    for( int j = 0; j < Q; j ++ ) {
        std::cin >> X.at( j ) >> K.at( j );
    }
    if( Debug ) {
        for( int j = 0; j < Q; j ++ ) {
            std::cerr << X.at( j ) << " " << K.at( j ) << std::endl;
        }
        std::cerr << std::endl;
    }
    
    //  Preprocess
    //  Make line counter
    std::map< int, std::vector< int > > counter;
    for( int i = 0; i < N; i ++ ) {
        counter[ A.at( i ) ].push_back( i + 1 );
    }
    //  Main
    for( int j = 0; j < Q; j ++) {
        int index = -1;
        auto it = counter.find( X.at( j ) );
        if( it != counter.end() ) {
            if( counter[ X.at( j ) ].size() >= K.at( j ) ) {
                index = counter[ X.at( j ) ].at( K.at( j ) - 1 );
            }
        }
        std::cout << index  << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
