/**
* @file abc222-d.cpp
* @brief ABC222 Problem D - Between Two Arrays
* @author Keitaro Naruse
* @date 2022-04-13
* @copyright MIT License
* @details https://atcoder.jp/contests/abc222/tasks/abc222_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>

template < class K, class V >
std::ostream& operator<<( std::ostream& os, const std::pair< K, V >& p )
{
    os << "( " <<p.first << ", " << p.second << " )";
    return( os );
}

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
    //  P
    const int P = 998244353;
    //  Read N = [ 1, 3*10^3 ]
    int N;
    std::cin >> N;
    //  Read Ai = [ 0, Bi ], Bi = [ Ai, 3*10^3 ]
    std::vector< std::string > A( N ), B( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i );
    } 
    
    //  Main
    //  dp.at( k ).at( i )
    //  the number of combinations of the value of Ci = k at the time instance i
    std::vector< std::vector< int > > dp( N + 1, std::vector< int >( N + 1, 0 ) );
    dp.at( 0 ).at( 0 ) = 1;

    //  Finalize
    return( 0 );
}
