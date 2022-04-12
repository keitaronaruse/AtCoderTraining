/**
* @file abc223-c.cpp
* @brief ABC223 Problem C - Doukasen
* @author Keitaro Naruse
* @date 2022-04-12
* @copyright MIT License
* @details https://atcoder.jp/contests/abc223/tasks/abc223_c
*/

// # Solution

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& e : v ) {
        os << e << " ";
    }
    return( os );
}

int main()
{
    //  Read N [ 1, 10^5 ]
    int N;
    std::cin >> N;
    //  Read Ai, Bi = [ 1, 1000 ]
    std::vector< int > A( N ), B( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i );
    }

    //  Main
    double total_time = 0.0;
    std::vector< double > C( N );
    C.at( 0 ) = ( double ) A.at( 0 ) / ( double ) B.at( 0 );
    for( int i = 1; i < N; i ++ ) {
        C.at( i ) = C.at( i - 1 ) + ( double ) A.at( i ) / ( double ) B.at( i );
    }
    double half_time = C.at( N - 1 ) / 2.0;

    double length = 0.0;
    if( N == 1 ) {
        length = ( double ) A.at( 0 ) / 2.0;
    }
    else {
        auto it = std::lower_bound( C.begin(), C.end(), half_time );
        int k = it - C.begin() - 1;
        for( int i = 0; i <= k; i ++ ) {
            length += ( double ) A.at( i );
        }
        length += ( half_time - ( double ) C.at( k ) ) * ( double ) B.at( k + 1 );
    }
    std::cout << std::fixed << std::setprecision(12) << length << std::endl;
    
    //  Finalize
    return( 0 );
}
