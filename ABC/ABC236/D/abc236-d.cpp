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
#include <list>
#include <algorithm>
#include <bitset>

const bool Debug = true;

bool next_combination( std::vector< int >& indecies )
{
    //  N = 1   [0]
    //  N = 2   [0][ 1- 3] 
    //  N = 3   [0][ 1- 4][ 2- 5]
    //  N = 4　 [0][ 1- 5][ 2- 6][ 3- 7]
    //  N = 5　 [0][ 1- 6][ 2- 7][ 3- 8][ 4- 9]
    //  N = 6　 [0][ 1- 7][ 2- 8][ 3- 9][ 4-10][ 5-11]
    //  N = 7　 [0][ 1- 8][ 2- 9][ 3-10][ 4-11][ 5-12][ 6-13]
    //  N = 8　 [0][ 1- 9][ 2-10][ 3-11][ 4-12][ 5-13][ 6-14][ 7-15]

    //  Initialize
    const int n = indecies.size();
    std::vector< int > min_value( n, 0 ), max_value( n, 0 ); 
    min_value.at( 0 ) = 0;
    max_value.at( 0 ) = 0;
    for( int i = 1; i < n; i ++ ) {
        min_value.at( i ) = i;
        max_value.at( i ) = i + n;
    }
    //  Find the next
    bool is_available = false;
    for( int i = n - 1; i > 0; i -- ) {
        indecies.at( i ) ++;
        if( indecies.at( i ) > max_value.at( i ) ) {
            indecies.at( i ) = min_value.at( i );
        }
        else {
            is_available = true;
            break;
        }
    }
    for( int i = 2; i < n ; i ++ ) {
        if( indecies.at( i ) == min_value.at( i ) ) {
            indecies.at( i ) = indecies.at( i - 1 ) + 1;
        }
    }

    return( is_available );
}

std::ostream& operator<<( std::ostream& os, const std::vector< int >& c ) 
{
    for( auto i : c ) {
        os << i << " ";
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
    //  Read Aij = [ 0, 2^30 ) 
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
    std::vector< int > indecies( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        indecies.at( i ) = i;
    }
    do {
        if( Debug ) {
            std::cerr << indecies << std::endl; 
        }
    } while( next_combination( indecies ) );

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
