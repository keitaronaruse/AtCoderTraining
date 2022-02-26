/**
* @file abc241-b.cpp
* @brief ABC241 Problem B
* @author Keitaro Naruse
* @date 2022-02-26
* @copyright MIT License
* @details https://atcoder.jp/contests/abc241/tasks/abc241_b
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = false;

std::ostream& operator<<( std::ostream& os, const std::vector< int >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read N, M = [ 1, 1000 ]
    int N = 0, M = 0;
    std::cin >> N >> M;
    if( Debug ) {
        std::cerr << N << " " << M << std::endl;
    }
    //  Read Ai
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    if( Debug ) {
        std::cerr << A << std::endl;
    }
    //  Read Bj
    std::vector< int > B( M, 0 );
    for( int j = 0; j < M; j ++ ) {
        std::cin >> B.at( j );
    }
    if( Debug ) {
        std::cerr << B << std::endl;
    }

    //  Main
    bool isYes = true;
    std::vector< bool > not_taken( N, true );
    for( int j = 0; j < M; j ++ ) {
        bool is_found = false;
        for( int i = 0; i < N; i ++ ) {
            if( B.at( j ) == A.at( i ) ) {
                if( not_taken.at( i ) ) {
                    not_taken.at( i ) = false;
                    is_found = true;
                    break;
                }
            }
        }
        if( !is_found ) {
            isYes = false;
            break;
        }
    }
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
