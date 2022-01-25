/**
* @file abc236-d.cpp
* @brief ABC236 Problem D - Dance
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

//  N = 2, H = 1    [ 0 ]
//  N = 4, H = 2    [ 0 ][ 1-3 ]   
//  N = 6, H = 3    [ 0 ][ 1-4 ][ 2-5 ]   
//  N = 8, H = 4    [ 0 ][ 1-5 ][ 2-6 ][ 3-7 ]
//  N = 16, H = 8   [ 0 ][ 1-9 ][ 2-10 ][ 3-11 ][ 4-12 ][ 5-13 ][ 6-14 ][ 7-15 ]

class division {
    public:
        int n, h;
        std::vector< int > first, second;
        std::vector< int > min_value, max_value;
    public:
        division( int n_ ) : n( n_ ), h( n_ / 2 ) {
            first  = std::vector< int >( h, 0 );
            second = std::vector< int >( h, 0 );
            min_value = std::vector< int >( h, 0 );
            max_value = std::vector< int >( h, 0 );
            min_value.at( 0 ) = 0;
            max_value.at( 0 ) = 0;
            for( int i = 1; i < h; i ++ ) {
                min_value.at( i ) = i;
                max_value.at( i ) = i + h;
            }
            for( int i = 0; i < h; i ++ ) {
                first.at( i ) = min_value.at( i );
            }
        }
        bool next()
        {
            return( true );
        }
};

std::ostream& operator<<( std::ostream& os, const std::vector< int >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 8 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    division d( N );
    if( Debug ) {
        std::cerr << "First:  " << d.first << std::endl;   
    }


    // //  Read Aij = [ 0, 2^30 ) 
    // std::vector< std::vector< int > > A( 2 * N, std::vector< int>( 2 * N, -1 ) );
    // for( int i = 0; i < 2 * N - 1; i ++ ) {
    //     for( int j = i + 1; j < 2 * N; j ++ ) {
    //         std::cin >> A.at( i ).at( j );
    //         A.at( j ).at( i ) = A.at( i ).at( j );
    //     }
    // }
    // if( Debug ) {
    //     for( int i = 0; i < 2 * N; i ++ ) {
    //         for( int j = 0; j < 2 * N; j ++ ) {
    //             std::cerr << A.at( i ).at( j ) << " ";
    //         }
    //         std::cerr << std::endl;
    //     }
    // }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
