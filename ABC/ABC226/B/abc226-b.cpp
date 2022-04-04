/**
* @file abc226-b.cpp
* @brief ABC226 Problem B - Counting Arrays
* @author Keitaro Naruse
* @date 2022-04-04
* @copyright MIT License
* @details https://atcoder.jp/contests/abc226/tasks/abc226_b
*/

// # Solution

#include <iostream>
#include <vector>
#include <set>

int main()
{
    //  Read N = [ 1, 2*10^5 ]
    int N;
    std::cin >> N;
    //  Read Li = [ 1, 2*10^5 ] and aij = [ 0, 10^9 ]
    std::vector< int > L( N ); 
    std::vector< std::vector< int > > a( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> L.at( i );
        a.at( i ) = std::vector< int >( L.at( i ) );
        for( int j = 0; j < L.at( i ); j ++ ) {
            std::cin >> a.at( i ).at( j );
        }
    }

    //  Main
    std::set< std::vector< int > > s;
    for( int i = 0; i < N; i ++ ) {
        s.insert( a.at( i ) );
    }
    std::cout << s.size() << std::endl;

    //  Finalize
    return( 0 );
}
