/**
* @file arc134-a.cpp
* @brief ARC134 Problem A
* @author Keitaro Naruse
* @date 2022-01-29
* @copyright MIT License
* @details https://atcoder.jp/contests/arc134/tasks/arc134_a
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::ostream& operator<<( std::ostream& os, const std::vector< int >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

const bool Debug = true;

int main()
{
    //  Read N = [ 1, 2 * 10^5 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read Ai = [ 1, N ]
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

    //  Main
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
