/**
* @file abc236-d.cpp
* @brief ABC236 Problem D
* @author Keitaro Naruse
* @date 2022-01-23
* @copyright MIT License
* @details https://atcoder.jp/contests/abc236/tasks/abc236_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

const bool Debug = true;

bool next_combination()
{
    //  2N=2,   0/1, x1/0
    //  2N=4,   01/23, 02/13, 03/12, 
    //          x12/03, x13/02, x23/01
    //  2n=4,   01/23, 02/13, 03/12
    //  2N=6,   012/345, 013/245, 014/235, 015/234, 023/145, 
    //          024/135, 025/134, 034/125, 035/124, 045/123,
    //          x123/045, x124/035, x125/034, x134/025, x135/024
    //          x145/023, x234/015, x235/014, x245/013, x345/012
    //  2N=8,   0123/4567 
    return( true );
}

int main()
{
    //  Read N = [ 1, 8 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read Aij = [ 0, 2^30 ) 
    std::vector< std::vector< int > > A( 2 * N, std::vector< int>( 2 * N, -1 ) );
    for( int i = 0; i < 2 * N - 1; i ++ ) {
        for( int j = i + 1; j < 2 * N; j ++ ) {
            std::cin >> A.at( i ).at( j );
            A.at( j ).at( i ) = A.at( i ).at( j );
        }
    }
    if( Debug ) {
        for( int i = 0; i < 2 * N; i ++ ) {
            for( int j = 0; j < 2 * N; j ++ ) {
                std::cerr << A.at( i ).at( j ) << " ";
            }
            std::cerr << std::endl;
        }
    }
    std::vector< int > index;
    for( int i = 0; i < 2 * N; i ++) {
        index.push_back( i );
    }
    for( auto i : index ) {
        std::cerr << i << " ";
    }
    std::cerr << std::endl;
    for( int i = 0; i < 2 * N - 1; i ++ ) {
        for( int j = i + 1; j < 2 * N; j ++) {
            std::swap( index.at( i ), index.at( j ) );
            for( auto i : index ) {
                std::cerr << i << " ";
            }
            std::cerr << std::endl;
            std::swap( index.at( i ), index.at( j ) );
        }
    }


    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
