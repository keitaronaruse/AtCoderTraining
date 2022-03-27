/**
* @file abc245-b.cpp
* @brief ABC245 Problem B - Mex
* @author Keitaro Naruse
* @date 2022-03-26
* @copyright MIT License
* @details https://atcoder.jp/contests/abc245/tasks/abc245_b
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 2 * 10^3 ]
    int N;
    std::cin >> N;

    //  Read Ai = [ 0, 2 * 10^3 ]
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    const int M = 2000;
    std::vector< bool > used( M + 1, false );
    for( int i = 0; i < N; i ++ ) {
        used.at( A.at( i ) ) = true;
    }

    int min_num = -1;
    for( int j = 0; j <= M; j ++ ) {
        if( !used.at( j ) ) {
            min_num = j;
            break;
        }
    }
    std::cout << min_num << std::endl;

    //  Finalize
    return( 0 );
}
