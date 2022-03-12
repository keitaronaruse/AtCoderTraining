/**
* @file past09-h.cpp
* @brief PAST 9 Problem H - 最長非共通部分列
  @author Keitaro Naruse
* @date 2022-03-12
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_h
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const bool Debug = true;

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > >& vv )
{
    for( const auto & v : vv ) {
        for( const auto & e : v ) {
            os << e << " ";
        }
        os << std::endl;
    }
    return( os );
}

int main()
{
    //  | S |, | T | = [ 1, 5 * 10^3 ]
    std::string S, T;
    std::cin >> S >> T;

    //  Main
    int n = S.size(), m = T.size();
    std::vector< std::vector< int > > dp( n, std::vector< int >( m, 0 ) );
    for( int i = 0; i < n; i ++ ) {
        dp.at( i ).at( 0 ) = ( S.at( i ) == T.at( 0 ) ) ? 0 : 1;
    }
    for( int j = 0; j < m; j ++ ) {
        dp.at( 0 ).at( j ) = ( S.at( 0 ) == T.at( j ) ) ? 0 : 1;
    }
    
    for( int i = 1; i < n; i ++ ) {
        for( int j = 1; j < m; j ++ ) {
            dp.at( i ).at( j ) = std::max( 
                dp.at( i - 1 ).at( j - 1 ) + ( ( S.at( i ) == T.at( j ) ) ? 0 : 1), 
                dp.at( i ).at( j - 1 )
            );
        }
    }
    std::cout << dp.at( n - 1 ).at( m - 1 ) << std::endl;

    return( 0 );
}
