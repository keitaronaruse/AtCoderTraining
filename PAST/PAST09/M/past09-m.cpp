/**
* @file past09-m.cpp
* @brief PAST 9 Problem M - 名前の変更
  @author Keitaro Naruse
* @date 2022-03-22
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_m
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) 
{
    for( auto k : v ) {
        os << k << " ";
    }
    os << std::endl;
    return( os );
}

int main()
{
    //  Read N, Q = [ 1, 10^5 ]
    int N, Q;
    std::cin >> N >> Q;

    //  Read S( N )
    std::vector< std::string > S( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> S.at( i );
    }

    //  Read X( Q ), T( Q )
    std::vector< int > X( Q );
    std::vector< std::string > T( Q );
    for( int j = 0; j < Q; j ++ ) {
        std::cin >> X.at( j ) >> T.at( j );
    }

    //  Main
    //  Master name list M( N + Q )
    std::vector< std::string > M( N + Q );
    //  Copy S to M
    std::copy( S.begin(), S.end(), std::back_inserter( M ) );
    //  Copy T to M
    std::copy( T.begin(), T.end(), std::back_inserter( M ) );
    //  Sort and erase duplicates
    std::sort( M.begin(), M.end() );
    M.erase( std::unique( M.begin(), M.end() ), M.end() );

    //  Make S -> id in M table
    std::vector< int > s_id( N );
    for( int i = 0; i < N; i ++ ) {
        s_id.at( i ) = std::lower_bound( M.begin(), M.end(), S.at( i ) ) - M.begin();
    }
    std::cerr << s_id;

    //  Make T -> id in M table
    std::vector< int > t_id( Q );
    for( int j = 0; j < Q; j ++ ) {
        t_id.at( j ) = std::lower_bound( M.begin(), M.end(), T.at( j ) ) - M.begin();
    }
    std::cerr << t_id;

    return( 0 );
}
