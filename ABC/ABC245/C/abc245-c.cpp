/**
* @file abc245-c.cpp
* @brief ABC245 Problem C - Choose Elements
* @author Keitaro Naruse
* @date 2022-03-26
* @copyright MIT License
* @details https://atcoder.jp/contests/abc245/tasks/abc245_c
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace nrs {
    /**
    * @brief absolute value
    * @param[in] an integer
    * @return T absolute value of a given integer
    */    
    template < class T >
    T abs( T a )
    {
        return( ( a > 0 ) ? a : -a );
    }
}

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
    //  Read N = [ 1, 2 * 10^5 ], K = [ 0, 10^9 ]
    int N, K;
    std::cin >> N >> K;

    //  Read Ai = [ 1, 10^9 ]
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }

    //  Read Bi = [ 1, 10^9 ]
    std::vector< int > B( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> B.at( i );
    }

    //  Main
    const int M = 2;
    std::vector< std::vector< bool > > possible( M, std::vector< bool >( N, false ) );
    possible.at( 0 ).at( 0 ) = true;
    possible.at( 1 ).at( 0 ) = true;
    for( int i = 1; i < N; i ++ ) {
        //  A end
        if( possible.at( 0 ).at( i - 1 ) ) {
            //  A-A case
            if( nrs::abs( A.at( i - 1 ) - A.at( i ) ) <= K ) {
                possible.at( 0 ).at( i ) = true;
            }
            //  A-B case
            if( nrs::abs( A.at( i - 1 ) - B.at( i ) ) <= K ) {
                possible.at( 1 ).at( i ) = true;
            }
        }
        //  B end
        if( possible.at( 1 ).at( i - 1 ) ) {
            //  B-A case
            if( nrs::abs( B.at( i - 1 ) - A.at( i ) ) <= K ) {
                possible.at( 0 ).at( i ) = true;
            }
            //  B-B case
            if( nrs::abs( B.at( i - 1 ) - B.at( i ) ) <= K ) {
                possible.at( 1 ).at( i ) = true;
            }
        }
    }

    if( possible.at( 0 ).at( N - 1 ) || possible.at( 1 ).at( N - 1 ) ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return( 0 );
}
