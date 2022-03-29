/**
* @file abc228-b.cpp
* @brief ABC228 Problem B - Takahashi's Secret
* @author Keitaro Naruse
* @date 2022-03-30
* @copyright MIT License
* @details https://atcoder.jp/contests/abc228/tasks/abc228_b
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
    //  Read N = [ 2, 10^5 ], X = [ 1, N ]
    int N, X;
    std::cin >> N >> X;

    //  Read Ai = [ 1, N ]
    std::vector< int > A( N + 1, 0 );
    for( int i = 1; i <= N; i ++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    std::vector< bool > known( N + 1, false );
    int num_knowns = 0, k = X;
    while( !known.at( k ) ) {
        known.at( k ) = true;
        num_knowns ++;
        k = A.at( k );
    }
    std::cout << num_knowns << std::endl;

    //  Finalize
    return( 0 );
}
