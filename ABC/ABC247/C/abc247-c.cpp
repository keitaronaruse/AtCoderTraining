/**
* @file abc247-c.cpp
* @brief ABC247 Problem C - 1 2 1 3 1 2 1
* @author Keitaro Naruse
* @date 2022-04-10
* @copyright MIT License
* @details https://atcoder.jp/contests/abc247/tasks/abc247_c
*/

// # Solution

#include <iostream>
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

int main()
{
    //  Read N = [ 1, 16 ]
    int N;
    std::cin >> N;

    //  Main
    std::vector< std::vector< int > > s( N + 1 );
    s.at( 1 ).push_back( 1 );
    for( int i = 2; i <= N; i ++ ) {
        std::copy( s.at( i - 1 ).begin(), s.at( i - 1 ).end(), std::back_inserter( s.at( i ) ) );
        s.at( i ).push_back( i );
        std::copy( s.at( i - 1 ).begin(), s.at( i - 1 ).end(), std::back_inserter( s.at( i ) ) );
    }
    std::cout << s.at( N ) << std::endl;

    //  Finalize
    return( 0 );
}
