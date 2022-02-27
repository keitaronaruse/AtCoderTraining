/**
* @file arc136-b.cpp
* @brief ARC136 Problem B
* @author Keitaro Naruse
* @date 2022-02-27
* @copyright MIT License
* @details https://atcoder.jp/contests/arc240/tasks/arc136_b
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const bool Debug = true;

std::ostream& operator<<( std::ostream& os, const std::vector< int >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read N = [ 3, 5000 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N <<  std::endl;
    }
    //  Read Ai
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    if( Debug ) {
        std::cerr << A << std::endl;
    }
    //  Read Bi
    std::vector< int > B( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> B.at( i );
    }
    if( Debug ) {
        std::cerr << B << std::endl;
    }

    //  Main
    std::vector< bool > is_used( N, false );
    std::vector< int > B_to_A( N, -1 );
    //  B end
    for( int i = 0; i < N; i ++ ) {
        //  A end
        for( int j = 0; j < N; j ++ ) {
            if( !is_used.at( j ) && B.at( i ) == A.at( j ) ) {
                is_used.at( j ) = true;
                B_to_A.at( i ) = j;
                break;
            }
        }
    }
    for( int i = 0; i < N; i ++ ) {
        if( !is_used.at( i ) ) {
            std::cout << "No" << std::endl;
            return( 0 );
        }
    }
    std::cerr << B_to_A << std::endl;

    //  Main
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
