/**
* @file abc247-a.cpp
* @brief ABC247 Problem A
* @author Keitaro Naruse
* @date 2022-04-10
* @copyright MIT License
* @details https://atcoder.jp/contests/abc247/tasks/abc247_a
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
