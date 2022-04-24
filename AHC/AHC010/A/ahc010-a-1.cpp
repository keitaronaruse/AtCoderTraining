/**
* @file ahc010-a-1.cpp
* @brief AHC010 Problem A - Loop Lines
* @author Keitaro Naruse
* @date 2022-04-24
* @copyright MIT License
* @details https://atcoder.jp/contests/ahc010/tasks/ahc010_a
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > >& vv )
{
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return( os );
}

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Constant
    const int N = 30;
    //  Read tij
    std::vector< std::vector< int > > t( N, std::vector< int >( N, 0 ) );

    for( int i = 0; i < N; i ++ ) {
        std::string s;
        std::cin >> s;
        for( int j = 0; j < N; j ++ ) {
            t.at( i ).at( j ) = s.at( j ) - '0';
        }
    }
    //  Main
    std::vector< std::vector< int > > r( N, std::vector<int>( N, 0 ) );
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            std::cout << r.at( i ).at( j );
        }
        // for( int j = 0; j < N; j ++ ) {
        //     if( 0 <= t.at( i ).at( j ) && t.at( i ).at( j ) <= 3 ) {
        //         std::cerr << "  "; 
        //     }
        //     if( 4 <= t.at( i ).at( j ) && t.at( i ).at( j ) <= 5 ) {
        //         std::cerr << "D "; 
        //     }
        //     else if( 6 <= t.at( i ).at( j ) && t.at( i ).at( j ) <= 7 ) {
        //         std::cerr << "S "; 
        //     }
        // }
        // std::cerr << std::endl;
    }

    //  Finalize
    return( 0 );
}
