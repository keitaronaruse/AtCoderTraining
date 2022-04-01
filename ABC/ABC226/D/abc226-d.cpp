/**
* @file abc226-d.cpp
* @brief ABC226 Problem D - Teleportation
* @author Keitaro Naruse
* @date 2022-04-01
* @copyright MIT License
* @details https://atcoder.jp/contests/abc226/tasks/abc226_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

namespace nrs {
    template < class T >
    T gcd( T a, T b )
    {
        T dividend = ( a > b )? a : b;
        T divisor  = ( a > b )? b : a;
        T residue = dividend % divisor;

        while( residue != 0 ) {
            dividend = divisor;
            divisor = residue;
            residue = dividend % divisor;
        }

        return( divisor );
    }

    template < class T >
    T lcm( T a, T b )
    {
        long long g = nrs::gcd( a, b );
        return( std::max( a, b ) / g * std::min( a, b ) );  
    }
}

int main()
{
    //  Read N = [ 2, 500 ]
    int N;
    std::cin >> N;
    //  Read xi, yi = [ 0, 10^9 ]
    std::vector< int > x( N ), y( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> x.at( i ) >> y.at( i );
    } 

    //  Main
    std::set< std::pair< int , int > > rules;
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < i; j ++ ) {
            int d_x = x.at( i ) - x.at( j );
            int d_y = y.at( i ) - y.at( j );
            if( d_x == 0 ) {
                rules.insert( std::make_pair( 0, 1 ) ); 
                rules.insert( std::make_pair( 0, -1 ) ); 
            } 
            else if( d_y == 0 ) {
                rules.insert( std::make_pair( 1, 0 ) ); 
                rules.insert( std::make_pair( -1, 0 ) ); 
            }
            else {
                int g = nrs::gcd( d_x, d_y );
                rules.insert( std::make_pair( d_x / g, d_y / g ) ); 
                rules.insert( std::make_pair( - d_x / g, - d_y / g ) ); 
            }
        }
    }
    std::cout << rules.size() << std::endl;

    //  Finalize
    return( 0 );
}
