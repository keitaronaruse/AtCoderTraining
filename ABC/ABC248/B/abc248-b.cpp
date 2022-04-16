/**
* @file abc248-b.cpp
* @brief ABC248 Problem X
* @author Keitaro Naruse
* @date 2022-04-16
* @copyright MIT License
* @details https://atcoder.jp/contests/abc248/tasks/abc248_b
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template< class K, class V >
std::ostream& operator<<( std::ostream& os, const std::pair< K, V >& p )
{
    os << "( " << p.first << ", " << p.second << " )";
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

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > > & vv )
{
    for( const auto& v : vv )  {
        os << v << std::endl;
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 10^3 ]
    int N = 0;
    std::cin >> N;

    //  Read Ai = [ 0, 10^9 ]
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }

    //  Read | S | = [ 1, 10^6 ]
    std::string S = "";
    std::cin >> S;

    //  Main

    //  Finalize
    return( 0 );
}
