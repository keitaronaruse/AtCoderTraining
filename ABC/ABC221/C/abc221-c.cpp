/**
* @file abc221-c.cpp
* @brief ABC221 Problem C - Select Mul
* @author Keitaro Naruse
* @date 2022-04-11
* @copyright MIT License
* @details https://atcoder.jp/contests/abc221/tasks/abc221_c
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <functional>
#include <algorithm>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) 
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int find_max_a_b( const std::string& N, unsigned int k )
{
    std::string a, b;
    std::bitset< 9 > bs( k );
    for( int i = 0; i < N.size(); i ++ ) {
        if( bs[ i ] == 0 ) {
            a.push_back( N.at( i ) );
        }
        else {
            b.push_back( N.at( i ) );
        }
    }
    std::sort( a.begin(), a.end(), std::greater< char >() );
    std::sort( b.begin(), b.end(), std::greater< char >() );

    return( std::stoi( a ) * std::stoi( b ) );
}

int main()
{
    //  Read N
    std::string N;
    std::cin >> N;

    //  Main
    size_t M = N.size();
    unsigned int min_num = 1, max_num = ( 1 << ( M - 1 ) ) - 1;
    int max_product = 0;
    for( unsigned int k = min_num; k <= max_num; k ++ ) {
        max_product = std::max( max_product, find_max_a_b( N, k ) );
    }
    std::cout << max_product << std::endl;

    //  Finalize
    return( 0 );
}
